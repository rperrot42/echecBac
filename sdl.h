
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
	Roi = 0, Dame = 1, Pion = 2, Fou = 3, Cavalier = 4,Tour = 5,Vide = 6
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
	SDL_Texture *rondNoir;
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


typedef struct s_piece_echec {
	SDL_Texture* imageRoiNoir;
	SDL_Texture* imageRoiBlanc;
	SDL_Texture* imageDameNoire;
	SDL_Texture* imageDameBlanche;
	SDL_Texture* imageTourBlanche;
	SDL_Texture* imageTourNoire;
	SDL_Texture* imageFouBlanc;
	SDL_Texture* imageFouNoir;
	SDL_Texture* imageCavalierBlanc;
	SDL_Texture* imageCavalierNoir;
	SDL_Texture* imagePionBlanc;
	SDL_Texture* imagePionNoir;
} t_piece_echec;

int init_piece_echec(t_piece_echec *piece_echec, SDL_Renderer* renderer);
int dessiner_echiquier(SDL_Renderer* renderer, int x, int y, int taille);
int initialiser_echiquier(SDL_Renderer* renderer, echec* jeuechec, t_piece_echec *piece_echec);
int initialiser_image(SDL_Texture **texture, char nomImage[40], SDL_Renderer* renderer);
int initialiser_pieces(Coordonnee poition, Joueur* joueur, Piece* piece, nomPiece nom_piece, SDL_Texture* texture,int* compteur);
void afficher_pieces(Piece pieces, SDL_Renderer* renderer, echec jeuechec);
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
void printEchiquier(SDL_Renderer * renderer, echec *jeuechec, Coordonnee* coordonnes);
