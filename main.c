
#include "sdl.h"

int main(void)
{

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET, 200, 200);
    /* Initialisation, cr�ation de la fen�tre et du renderer. */
    if (0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    if (SDL_CreateWindowAndRenderer(600, 600, 0, &window, &renderer) != 0)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }

    SDL_Surface* image = SDL_LoadBMP("image pieces d'echec/image rond noir.bmp");
    if (!image)
    {
        printf("erreur");
        goto Quit;
    }
    SDL_Texture* rondNoir = SDL_CreateTextureFromSurface(renderer, image);  //La texture monImage contient maintenant l'image import�e
    SDL_FreeSurface(image);






    SDL_SetRenderTarget(renderer, texture);
    /* La texture est la cible de rendu, maintenant, on dessine sur la texture. */



    /* On dessine un rectangle rouge sur la texture. */

    SDL_SetRenderTarget(renderer, NULL); /* Le renderer est la cible de rendu. */

    /* On r�cup�re les dimensions de la texture, on la copie sur le renderer
       et on met � jour l��cran. */




    Coordonnee point = { 100,100 };
    echec jeuechec;
    Joueur joueur1;
    Joueur joueur2;
    joueur1.couleur = 0;
    joueur1.haut = 1;
    joueur1.bot = 1;
    joueur2.bot =1;
    joueur2.couleur = 1;
    joueur2.haut = 0;
    
    jeuechec.taille = 400;
    jeuechec.positonEchiquier = point;
    jeuechec.joueur1 = joueur1;
    jeuechec.joueur2 = joueur2;
    printf("%d", initialiser_echiquier(renderer, &jeuechec));
    SDL_RenderPresent(renderer);
	while (1);
	/*
    int program_lunched = 1;
    int afficher_coord_possible = 1;
    Coordonnee CoordonnePossiblePion[28];
    Piece pieceAppuyer;
    int nbTour = 0;
    int tourPasse;
    tourPasse = -2;
    int pionPasse = 0;
    pieceAppuyer.nom = Tour;
    initialiserListeCoordonee(&CoordonnePossiblePion[0], 28);

    while (program_lunched)
    {

        SDL_Event event;
        if ((nbTour % 2 == joueur1.couleur && joueur1.bot == 0 )||(nbTour % 2 == joueur2.couleur && joueur2.bot == 0))
        {
            Piece pieceAdeplacer;
            Coordonnee coordADEplacer;
     
            
            minMax(jeuechec, nbTour%2,4, &pieceAdeplacer, &coordADEplacer, nbTour % 2);
            deplacerPiece(renderer, &jeuechec, pieceAdeplacer, coordADEplacer, 1);
            Coordonnee coordonneApeindre[1];
            coordonneApeindre[0] = coordADEplacer;
            repeindreListeCase(jeuechec, &coordonneApeindre[0], 1, renderer);
            nbTour += 1;
            int valeurEchecMat;
            if (joueur1.couleur != nbTour%2)
            {

                valeurEchecMat = echecMatPat(jeuechec, jeuechec.joueur1);
                if (valeurEchecMat == 1)printf("le joueur 2 a gagne");
                if (valeurEchecMat == 2)printf(" Il y a nul");
            }
            else {
                valeurEchecMat = echecMatPat(jeuechec, jeuechec.joueur2);

                if (valeurEchecMat == 1)printf("le joueur 1 a gagne");
                if (valeurEchecMat == 2)printf(" Il y a nul");
            }
            if (valeurEchecMat != 0) program_lunched = 0;
        }
        
        while(SDL_PollEvent(&event))
            switch (event.type)
            {
            case SDL_QUIT:
                program_lunched = 0;
                break;

            case SDL_MOUSEBUTTONDOWN:
                
                {

                    Piece Pieces_sourie;
                    Pieces_sourie = case_position_pieces(event.button.x, event.button.y, jeuechec);
            
                   

                    if (pieceEstCoordonnePossible(Pieces_sourie, &CoordonnePossiblePion[0], 28) == 0)
                    {
                        
                        if (tourPasse == nbTour - 1) {
                            jeuechec.pionPasse.possible = 1;
                            pionPasse = 0;
                        }
                        deplacerPiece(renderer, &jeuechec, pieceAppuyer, Pieces_sourie.position,1);
       
                            if (jeuechec.pionPasse.possible == 0 && pionPasse==0)
                        {
                            int* pointeur = &nbTour;
                            tourPasse=*pointeur+1;
                            pionPasse = 1;
                        }
                        repeindreListeCase(jeuechec, &CoordonnePossiblePion[0], 28, renderer);
                        afficher_coord_possible = 1;
                        initialiserListeCoordonee(&CoordonnePossiblePion[0], 28);
                        
                        nbTour+=1;
                        int valeurEchecMat;

                        if (joueur1.couleur !=jeuechec.echiquier[Pieces_sourie.position.y][Pieces_sourie.position.x].couleur)
                        {
                           
                            valeurEchecMat = echecMatPat(jeuechec, jeuechec.joueur1);
                            if (valeurEchecMat == 1)printf("le joueur 2 a gagne");
                            if (valeurEchecMat == 2)printf(" Il y a nul");
                        }
                        else {
                            valeurEchecMat = echecMatPat(jeuechec, jeuechec.joueur2);

                            if (valeurEchecMat == 1)printf("le joueur 1 a gagne");
                            if (valeurEchecMat == 2)printf(" Il y a nul");
                        }
                        if (valeurEchecMat != 0) program_lunched = 0;
                    }
                    else
                    {
                        
                        repeindreListeCase(jeuechec, &CoordonnePossiblePion[0],28, renderer);
                
                        afficher_coord_possible = 1;
                        
                        if (Pieces_sourie.en_vie == 0 && Pieces_sourie.couleur == nbTour%2 && Pieces_sourie.bot==1)
                        {                                                       
                            if (afficher_coord_possible == 1)
                            {

                                initialiserListeCoordonee(&CoordonnePossiblePion[0], 28);
                                case_possible(Pieces_sourie, jeuechec, &CoordonnePossiblePion[0],1);
                                afficher_coordonne(renderer, rondNoir, &CoordonnePossiblePion[0], jeuechec,28);
                                afficher_coord_possible = 0;
                                pieceAppuyer = Pieces_sourie;
                            }                            
                        }
                    }
                }
            default:
                break;


            }
    }
	*/
    return EXIT_SUCCESS;

Quit:
    if (NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if (NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_FAILURE;
}
//gcc sdl/main.c -o prog -I include -L lib -mingw32 -lSDL2main -lSDL2