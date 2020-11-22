#include "Tableau2D.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>

void init(Tableau2D* t, unsigned int nbColonnes, unsigned int nbLignes) {
    t->nbColonnes = nbColonnes;
    t->nbLignes = nbLignes;
    // il y a une ligne en plus pour le numéro de colonne
    t->cellules = (char*) malloc (nbColonnes * (nbLignes + 1) * sizeof(char));
    for(unsigned int i = 0; i < nbColonnes * (nbLignes + 1) ; ++i) {
        if (i < nbColonnes * nbLignes) {
            // pas la dernière ligne
            t->cellules[i] = '.';
        }
        else {
            // la dernière ligne est pour le numéro de colonne
            t->cellules[i] = '1' + i - nbColonnes * nbLignes;
        }
    }
}

void suppressionGrille(Tableau2D* t) {
    free(t->cellules);
    t->nbLignes = 0;
    t->nbColonnes = 0;
}

char get(const Tableau2D* t, unsigned int colonne, unsigned int ligne) {
    // les lignes et colonnes sont indexées à partir de 0
    return t->cellules[t->nbColonnes * ligne + colonne];
}

void set(Tableau2D* t, unsigned int colonne, unsigned int ligne, char c) {
    // les lignes et colonnes sont indexées à partir de 0
    t->cellules[t->nbColonnes * ligne + colonne] = c;
}


unsigned int getCoupJoueur(const Tableau2D* t, unsigned int joueur) {

    unsigned int colonne;
    char input[100];
    int coupValide = 0;

    while (!coupValide) {
        printf("Joueur %u, entrez un numéro de colonne: ", joueur);
        scanf("%s", input);
        colonne = strtol(input, NULL, 10);
        //le tableau indexe les colonnes à partir de 0 mais le joueur entre une colonne à partir de 1, donc on décrémente
        colonne--;
        coupValide = estCoupValide(t, colonne);
        if (!coupValide) {
            puts("\nCe coup n'est pas valide!\n");
        }
    }
    puts("");

    return colonne;
}


unsigned int estCoupValide(const Tableau2D* t, unsigned int colonne) {

    // vérifie si le numéro de colonne est bien dans le tableau
    if (colonne < 0 || colonne >= t->nbColonnes) {
        return 0;
    }

    // vérifie s'il y a de la place dans la colonne
    if (get(t, colonne, 0) == '.') {
        return 1;
    }
    else {
        return 0;
    }
}

char* toString(const Tableau2D* t) {

    // chaque colonne a 2 caractères (incluant l'espace après la colonne)
    // chaque ligne a le caractère de fin de ligne en fin de ligne
    // il y a une ligne en plus pour les numéros de colonnes
    unsigned int taille_s = (t->nbColonnes * 2 + 1) * (t->nbLignes + 1);
    unsigned int lgr = 0;
    // +1 pour le caractère nul à la fin
    char* s = (char*) malloc(taille_s + 1);
    for (unsigned int lin = 0; lin < t->nbLignes + 1; ++lin) {
        for (unsigned int col = 0; col < t->nbColonnes; ++col)
            lgr += sprintf(s + lgr,"%c ", get(t, col, lin));
        lgr += sprintf(s + lgr, "\n");
    }
    return s;
}

unsigned int faireCoup(Tableau2D* t, unsigned int joueur, unsigned int colonne) {

    // trouve la dernière cellule vide dans la colonne donnée à partir du haut
    unsigned int ligne;

    //pour chaque cellule dans la colonne à partir du haut
    for (ligne = 0; ligne < t->nbLignes + 1; ++ligne) {
        if (get(t, colonne, ligne) != '.') {
            // cette cellule n'est pas vide, la cellule précedente est la dernière cellule vide
            ligne = ligne - 1;
            break;
        }
    }

    // determine le caractère à mettre dans la cellule selon le numéro du joueur
    char symboleJoueur;

    if (joueur % 2 == 0) {
        symboleJoueur = 'o';
    }
    else {
        symboleJoueur = 'x';
    }

    // met le caractère dans la cellule
    set(t, colonne, ligne, symboleJoueur);

    // vérifie si le joueur a gagné avec ce coup
    return QuatreAlignes(t, colonne, ligne);
}

unsigned int comptageGauche(const Tableau2D* t, unsigned int colonne, unsigned int ligne) {

    //obtient le caractère de la cellule actuelle
    char symboleActuel = get(t, colonne, ligne);

    // compteur des mêmes caractères consécutifs
    unsigned int compteur = 0;

    // vérifie à gauche de la cellule actuelle
    for (unsigned int colonne2 = colonne - 1; colonne2 >= 0; --colonne2) {
        // obtient le caractère de l'autre cellule
        char symboleActuel2 = get(t, colonne2, ligne);
        if (symboleActuel == symboleActuel2) {
            // les caractères sont identiques
            compteur++;
        }
        else {
            // les caractères sont différents, ne vérifie pas plus dans cette direction
            break;
        }
    }

    return compteur;
}

unsigned int comptageDroite(const Tableau2D* t, unsigned int colonne, unsigned int ligne) {

    //obtient le caractère de la cellule actuelle
    char symboleActuel = get(t, colonne, ligne);

    // compteur des caractères identiques consécutifs
    unsigned int compteur = 0;

    // vérifie à droite de la cellule actuelle
    for (unsigned int colonne2 = colonne + 1; colonne2 < t->nbColonnes; ++colonne2) {
        // obtient le caractère de l'autre cellule
        char symboleActuel2 = get(t, colonne2, ligne);
        if (symboleActuel == symboleActuel2) {
            // les caractères sont identiques
            compteur++;
        }
        else {
            // les caractères sont différents, ne vérifie pas plus dans cette direction
            break;
        }
    }

    return compteur;
}

