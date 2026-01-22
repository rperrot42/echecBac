
#include "sdl.h"

#include <stdio.h>

int main2(int argc, char* argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur SDL_Init : %s\n", SDL_GetError());
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow(
        "Texture Rouge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        400, 400, SDL_WINDOW_SHOWN
    );
    if (!window) {
        printf("Erreur SDL_CreateWindow : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Création du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur SDL_CreateRenderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Création de la texture cible 200x200
    SDL_Texture* texture = SDL_CreateTexture(
        renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET, 200, 200
    );
    if (!texture) {
        printf("Erreur SDL_CreateTexture : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Dessiner sur la texture (remplir en rouge)
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // rouge opaque
    SDL_RenderClear(renderer); // rempli toute la texture
    SDL_SetRenderTarget(renderer, NULL); // revenir au rendu normal

    // Boucle principale simple
    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
        }

    // Effacer l'écran (noir)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Afficher la texture rouge
    SDL_Rect dstRect = {100, 100, 200, 200}; // position et taille
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);

    // Mettre à jour l'écran
    SDL_RenderPresent(renderer);
    }

    // Nettoyage
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

int main(void)
{

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;

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

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET, 200, 200);
    if (!texture) {
        printf("erreur");
        goto Quit;
    }
    SDL_Texture* rondNoir = SDL_CreateTextureFromSurface(renderer, image);  //La texture monImage contient maintenant l'image import�e
    SDL_FreeSurface(image);






    SDL_SetRenderTarget(renderer, texture);
    // /* La texture est la cible de rendu, maintenant, on dessine sur la texture. */
    //
    //
    //
    // /* On dessine un rectangle rouge sur la texture. */

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
    joueur2.bot = 1;
    joueur2.couleur = 1;
    joueur2.haut = 0;

    jeuechec.taille = 400;
    jeuechec.positonEchiquier = point;
    jeuechec.joueur1 = joueur1;
    jeuechec.joueur2 = joueur2;
    t_piece_echec piece_echec;
    if (init_piece_echec(&piece_echec, renderer))
        return 1;
    if (initialiser_echiquier(renderer, &jeuechec, &piece_echec))
        return 1;
    SDL_RenderPresent(renderer);

    int program_lunched = 1;
    int afficher_coord_possible = 1;
    Coordonnee CoordonnePossiblePion[28];
    Piece pieceAppuyer;
    int nbTour = 0;
    int tourPasse;
    tourPasse = -2;
    int pionPasse = 0;
    pieceAppuyer.nom = Tour;
    jeuechec.rondNoir = rondNoir;
    initialiserListeCoordonee(&CoordonnePossiblePion[0], 28);

    while (program_lunched) {
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
            if (joueur1.couleur != nbTour % 2)
            {

                valeurEchecMat = echecMatPat(jeuechec, jeuechec.joueur1);
                if (valeurEchecMat == 1)
                    printf("le joueur 2 a gagne");
                if (valeurEchecMat == 2)
                    printf(" Il y a nulle");
            }
            else {
                valeurEchecMat = echecMatPat(jeuechec, jeuechec.joueur2);

                if (valeurEchecMat == 1)
                    printf("le joueur 1 a gagne");
                if (valeurEchecMat == 2)
                    printf(" Il y a nul");
            }
            if (valeurEchecMat != 0)
                program_lunched = 0;
        }


        while(SDL_PollEvent(&event)){
            switch (event.type)
            {
            case SDL_QUIT:
                    program_lunched = 0;
                    break;
            case SDL_MOUSEBUTTONDOWN:
            {
                Piece pieces_sourie;
                pieces_sourie = case_position_pieces(event.button.x, event.button.y, jeuechec);

                if (pieceEstCoordonnePossible(pieces_sourie, &CoordonnePossiblePion[0], 28) == 0)
                {

                    if (tourPasse == nbTour - 1) {
                        jeuechec.pionPasse.possible = 1;
                        pionPasse = 0;
                    }
                    deplacerPiece(renderer, &jeuechec, pieceAppuyer, pieces_sourie.position,1);

                    if (jeuechec.pionPasse.possible == 0 && pionPasse==0)
                    {
                        int* pointeur = &nbTour;
                        tourPasse=*pointeur+1;
                        pionPasse = 1;
                    }
                    afficher_coord_possible = 1;
                    initialiserListeCoordonee(&CoordonnePossiblePion[0], 28);
                    printEchiquier(renderer, &jeuechec, CoordonnePossiblePion);
                    nbTour += 1;
                    int valeurEchecMat;

                    if (joueur1.couleur !=jeuechec.echiquier[pieces_sourie.position.y][pieces_sourie.position.x].couleur)
                    {

                        valeurEchecMat = echecMatPat(jeuechec, jeuechec.joueur1);
                        if (valeurEchecMat == 1)
                            printf("le joueur 2 a gagne\n");
                        if (valeurEchecMat == 2)
                            printf(" Il y a nulle\n");
                    }
                    else {
                        valeurEchecMat = echecMatPat(jeuechec, jeuechec.joueur2);

                        if (valeurEchecMat == 1)
                            printf("le joueur 1 a gagne\n");
                        if (valeurEchecMat == 2)
                            printf(" Il y a nulle\n");
                    }
                    if (valeurEchecMat != 0)
                        program_lunched = 0;
                }
                else
                {

                    // repeindreListeCase(jeuechec, &CoordonnePossiblePion[0],28, renderer);

                    afficher_coord_possible = 1;
                    if (pieces_sourie.en_vie == 0 && pieces_sourie.couleur == nbTour%2 && pieces_sourie.bot==1)
                    {
                        initialiserListeCoordonee(&CoordonnePossiblePion[0], 28);
                        case_possible(pieces_sourie, jeuechec, &CoordonnePossiblePion[0],1);
                        printEchiquier(renderer, &jeuechec, CoordonnePossiblePion);
                        afficher_coord_possible = 0;
                        pieceAppuyer = pieces_sourie;
                    }
                }
            }
            default:
                    break;
            }
            // initialiser_echiquier(renderer, &jeuechec, &piece_echec);
        }
    }
    return EXIT_SUCCESS;

Quit:
    if (NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if (NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_FAILURE;
}