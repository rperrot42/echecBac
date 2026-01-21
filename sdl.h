
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

typedef struct Arbre Arbre;
struct Arbre
{
	Arbre *arbreSuivant[100];
	int valeur;
};
typedef enum nomPiece nomPiece;
enum nomPiece
{
	Roi, Dame, Pion, Fou, Cavalier,Tour,Vide
};
typedef struct Joueur Joueur;

typedef struct Coordonnee Coordonnee;
struct Coordonnee
{
	int x;
	int y;
};
typedef struct Piece Piece;
struct Piece
{
	nomPiece nom;
	int valeur;
	int couleur;
	int haut;
	SDL_Texture* texture;
	Coordonnee position;
	int en_vie;
	int bot;
	

};
struct Joueur
{
	int haut;
	int couleur;
	int rockGauche;
	int rockDroit;
	Piece pieceJoueur[16];
	int nbPiece;
	Coordonnee positionRoi;
	int bot;
};

typedef struct PriseEnPassant  PriseEnPassant;
struct PriseEnPassant
{
	Coordonnee coordPion;
	int possible;
	
};
typedef struct echec echec;
struct echec
{
	Piece echiquier[8][8];
	Joueur joueur1;
	Joueur joueur2;
	Coordonnee positonEchiquier;
	int taille;
	PriseEnPassant pionPasse;
};
typedef struct  rectangle rectangle;
struct rectangle
{
	int x;
	int y;
	int w;
	int h;
};
int dessiner_echiquier(SDL_Renderer* renderer, int x, int y, int taille);
int initialiser_echiquier(SDL_Renderer* renderer, echec* jeuechec);
int initialiser_image(SDL_Texture **texture, char nomImage[40], SDL_Renderer* renderer);
int initialiser_pieces(Coordonnee poition, Joueur* joueur, Piece* piece, nomPiece nom_piece, SDL_Texture* texture,int* compteur);
int afficher_pieces(Piece pieces, SDL_Renderer* renderer, echec jeuechec);
Piece case_position_pieces(int nbPixelX, int nbPixelY,echec jeuEchec);
void case_possible_pion(Piece pion, echec jeuEchec, Coordonnee* coordonneePossible);
void initialiserListeCoordonee(Coordonnee* coordonneePossible, int taille);
void trouveRectangleCoordonne(SDL_Rect* rectangle, Coordonnee coordonne, echec jeuEchec);
void afficher_coordonne(SDL_Renderer* renderer, SDL_Texture* texture, Coordonnee* coordonnes, echec jeuechec, int taille);
int pieceEstCoordonnePossible(Piece pieceSouris, Coordonnee* coordoneePosible, int taille);
void repeindreListeCase(echec jeuEchec, Coordonnee* coordonneAPeindre, int taille, SDL_Renderer* renderer);
void deplacerPiece(SDL_Renderer* renderer, echec* jeuEchec, Piece piecesADeplacer, Coordonnee coordPiece, int deplacerPieceJoueur);
void case_possible_fou(Piece fou, echec jeuEchec, Coordonnee* coordonneePossible);
int case_possible_tour(Piece tour, echec jeuEchec, Coordonnee* coordonneePossible);
void case_possible_cavalier(Piece cavalier, echec jeuEchec, Coordonnee* coordonneePossible);
void case_possible_roi(Piece roi, echec jeuEchec, Coordonnee* coordonneePossible);
void suprimerPiece(Joueur* joueur, Piece pieceASupprimer);
void modifierEmplacementPieceJoueur(Joueur* joueur, Piece piecesADeplacer, echec* jeuEchec, Coordonnee coordaDEplacer, SDL_Renderer* renderer);
void afficherToutesLesPieces(Joueur joueur);
void calculerTouteCoordJoueur(Joueur joueur, echec jeuEchec, Coordonnee* coordonnePossible);
void ConcatenerListeCoordonnee(Coordonnee* coordToutesPieces, Coordonnee* CoordUnePiece, int* i);
void afficherTouteCoordonee(Coordonnee* coordonnne);
void verifierLesEchecs(Coordonnee* coordonnePossible, echec jeuEchec, Piece pieceADeplacer);
int RoiEstCoordonne(Joueur joueur, Coordonnee* coordonneePossible);
void case_possible(Piece piece, echec jeuEchec, Coordonnee* coordonneePossible, int verifierEchec);
void copiePiece(Piece* pieceACopier, Piece* piece);
int verifieCasePossibleJoueur(echec jeuEchec, Joueur joueur);
int echecMatPat(echec jeuEchec, Joueur joueur);
int evaluerUnePosition(echec jeuEchec, int couleur);
int evaluerPositionJoueur(Joueur joueur);
int minMax(echec jeuEchec, int couleurJouant, int CoupAnticipe, Piece* pieceADeplacer, Coordonnee* coordonnePossible, int couleurDeBase);
