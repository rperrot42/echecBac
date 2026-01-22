#include "sdl.h"

int dessiner_echiquier(SDL_Renderer *renderer,int x, int y, int taille)
{
    SDL_Color color2 = { 0,86,27,255 };
    SDL_Color color1 = { 149,165,149,255 };
    int n = taille / 8;
    int i;
    int j;
    
    for (j = 0; j < 8; j++)
    {
        for (i = 0; i < 8; i++)
        {
            if ((i + j) % 2 == 0)
            {
                if (SDL_SetRenderDrawColor(renderer, color1.r, color1.g, color1.b, color1.a != 0))
					return -1;

            }
            else if (SDL_SetRenderDrawColor(renderer, color2.r, color2.g, color2.b, color2.a != 0))
				return -1;
            SDL_Rect rectangle = { x+(taille*j/8),y+(taille*i/8),taille/8,taille/8 };
            if (SDL_RenderFillRect(renderer, &rectangle) != 0)
				return -1;
        }
    }
    return 0;
}

int init_piece_echec(t_piece_echec *piece_echec, SDL_Renderer* renderer) {
    int somme_test_surface = 0;
    piece_echec->imageRoiNoir = NULL;
    piece_echec->imageRoiBlanc = NULL;
    piece_echec->imageDameNoire = NULL;
    piece_echec->imageDameBlanche = NULL;
    piece_echec->imageTourBlanche = NULL;
    piece_echec->imageTourNoire = NULL;
    piece_echec->imageFouBlanc = NULL;
    piece_echec->imageFouNoir = NULL;
    piece_echec->imageCavalierBlanc = NULL;
    piece_echec->imageCavalierNoir = NULL;
    piece_echec->imagePionBlanc = NULL;
    piece_echec->imagePionNoir = NULL;
    somme_test_surface += initialiser_image(&piece_echec->imageRoiNoir, "image pieces d'echec/roi noir.bmp",renderer);
    somme_test_surface += initialiser_image(&piece_echec->imageRoiBlanc, "image pieces d'echec/roi blanc.bmp", renderer);
    somme_test_surface += initialiser_image(&piece_echec->imageDameNoire, "image pieces d'echec/dame noir.bmp", renderer);
    somme_test_surface += initialiser_image(&piece_echec->imageDameBlanche, "image pieces d'echec/dame Blanche.bmp", renderer);
    somme_test_surface += initialiser_image(&piece_echec->imageTourBlanche, "image pieces d'echec/tour blanche.bmp", renderer);
    somme_test_surface += initialiser_image(&piece_echec->imageTourNoire, "image pieces d'echec/tour noir.bmp", renderer);
    somme_test_surface += initialiser_image(&piece_echec->imageFouBlanc, "image pieces d'echec/fou blanc.bmp", renderer);
    somme_test_surface += initialiser_image(&piece_echec->imageFouNoir, "image pieces d'echec/fou noir.bmp", renderer);
    somme_test_surface += initialiser_image(&piece_echec->imageCavalierBlanc, "image pieces d'echec/cavalier blanc.bmp", renderer);
    somme_test_surface += initialiser_image(&piece_echec->imageCavalierNoir, "image pieces d'echec/cavalier noir.bmp", renderer);
    somme_test_surface += initialiser_image(&piece_echec->imagePionBlanc, "image pieces d'echec/pion blanc.bmp",renderer);
    somme_test_surface += initialiser_image(&piece_echec->imagePionNoir, "image pieces d'echec/pion noir.bmp", renderer);
    return somme_test_surface;

};
int initialiser_echiquier(SDL_Renderer* renderer, echec* jeuechec, t_piece_echec *piece_echec)
{
    dessiner_echiquier(renderer,jeuechec->positonEchiquier.x, jeuechec->positonEchiquier.x, jeuechec->taille);
    int i;
    int j;
    int compteurBlanc = 0;
    int compteurNoir = 0;
    int compteur = 0;
    jeuechec->joueur1.rockDroit = 1;
    jeuechec->joueur1.rockGauche = 1;
    jeuechec->joueur2.rockDroit = 1;
    jeuechec->joueur2.rockGauche = 1;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {

            Coordonnee position = { j,i };
            if (i == 6)
            {

                Piece pion;
                if (jeuechec->joueur1.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Pion, piece_echec->imagePionNoir,&compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Pion, piece_echec->imagePionBlanc, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else if (i == 1)
            {

                Piece pion;
                if (jeuechec->joueur2.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Pion, piece_echec->imagePionNoir, &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Pion, piece_echec->imagePionBlanc, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else if (i == 7 && j== 4)
            {

                Piece pion;
                if (jeuechec->joueur1.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Dame, piece_echec->imageDameNoire, &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Roi, piece_echec->imageRoiBlanc, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else if (i == 0 && j == 4)
            {
                Piece pion;
                if (jeuechec->joueur2.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Roi, piece_echec->imageRoiNoir, &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Dame, piece_echec->imageDameBlanche, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else if (i == 7 && j == 3)
            {

                Piece pion;
                if(jeuechec->joueur1.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Roi, piece_echec->imageRoiNoir, &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Dame, piece_echec->imageDameBlanche, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else if (i == 0 && j == 3)
            {

                Piece pion;
                if (jeuechec->joueur2.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Dame, piece_echec->imageDameNoire, &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Roi, piece_echec->imageRoiBlanc, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;

            }
            else if (i == 7 && (j == 0 || j == 7))
            {
                Piece pion;
                if (jeuechec->joueur1.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Tour, piece_echec->imageTourNoire, &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Tour, piece_echec->imageTourBlanche, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else if (i == 0 && (j == 0 || j==7))
            {

                Piece pion;
                if (jeuechec->joueur2.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Tour, piece_echec->imageTourNoire, &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Tour, piece_echec->imageTourBlanche, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else if (i == 7 && (j == 1 || j == 6))
            {

                Piece pion;
                if (jeuechec->joueur1.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Cavalier, piece_echec->imageCavalierNoir, &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Cavalier, piece_echec->imageCavalierBlanc, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else if (i == 0 && (j == 1 || j == 6))
            {

                Piece pion;
                if (jeuechec->joueur2.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Cavalier, piece_echec->imageCavalierNoir, &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Cavalier, piece_echec->imageCavalierBlanc, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else if (i == 7 && (j == 2 || j == 5))
            {

                Piece pion;
                if (jeuechec->joueur1.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Fou, piece_echec->imageFouNoir, &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur1, &pion, Fou, piece_echec->imageFouBlanc, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else if (i == 0 && (j == 2 || j == 5))
            {

                Piece pion;
                if (jeuechec->joueur2.couleur == 1)
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Fou, piece_echec->imageFouNoir , &compteurNoir);
                else
                    initialiser_pieces(position, &jeuechec->joueur2, &pion, Fou, piece_echec->imageFouBlanc, &compteurBlanc);
                jeuechec->echiquier[i][j] = pion;
            }
            else {
                Piece pion;
                pion.position.x = j;
                pion.position.y = i;
                pion.en_vie = 1;
                pion.texture = NULL;
                jeuechec->echiquier[i][j] = pion;
            }
            afficher_pieces(jeuechec->echiquier[i][j], renderer, *jeuechec);
        }
    }
    return 0;
}
int initialiser_image(SDL_Texture **texture, char nomImage[40], SDL_Renderer* renderer)
{
    SDL_Surface* image = SDL_LoadBMP(nomImage);
    if (image == NULL)
    {
        printf("erreur de chargement image");
        return -1;
    }
    *texture = SDL_CreateTextureFromSurface(renderer, image);
    if (*texture == NULL)
    {
        printf("erreur dans le chargement de la texture");
        return -1;
    }
    return 0;
}
int initialiser_pieces(Coordonnee coordonneePosition, Joueur *joueur, Piece* piece, nomPiece nom_piece,SDL_Texture*texture,int *compteur)
{

    piece->en_vie = 0;
    piece->nom = nom_piece;
    piece->couleur = joueur->couleur;
    piece->haut = joueur->haut;
    piece->texture = texture;
    piece->position = coordonneePosition;
    piece->bot = joueur->bot;
    joueur->pieceJoueur[*compteur] = *piece;
    if (nom_piece == Roi)joueur->positionRoi = coordonneePosition;
    *compteur=*compteur+1;
    joueur->nbPiece = *compteur;
}

void afficher_pieces(Piece pieces, SDL_Renderer* renderer, echec jeuechec)
{
  
    if (pieces.en_vie == 0)
    {
        int j = pieces.position.x;
        int i = pieces.position.y;
        SDL_Rect rect;
        rect.x = jeuechec.positonEchiquier.x + jeuechec.taille / 8 * j;
        rect.y = jeuechec.positonEchiquier.y + jeuechec.taille / 8 * i;
        rect.h = jeuechec.taille / 8;
        rect.w = jeuechec.taille / 8;
        SDL_RenderCopy(renderer, pieces.texture, NULL, &rect);
    }
}
Piece case_position_pieces(int nbPixelX, int nbPixelY,echec jeuEchec)
{
    if (nbPixelX > jeuEchec.taille + jeuEchec.positonEchiquier.x || nbPixelX < jeuEchec.positonEchiquier.x || nbPixelY>jeuEchec.taille + jeuEchec.positonEchiquier.y || nbPixelY < jeuEchec.positonEchiquier.y)
    {
        Piece HorsEchiquier;
        HorsEchiquier.en_vie = 1;
        return HorsEchiquier;
    }
    nbPixelX = (nbPixelX - jeuEchec.positonEchiquier.x) / (jeuEchec.taille / 8);
    nbPixelY = (nbPixelY - jeuEchec.positonEchiquier.x) / (jeuEchec.taille / 8);
    
    Piece piece = jeuEchec.echiquier[nbPixelY][nbPixelX];

    return piece;
}
void case_possible_pion(Piece pion,echec jeuEchec,Coordonnee *coordonneePossible)
{
    int x = pion.position.x;
    
    int y = pion.position.y;

    int ordAAjouter = -1;
    int coordDepart = 6;

    if (pion.haut == 0)
    {

        ordAAjouter = 1;
        coordDepart = 1;
    }
    if (jeuEchec.echiquier[y + ordAAjouter][x].en_vie == 1 && 7>= y + ordAAjouter>=0)
    {
        coordonneePossible[0].x = x;
        coordonneePossible[0].y = ordAAjouter +y;
        if (jeuEchec.echiquier[y + 2*ordAAjouter][x].en_vie == 1 && y==coordDepart)
        {
            coordonneePossible[1].x = x;
            coordonneePossible[1].y = y+2*ordAAjouter;
        }

    }
    if (jeuEchec.echiquier[y + ordAAjouter][x + 1].en_vie == 0 && jeuEchec.echiquier[y + ordAAjouter][x + 1].couleur!=pion.couleur && 7 >= y + ordAAjouter >= 0)
    {
        if (x + 1 <= 7) {
            coordonneePossible[2].x = x + 1;
            coordonneePossible[2].y = y + ordAAjouter;
        }
        
    }
    if (jeuEchec.echiquier[y + ordAAjouter][x - 1].en_vie == 0 && jeuEchec.echiquier[y + ordAAjouter][x - 1].couleur != pion.couleur && 7 >= y + ordAAjouter >= 0)
    {
        if (x - 1 >= 0) {
            coordonneePossible[3].x = x - 1;
            coordonneePossible[3].y = y + ordAAjouter;
        }
    }
    if (jeuEchec.pionPasse.possible == 0)
    {
        if (jeuEchec.echiquier[y][x - 1].position.x == jeuEchec.pionPasse.coordPion.x && jeuEchec.echiquier[y][x - 1].position.y == jeuEchec.pionPasse.coordPion.y)
            coordonneePossible[4].x = x - 1;
            coordonneePossible[4].y = y + ordAAjouter;
        if (jeuEchec.echiquier[y][x + 1].position.x == jeuEchec.pionPasse.coordPion.x && jeuEchec.echiquier[y][x + 1].position.y == jeuEchec.pionPasse.coordPion.y)
        {


            coordonneePossible[5].x = x + 1;
            coordonneePossible[5].y = y + ordAAjouter;
        }
    }
    
}
void initialiserListeCoordonee(Coordonnee* coordonneePossible,int taille)
{
    int i = 0;
    for (i = 0; i < taille; i++)
    {
        coordonneePossible[i].x = -1;
        coordonneePossible[i].y = -1;
    }
}
void trouveRectangleCoordonne(SDL_Rect* rectangle, Coordonnee coordonnee, echec jeuEchec)
{
    rectangle->h = jeuEchec.taille / 8;
    rectangle->w = jeuEchec.taille / 8;
    rectangle->x = jeuEchec.positonEchiquier.x + jeuEchec.taille / 8 * coordonnee.x;
    rectangle->y = jeuEchec.positonEchiquier.y + jeuEchec.taille / 8 * coordonnee.y;
}

void printEchiquier(SDL_Renderer * renderer, echec *jeuechec, Coordonnee* coordonnes) {
    dessiner_echiquier(renderer, jeuechec->positonEchiquier.x, jeuechec->positonEchiquier.x, jeuechec->taille);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            afficher_pieces(jeuechec->echiquier[i][j], renderer, *jeuechec);
        }
    }

    int i = 0;
    for (i = 0; i < 28; i++)
    {
        if (coordonnes[i].x != -1)
        {
            SDL_Rect rect;
            trouveRectangleCoordonne(&rect, coordonnes[i], *jeuechec);

            SDL_RenderCopy(renderer, jeuechec->rondNoir, NULL, &rect);

        }
    }

    SDL_RenderPresent(renderer);
}

void afficher_coordonne(SDL_Renderer* renderer, SDL_Texture* texture , Coordonnee* coordonnes,echec jeuechec, int taille)
{

    int i = 0;
    for (i = 0; i < taille; i++)
    {
        if (coordonnes[i].x != -1)
        {
            SDL_Rect rect;
            trouveRectangleCoordonne(&rect, coordonnes[i], jeuechec);
  
            SDL_RenderCopy(renderer, texture, NULL, &rect);
            
        }
    }
    SDL_RenderPresent(renderer);
}
int pieceEstCoordonnePossible(Piece pieceSouris, Coordonnee *coordoneePosible, int taille)
{
    int i = 0;
    for (i = 0; i < taille; i++)
    {
        if (coordoneePosible[i].x == pieceSouris.position.x && coordoneePosible[i].y == pieceSouris.position.y) return 0;
    }
    return 1;
}
void repeindreListeCase(echec jeuEchec, Coordonnee* coordonneAPeindre, int taille,SDL_Renderer*  renderer) {
    SDL_Color color2 = { 0,86,27,255 };
    SDL_Color color1 = { 149,165,149,255 };
    int indice = 0;
    int x = jeuEchec.positonEchiquier.x;
    int y = jeuEchec.positonEchiquier.y;
    int tailleEchquier = jeuEchec.taille;

    for (indice=0; indice<taille;indice++)
        if (coordonneAPeindre[indice].x != -1)
        {
            int i = coordonneAPeindre[indice].y;
            int j = coordonneAPeindre[indice].x;

            if ((i + j) % 2 == 0)
            {
                SDL_SetRenderDrawColor(renderer, color1.r, color1.g, color1.b, color1.a != 0);

            }
            else
            {
                SDL_SetRenderDrawColor(renderer, color2.r, color2.g, color2.b, color2.a != 0);
            }

            SDL_Rect rectangle = { x + (tailleEchquier * j / 8),y + (tailleEchquier * i / 8),tailleEchquier / 8,tailleEchquier / 8 };
            SDL_RenderFillRect(renderer, &rectangle);

            Piece  piece = jeuEchec.echiquier[i][j];


        }
}
void deplacerPiece(SDL_Renderer* renderer, echec* jeuEchec, Piece piecesADeplacer, Coordonnee coordPiece, int deplacerPieceJoueur)
{
    int nbCoup=0;
    Piece pion;

    if (piecesADeplacer.nom == Tour)
    {
        int ordTour = piecesADeplacer.position.y;
        int absTour = piecesADeplacer.position.x;
        int ordOrigine = 7;
        if (piecesADeplacer.haut == 0) ordOrigine = 0;
        if (ordTour == ordOrigine && absTour == 0 && deplacerPieceJoueur == 1)
        {
            if (piecesADeplacer.couleur == jeuEchec->joueur1.couleur) jeuEchec->joueur1.rockGauche = 0;
            else jeuEchec->joueur2.rockGauche = 0;
        }
        if (ordTour == ordOrigine && absTour == 7 && deplacerPieceJoueur == 1)
        {
            if (piecesADeplacer.couleur == jeuEchec->joueur1.couleur) jeuEchec->joueur1.rockDroit = 0;
            else jeuEchec->joueur2.rockDroit = 0;
        }
    }
    int rappelerFonction = 0;
    if (piecesADeplacer.nom == Roi )
    {
        if (deplacerPieceJoueur == 1)
        {
            if (piecesADeplacer.couleur == jeuEchec->joueur1.couleur) { jeuEchec->joueur1.rockDroit = 0; jeuEchec->joueur1.rockGauche = 0; }
            else { jeuEchec->joueur2.rockGauche = 0; jeuEchec->joueur2.rockDroit = 0; }
        }
        if ((coordPiece.x - piecesADeplacer.position.x) > 1 || (coordPiece.x - piecesADeplacer.position.x) < -1)
        {
            if (coordPiece.x == 0 && piecesADeplacer.position.x == 3) coordPiece.x = 1;
            else if (coordPiece.x == 0 && piecesADeplacer.position.x == 4) coordPiece.x = 2;
            else if (coordPiece.x == 7 && piecesADeplacer.position.x == 4) coordPiece.x = 6;
            else coordPiece.x = 5;
            rappelerFonction = 1;
        }
    }
    if (jeuEchec->joueur1.couleur == piecesADeplacer.couleur) modifierEmplacementPieceJoueur(&jeuEchec->joueur1, piecesADeplacer, jeuEchec, coordPiece,renderer);
    else modifierEmplacementPieceJoueur(&jeuEchec->joueur2, piecesADeplacer, jeuEchec, coordPiece,renderer);
    if (piecesADeplacer.nom == Pion && coordPiece.x == piecesADeplacer.position.x && (coordPiece.y == piecesADeplacer.position.y + 2 || coordPiece.y == piecesADeplacer.position.y - 2) && deplacerPieceJoueur == 1)
    {
        jeuEchec->pionPasse.coordPion = coordPiece;
        jeuEchec->pionPasse.possible = 0;

    }
    if (piecesADeplacer.nom == Pion && coordPiece.x != piecesADeplacer.position.x && jeuEchec->echiquier[coordPiece.y][coordPiece.x].en_vie == 1)
    {
        int ordAAjouter = -1;
        if (piecesADeplacer.haut == 0)
        {
            ordAAjouter = 1;
        }
        Piece PieceVide;
        PieceVide.en_vie = 1;
        PieceVide.position.x = coordPiece.x;
        PieceVide.position.y = coordPiece.y - ordAAjouter;

        if(jeuEchec->echiquier[coordPiece.y - ordAAjouter][coordPiece.x].couleur==jeuEchec->joueur1.couleur)
        {
            
            suprimerPiece(&jeuEchec->joueur1, jeuEchec->echiquier[coordPiece.y - ordAAjouter][coordPiece.x]);
        }
        else suprimerPiece(&jeuEchec->joueur2, jeuEchec->echiquier[coordPiece.y - ordAAjouter][coordPiece.x]);
        jeuEchec->echiquier[coordPiece.y - ordAAjouter][coordPiece.x] = PieceVide;
    }
    pion.en_vie = 1;
    int coordPieceX = coordPiece.x;
    int coordPieceY = coordPiece.y;
    int PionX = piecesADeplacer.position.x;
    int PionY = piecesADeplacer.position.y;
    pion.position.x = PionX;
    pion.position.y = PionY;
    jeuEchec->echiquier[pion.position.y][pion.position.x] = pion;
    Piece piece = piecesADeplacer;

    if (piecesADeplacer.nom == Pion && (coordPiece.y == 0 || coordPiece.y == 7))
    {
        piece.nom = Dame;
        if (renderer != NULL )
        {
            if (piecesADeplacer.couleur == 0)
            {
                SDL_Surface* imageDameBlanche = NULL;
                initialiser_image(&imageDameBlanche, "image pieces d'echec/dame Blanche.bmp", renderer);
                piece.texture = imageDameBlanche;
            }
            else
            {
                SDL_Surface* imageDameNoire = NULL;
                initialiser_image(&imageDameNoire, "image pieces d'echec/dame noir.bmp", renderer);
                piece.texture = imageDameNoire;
            }
        }
    }

    piece.position.x = coordPieceX;
    piece.position.y = coordPieceY;
    jeuEchec->echiquier[coordPieceY][coordPieceX] = piece;
    if (rappelerFonction == 1)
    {

        if (coordPieceX == 1)
        {
            Coordonnee coordAdeplacer = { 2,PionY };
            deplacerPiece(renderer, jeuEchec, jeuEchec->echiquier[PionY][0], coordAdeplacer, deplacerPieceJoueur);
        }
        else if (coordPieceX == 5)
        {
            Coordonnee coordAdeplacer = { 4,PionY };
            deplacerPiece(renderer, jeuEchec, jeuEchec->echiquier[PionY][7], coordAdeplacer, deplacerPieceJoueur);
        }
        else if (coordPieceX == 2)
        {
            Coordonnee coordAdeplacer = { 3,PionY };
            deplacerPiece(renderer, jeuEchec, jeuEchec->echiquier[PionY][0], coordAdeplacer, deplacerPieceJoueur);
        }
        else {
            Coordonnee coordAdeplacer = { 5,PionY };
            deplacerPiece(renderer, jeuEchec, jeuEchec->echiquier[PionY][7], coordAdeplacer, deplacerPieceJoueur);
        }
    }

}
void case_possible(Piece piece, echec jeuEchec, Coordonnee* coordonneePossible,int verifierEchec)
{

    if (piece.nom==Pion)
    {
        case_possible_pion(piece, jeuEchec, &coordonneePossible[0]);
    }
    else if (piece.nom == Fou)
    {
        int nbCoup = 0;
        case_possible_fou(piece, jeuEchec, &coordonneePossible[0]);
    }
    else if (piece.nom == Tour)
    {
        case_possible_tour(piece, jeuEchec, &coordonneePossible[0]);
    }
    else if (piece.nom == Dame)
    {
        case_possible_tour(piece, jeuEchec, &coordonneePossible[0]);
        case_possible_fou(piece, jeuEchec, &coordonneePossible[0]);
    }
    else if (piece.nom == Cavalier)
    {
        case_possible_cavalier(piece, jeuEchec, &coordonneePossible[0]);

    }
    else if (piece.nom == Roi)
    {
        case_possible_roi(piece, jeuEchec, &coordonneePossible[0]);
    }
    if (verifierEchec == 1)
        verifierLesEchecs(&coordonneePossible[0], jeuEchec, piece);
}
void case_possible_fou(Piece fou, echec jeuEchec, Coordonnee* coordonneePossible)
{
    int x = fou.position.x;
    int y = fou.position.y;
    int i = 0;
    int nbCoupPossible = 14;
    int xDeplacer;
    int yDeplacer;
    for (i = 0; i < 4; i++)
    {
        xDeplacer=0;
        yDeplacer=0;
        int j = 1;
        int lancerBoucle = 0;
        if (i / 2 == 0) xDeplacer = j;
        else xDeplacer = -(j);

        if (i % 2 == 0) yDeplacer = j;
        else yDeplacer = -(j);
        while(jeuEchec.echiquier[y+yDeplacer][x+xDeplacer].en_vie==1 && (x+xDeplacer)<=7 && (y + yDeplacer )<=7 && (y + yDeplacer)>=0 && (x+ xDeplacer) >= 0)
        {
           
            
            coordonneePossible[nbCoupPossible].x = x + xDeplacer;
            coordonneePossible[nbCoupPossible].y = y + yDeplacer;
            if (i / 2 == 0) xDeplacer = j;
            else xDeplacer = -(j);
            if (i % 2 == 0) yDeplacer = j;
            else yDeplacer = -(j);
            nbCoupPossible++;
            j += 1;
            
        }

        if (jeuEchec.echiquier[y + yDeplacer][x + xDeplacer].en_vie ==0 && jeuEchec.echiquier[y + yDeplacer][x + xDeplacer].couleur != fou.couleur && (x + xDeplacer) <= 7 && (y + yDeplacer) <= 7 && (y + yDeplacer) >= 0 && (x + xDeplacer) >= 0)
        {
            coordonneePossible[nbCoupPossible].x = x + xDeplacer;
            coordonneePossible[nbCoupPossible].y = y + yDeplacer;
            nbCoupPossible++;
        }


    }
}
int case_possible_tour(Piece tour, echec jeuEchec, Coordonnee* coordonneePossible)
{
    int x = tour.position.x;
    int y = tour.position.y;
    int i = 0;

    int xDeplacer;
    int yDeplacer;
    int nb_coup_possible = 0;
    for (i = 0; i < 4; i++)
    {
        xDeplacer = 0;
        yDeplacer = 0;
        int j = 1;
        int lancerBoucle = 0;
        if (i == 0) xDeplacer = j;
        else if (i == 1)xDeplacer = -(j);
        else if (i % 2 == 0) yDeplacer = j;
        else yDeplacer = -(j);
        while (jeuEchec.echiquier[y + yDeplacer][x + xDeplacer].en_vie == 1 && (x + xDeplacer) <= 7 && (y + yDeplacer) <= 7 && (y + yDeplacer) >= 0 && (x + xDeplacer) >= 0)
        {


            coordonneePossible[nb_coup_possible].x = x + xDeplacer;
            coordonneePossible[nb_coup_possible].y = y + yDeplacer;
            nb_coup_possible++;
            if (i == 0) xDeplacer = j;
            else if (i == 1)xDeplacer = -(j);
            else if (i % 2 == 0) yDeplacer = j;
            else yDeplacer = -(j);

            j += 1;

        }

        if (jeuEchec.echiquier[y + yDeplacer][x + xDeplacer].en_vie == 0 && jeuEchec.echiquier[y + yDeplacer][x + xDeplacer].couleur != tour.couleur && (x + xDeplacer) <= 7 && (y + yDeplacer) <= 7 && (y + yDeplacer) >= 0 && (x + xDeplacer) >= 0)
        {
            coordonneePossible[nb_coup_possible].x = x + xDeplacer;
            coordonneePossible[nb_coup_possible].y = y + yDeplacer;
            nb_coup_possible++;
        }
    }
    return nb_coup_possible;
}
void case_possible_cavalier(Piece cavalier, echec jeuEchec, Coordonnee* coordonneePossible)
{

    int i = 0;
    int x = cavalier.position.x;
    int y = cavalier.position.y;
    int nbCoups=0;
    for (i = 0; i < 4; i++)
    {
        int xDeplacer = 0;
        int yDeplacer = 0;
        if (i == 0) xDeplacer = 2;
        else if (i == 1) xDeplacer = -2;
        else if (i == 2)yDeplacer = 2;
        else yDeplacer = -2;
        int j;
        
        for (j = -1; j < 2; j += 2)
        {
            if (xDeplacer == 0 || xDeplacer==-1)  xDeplacer= j;
            else yDeplacer = j;
            if (xDeplacer + x >= 0 && xDeplacer + x <= 7 && yDeplacer + y >= 0 && yDeplacer + y <= 7 && jeuEchec.echiquier[yDeplacer + y][xDeplacer + x].couleur != cavalier.couleur)
            {
              
                coordonneePossible[nbCoups].x = xDeplacer + x;
                coordonneePossible[nbCoups].y = yDeplacer + y;
                nbCoups++;
               
            }

           
     
        }
    }    
}
void case_possible_roi(Piece roi, echec jeuEchec, Coordonnee* coordonneePossible)
{
    int i = 0;
    int x = roi.position.x;
    int y = roi.position.y;
    int nbCoups = 0;
    Joueur joueurRoi= jeuEchec.joueur2;
    if (roi.couleur == jeuEchec.joueur1.couleur)joueurRoi = jeuEchec.joueur1;
    if (x == 4 && joueurRoi.rockGauche == 1 && jeuEchec.echiquier[y][3].en_vie == 1 && jeuEchec.echiquier[y][2].en_vie == 1 && jeuEchec.echiquier[y][1].en_vie == 1)
    {
        coordonneePossible[8].x = 0;
        coordonneePossible[8].y = y;
    }

    if ( x==4  && joueurRoi.rockDroit == 1 && jeuEchec.echiquier[y][5].en_vie == 1 && jeuEchec.echiquier[y][6].en_vie == 1 )
    {
        
        coordonneePossible[9].x = 7;
        coordonneePossible[9].y = y;
        
    }
    if (x == 3 && joueurRoi.rockDroit == 1 && jeuEchec.echiquier[y][4].en_vie == 1 && jeuEchec.echiquier[y][5].en_vie == 1 && jeuEchec.echiquier[y][6].en_vie == 1)
    {
        coordonneePossible[8].x = 7;
        coordonneePossible[8].y = y;
    }

    if (x == 3 && joueurRoi.rockGauche == 1 && jeuEchec.echiquier[y][1].en_vie == 1 && jeuEchec.echiquier[y][2].en_vie == 1)
    {

        coordonneePossible[9].x = 0;
        coordonneePossible[9].y = y;

    }


    for (i = 0; i < 8; i++)
    {
        int xDeplacer = 0;
        int yDeplacer = 0;
        switch (i)
        {
        case 0:
            xDeplacer = 1;
            break;
        case 1:
            xDeplacer = -1;
            break;
        case 2:
            yDeplacer = 1;
            break;
        case 3:
            yDeplacer = -1;
            break;
        case 4:
            xDeplacer = 1;
            yDeplacer = -1;
            break;
        case 5:
            xDeplacer = 1;
            yDeplacer = 1;
            break;
        case 6:
            xDeplacer = -1;
            yDeplacer = 1;
            break;
        case 7:
            xDeplacer = -1;
            yDeplacer = -1;
            break;
        }
    
        if (xDeplacer + x >= 0 && xDeplacer + x <= 7 && yDeplacer + y >= 0 && yDeplacer + y <= 7 && jeuEchec.echiquier[yDeplacer + y][xDeplacer + x].couleur != roi.couleur)
        {
            coordonneePossible[nbCoups].x = xDeplacer + x;
            coordonneePossible[nbCoups].y = yDeplacer + y;
            nbCoups++;
        }   
    }
}
void suprimerPiece(Joueur* joueur, Piece pieceASupprimer)
{
    
    int i = 0;
    int supprimer = 0;

    for (i = 0; i < joueur->nbPiece; i++)
    {
        Piece pieceActuelle = joueur->pieceJoueur[i];
        if (pieceActuelle.position.x == pieceASupprimer.position.x && pieceActuelle.position.y == pieceASupprimer.position.y && pieceActuelle.nom == pieceASupprimer.nom && pieceASupprimer.couleur == pieceActuelle.couleur)
        {
            joueur->nbPiece = joueur->nbPiece - 1;
           
            supprimer = 1;
        }
       

        
        if (supprimer == 1)
        {
            joueur->pieceJoueur[i] = joueur->pieceJoueur[i + 1];
        }
    }
}
void modifierEmplacementPieceJoueur(Joueur* joueur, Piece piecesADeplacer, echec* jeuEchec, Coordonnee coordaDEplacer,SDL_Renderer* renderer)
{
    int i;

    for (i = 0; i < joueur->nbPiece; i++)
    {

        Piece pieceActuelle = joueur->pieceJoueur[i];
        if (pieceActuelle.position.x == piecesADeplacer.position.x && pieceActuelle.position.y == piecesADeplacer.position.y && pieceActuelle.nom == piecesADeplacer.nom && piecesADeplacer.couleur == pieceActuelle.couleur)
        {

            joueur->pieceJoueur[i].position = coordaDEplacer;
            if (pieceActuelle.nom == Roi)joueur->positionRoi = coordaDEplacer;
          
            if (pieceActuelle.nom == Pion && (coordaDEplacer.y == 0 || coordaDEplacer.y == 7))
            {
         
                joueur->pieceJoueur[i].nom = Dame;
                if (renderer != NULL)
                {
                    if (pieceActuelle.couleur == 0)
                    {
                        SDL_Surface* imageDameBlanche = NULL;
                        initialiser_image(&imageDameBlanche, "image pieces d'echec/dame Blanche.bmp", renderer);
                        joueur->pieceJoueur[i].texture = imageDameBlanche;
                    }
                    else
                    {
                        SDL_Surface* imageDameNoire = NULL;
                        initialiser_image(&imageDameNoire, "image pieces d'echec/dame noir.bmp", renderer);
                        joueur->pieceJoueur[i].texture = imageDameNoire;
                    }
                }
                    
                
                
            
            }
            if (jeuEchec->echiquier[coordaDEplacer.y][coordaDEplacer.x].couleur == jeuEchec->joueur1.couleur)
                suprimerPiece(&jeuEchec->joueur1, jeuEchec->echiquier[coordaDEplacer.y][coordaDEplacer.x]);
            else suprimerPiece(&jeuEchec->joueur2, jeuEchec->echiquier[coordaDEplacer.y][coordaDEplacer.x]);
        }
    }
}
void afficherToutesLesPieces(Joueur joueur)
{
    int i = 0;

    for (i = 0; i < joueur.nbPiece; i++)
    {
        Piece piece = joueur.pieceJoueur[i];
        printf("vie %d, couleur %d, nom %d, x %d, y %d, haut %d\n", piece.en_vie, piece.couleur, piece.nom, piece.position.x, piece.position.y, piece.haut);
    }
    printf("\n");
}
void calculerTouteCoordJoueur(Joueur joueur, echec jeuEchec,Coordonnee* coordonnePossible)
{
    int i;
    int indiceToutePiece=0;
    initialiserListeCoordonee(&coordonnePossible[0], 100);
    Coordonnee coordPiece[100];
    for (i = 0; i < joueur.nbPiece; i++)
    {
        initialiserListeCoordonee(&coordPiece[0], 28);
        case_possible(joueur.pieceJoueur[i], jeuEchec, &coordPiece[0],0);

        ConcatenerListeCoordonnee(&coordonnePossible[0], &coordPiece[0], &indiceToutePiece);
    }
  

}
void ConcatenerListeCoordonnee(Coordonnee* coordToutesPieces, Coordonnee *CoordUnePiece, int* i)
{
    int j = 0;
    for (j = 0; j < 28; j++)
    {

        if (CoordUnePiece[j].x != -1)
        {
            coordToutesPieces[*i] = CoordUnePiece[j];
            *i =*i+ 1;
        }

    }
}
void afficherTouteCoordonee(Coordonnee* coordonnne)
{
    int i;
    for (i = 0; i < 28; i++)
    {
        if (coordonnne[i].x!=-1) printf("%d %d\n", coordonnne[i].x, coordonnne[i].y);
    }
    printf("\n");
}

void verifierLesEchecs(Coordonnee* coordonnePossible, echec jeuEchec, Piece pieceADeplacer)
{
    int i = 0;
    int joueurNeJouanntPas = 1;
    Coordonnee TouteCoordonnePossible[100];
    if (pieceADeplacer.couleur == jeuEchec.joueur1.couleur) joueurNeJouanntPas = 2;

    echec jeuEchecCopie = jeuEchec;
    for (i = 0; i < 28; i++)
    {

        if (coordonnePossible[i].x != -1 && coordonnePossible[i].x >= 0 && coordonnePossible[i].y>= 0 && coordonnePossible[i].x<=  7 && coordonnePossible[i].y <= 7)
        {
            initialiserListeCoordonee(&TouteCoordonnePossible, 100);
            deplacerPiece(NULL, &jeuEchec, pieceADeplacer, coordonnePossible[i],1);           
            if (joueurNeJouanntPas == 1) {
                
                calculerTouteCoordJoueur(jeuEchec.joueur1, jeuEchec, &TouteCoordonnePossible[0]);
                if (RoiEstCoordonne(jeuEchec.joueur2, &TouteCoordonnePossible[0]) == 0)
                {
                    coordonnePossible[i].x = -1;
                    coordonnePossible[i].y = -1;
                }
            }
            else {
                
                calculerTouteCoordJoueur(jeuEchec.joueur2, jeuEchec, &TouteCoordonnePossible[0]);
                
                if (RoiEstCoordonne(jeuEchec.joueur1, &TouteCoordonnePossible[0])==0)
                {
                    coordonnePossible[i].x = -1;
                    coordonnePossible[i].y = -1;
                }
            }          
         
            jeuEchec = jeuEchecCopie;
        }
    }
}
int RoiEstCoordonne(Joueur joueur, Coordonnee* coordonneePossible)
{
    int i = 0;
    while (coordonneePossible[i].x != -1 && i<100)
    {
        if (coordonneePossible[i].x == joueur.positionRoi.x && coordonneePossible[i].y == joueur.positionRoi.y) return 0;
        i++;
    }

    return 1;
}
void copiePiece(Piece* pieceACopier, Piece* piece)
{
    int i = 0;
    for (i = 0; i < 16; i++)
    {
        pieceACopier[i] = piece[i];
    }
}

int verifieCasePossibleJoueur(echec jeuEchec, Joueur joueur)
{
    int i;
    int j;

    Coordonnee coordPossible[28];

    for (i = 0; i < joueur.nbPiece;i++)
    {
        initialiserListeCoordonee(&coordPossible[0], 28);
        case_possible(joueur.pieceJoueur[i], jeuEchec, &coordPossible[0], 1);
        for (j = 0; j < 28; j++)
        {
   
            if (coordPossible[j].x != -1) return 0;
            
        }
    }
    return 1;
}

int echecMatPat(echec jeuEchec, Joueur joueur)
{
    Joueur joueurNeJouantPas;
    if (jeuEchec.joueur2.couleur == joueur.couleur) joueurNeJouantPas = jeuEchec.joueur1;
    else joueurNeJouantPas = jeuEchec.joueur2;
    if (verifieCasePossibleJoueur(jeuEchec,joueur)==0) return 0;
    
    Coordonnee coordonneePossibleJoueurAdverse[100];
    calculerTouteCoordJoueur(joueurNeJouantPas, jeuEchec, &coordonneePossibleJoueurAdverse[0]);
    if (RoiEstCoordonne(joueur, &coordonneePossibleJoueurAdverse[0]) == 0)  return 1;
    else return 2;
}
int evaluerUnePosition(echec jeuEchec, int couleur)
{
    int valeurPosition = 0;
    Joueur joueurJouant = jeuEchec.joueur1;
    Joueur joueurNEjouantPas = jeuEchec.joueur2;
    if (couleur == jeuEchec.joueur2.couleur){
        joueurJouant = jeuEchec.joueur2;
        joueurNEjouantPas = jeuEchec.joueur1;
    }
    valeurPosition=evaluerPositionJoueur(joueurJouant);
    valeurPosition-=evaluerPositionJoueur(joueurNEjouantPas);
    int echecMatJoueurJouant;
    echecMatJoueurJouant = echecMatPat(jeuEchec, joueurNEjouantPas);
    int echecMatJoueurNeJouantPas;
    echecMatJoueurNeJouantPas = echecMatPat(jeuEchec, joueurJouant);
    if (echecMatJoueurJouant == 2 || echecMatJoueurNeJouantPas==2)valeurPosition = 0;
    if (echecMatJoueurJouant == 1)valeurPosition = 1000;
    if(echecMatJoueurNeJouantPas==1)valeurPosition = -1000;
    return valeurPosition;
}
int evaluerPositionJoueur(Joueur joueur)
{
    int valeurPosition = 0;
    int i;
    for (i = 0; i < joueur.nbPiece; i++) {
        
        switch (joueur.pieceJoueur[i].nom)
        {
        case Pion:
            valeurPosition += 10;
            break;
        case Dame:
            valeurPosition += 90;
            break;
        case Cavalier:
            valeurPosition += 32;
            break;
        case Fou:
            valeurPosition += 33;
            break;
        case Tour:
            valeurPosition += 50;
            break;
        }  
    }
    return valeurPosition;
}
int minMax(echec jeuEchec, int couleurJouant, int CoupAnticipe,Piece* pieceADeplacer,Coordonnee* coordonnePossible, int couleurDeBase)
{
    
  
    if (CoupAnticipe == 0)
    {

        return evaluerUnePosition(jeuEchec, couleurJouant);
    }
    else
    {
        Coordonnee coordonneeJoueur[100];
        Joueur joueurJouant;
        if (couleurJouant == jeuEchec.joueur1.couleur) joueurJouant = jeuEchec.joueur1;
        else joueurJouant = jeuEchec.joueur2;
        int valeurPossible;
        int i;
        int j;
        int valeurOptimal = 0;
        echec copieJEuEchec = jeuEchec;



        for (i = 0; i < joueurJouant.nbPiece; i++)
        {
            initialiserListeCoordonee(&coordonneeJoueur[0], 100);

            case_possible(joueurJouant.pieceJoueur[i], jeuEchec, &coordonneeJoueur[0], 1);
      
            
            for (j = 0; j < 28; j++)
            {
                
                if (coordonneeJoueur[j].x != -1)
                {
    
                    deplacerPiece(NULL, &jeuEchec, joueurJouant.pieceJoueur[i], coordonneeJoueur[j], 1);
                    
                    
               
                    if (couleurJouant == couleurDeBase) {
                     
                        valeurPossible = minMax(jeuEchec,2, CoupAnticipe - 1, NULL, NULL, couleurDeBase);

                        if (valeurOptimal == 0 || ( valeurOptimal < valeurPossible))
                        {

                            valeurOptimal = valeurPossible;
                            if (CoupAnticipe == 4)
                            {
                                *pieceADeplacer = joueurJouant.pieceJoueur[i];
                                *coordonnePossible = coordonneeJoueur[j];
                            }
                        }
                    }
                    else
                    {
                        valeurPossible = minMax(jeuEchec, couleurDeBase, CoupAnticipe - 1, NULL, NULL,couleurDeBase);
                           
                 
                        if (valeurOptimal == 0 ||( valeurOptimal > valeurPossible))
                        {


                            valeurOptimal = valeurPossible;
                            if (CoupAnticipe == 4)
                            {
                                *pieceADeplacer = joueurJouant.pieceJoueur[i];
                                *coordonnePossible = coordonneeJoueur[j];
                            }
                        }
                    }
                    jeuEchec = copieJEuEchec;
                }
            }
        }       
        return valeurOptimal;
    }
}