unsigned int comptageBas(const Tableau2D* t, unsigned int colonne, unsigned int ligne) {

    //obtient le caractère de la cellule actuelle
    char symboleActuel = get(t, colonne, ligne);

    // compteur des caractères identiques consécutifs
    unsigned int compteur = 0;

    // vérifie sous la cellule actuelle
    for (unsigned int ligne2 = ligne + 1; ligne2 < t->nbLignes; ++ligne2) {
        // obtient le caractère de l'autre cellule
        char symboleActuel2 = get(t, colonne, ligne2);
        if (symboleActuel == symboleActuel2) {
            // les caractères sont identiques
            compteur++;
        }
        else {
            // les caractères sont différents, ne vérifie pas plus dans cette direction
            break;
        }
    }

    return compteur;
}

unsigned int comptageHautGauche(const Tableau2D* t, unsigned int colonne, unsigned int ligne) {

    //obtient le caractère de la cellule actuelle
    char symboleActuel = get(t, colonne, ligne);

    // compteur des caractères identiques consécutifs
    unsigned int compteur = 0;

    // vérifie en haut à gauche à partir de la cellule actuelle
    for (unsigned int ligne2 = ligne - 1, colonne2 = colonne - 1; ligne2 >= 0 && colonne2 >= 0; --ligne2, --colonne2) {
        // obtient le caractère de l'autre cellule
        char symboleActuel2 = get(t, colonne2, ligne2);
        if (symboleActuel == symboleActuel2) {
            // les caractères sont identiques
            compteur++;
        }
        else {
            // les caractères sont différents, ne vérifie pas plus dans cette direction
            break;
        }
    }

    return compteur;
}

unsigned int comptageHautDroite(const Tableau2D* t, unsigned int colonne, unsigned int ligne) {

    //obtient le caractère de la cellule actuelle
    char symboleActuel = get(t, colonne, ligne);

    // compteur des caractères identiques consécutifs
    unsigned int compteur = 0;

    // vérifie en haut à droite à partir de la cellule actuelle
    for (unsigned int ligne2 = ligne - 1, colonne2 = colonne + 1; ligne2 >= 0 && colonne2 < t->nbColonnes; --ligne2, ++colonne2) {
        // obtient le caractère de l'autre cellule
        char symboleActuel2 = get(t, colonne2, ligne2);
        if (symboleActuel == symboleActuel2) {
            // les caractères sont identiques
            compteur++;
        }
        else {
            // les caractères sont différents, ne vérifie pas plus dans cette direction
            break;
        }
    }

    return compteur;
}

unsigned int comptageBasGauche(const Tableau2D* t, unsigned int colonne, unsigned int ligne) {

    //obtient le caractère de la cellule actuelle
    char symboleActuel = get(t, colonne, ligne);

    // compteur des caractères identiques consécutifs
    unsigned int compteur = 0;

    // vérifie en bas à gauche à partir de la cellule actuelle
    for (unsigned int ligne2 = ligne + 1, colonne2 = colonne - 1; ligne2 < t->nbLignes && colonne2 >= 0; ++ligne2, --colonne2) {
        // obtient le caractère de l'autre cellule
        char symboleActuel2 = get(t, colonne2, ligne2);
        if (symboleActuel == symboleActuel2) {
            // les caractères sont identiques
            compteur++;
        }
        else {
            // les caractères sont différents, ne vérifie pas plus dans cette direction
            break;
        }
    }

    return compteur;
}

unsigned int comptageBasDroite(const Tableau2D* t, unsigned int colonne, unsigned int ligne) {

    //obtient le caractère de la cellule actuelle
    char symboleActuel = get(t, colonne, ligne);

    // compteur des caractères identiques consécutifs
    unsigned int compteur = 0;

    // vérifie en bas à droite à partir de la cellule actuelle
    for (unsigned int ligne2 = ligne + 1, colonne2 = colonne + 1; ligne2 < t->nbLignes && colonne2 < t->nbColonnes; ++ligne2, ++colonne2) {
        // obtient le caractère de l'autre cellule
        char symboleActuel2 = get(t, colonne2, ligne2);
        if (symboleActuel == symboleActuel2) {
            // les caractères sont identiques
            compteur++;
        }
        else {
            // les caractères sont différents, ne vérifie pas plus dans cette direction
            break;
        }
    }

    return compteur;
}

unsigned int QuatreAlignes(const Tableau2D* t, unsigned int colonne, unsigned int ligne) {

    // vérifie horizontalement 
    if (comptageGauche(t, colonne, ligne) + comptageDroite(t, colonne, ligne) + 1 >= 4) {
        return 1;
    }
    // vérifie verticalement
    if (comptageBas(t, colonne, ligne) + 1 >= 4) {
        return 1;
    }
    // vérifie diagonalement 
    if (comptageHautGauche(t, colonne, ligne) + comptageBasDroite(t, colonne, ligne) + 1 >= 4) {
        return 1;
    }
    // vérifie diagonalement 
    if (comptageHautDroite(t, colonne, ligne) + comptageBasGauche(t, colonne, ligne) + 1 >= 4) {
        return 1;
    }
    else {
        return 0;
    }
}
