#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Tableau2D.h"
#include "unittest.h"
#include "Puissance4Test.h"



int main() {
    testPuissance4();


    // initialise un tableau vide
    Tableau2D t;
    init(&t, 7, 6);

    // affiche le tableau vide
    puts("Après l'initialisation :\n");
    puts(toString(&t));

    unsigned int fini = 0; // devient 1 quand un joueur gagne
    unsigned int joueurActuel = 1;

    while (!fini) {
        // demande au joueur la colonne à jouer
        unsigned int colonne = getCoupJoueur(&t, joueurActuel);
        // faire un coup dans cette colonne
        fini = faireCoup(&t, joueurActuel, colonne);
        // affiche le tableau mis à jour
        puts(toString(&t));
        if (fini) {
            // la partie est finie, affiche le gagnant
            printf("Player %u wins!\n", joueurActuel);
        }
        else {
            // changement de joueur
            if (joueurActuel == 1) {
                joueurActuel = 2;
            }
            else {
                joueurActuel = 1;
            }
        }
    }

    // fin du jeu, efface le tableau
    suppressionGrille(&t);

    return 0;
}




