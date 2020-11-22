#ifndef TABLEAU2D_H_INCLUDED
#define TABLEAU2D_H_INCLUDED

// tableau de caractères en 2 dimensions
// à l'initialisation, chaque cellule contient '.'
// sauf la dernière ligne qui contient les numéros de ligne

// les lignes sont indéxées à partir de 0 en partant du coin haut gauche du tableau
// les colonnes sont indéxées à partir de 0 en partant de la gauche du tableau (mais elles sont comptées à partir de 1 quand il s'agit de l'affichage utilisateur)

// une cellule est nommée par sa colonne puis sa ligne
// par exemple (0, 2)

struct Tableau2D {
    unsigned int nbColonnes;
    unsigned int nbLignes;
    char* cellules;
};

// convertit le tableau en une chaine de caractères qui peut être affichée à l'écran
char* toString(const Tableau2D* t);

// initialise une grille vide avec le nombre de lignes et de colonnes donné
void init(Tableau2D*, unsigned int nbColonnes, unsigned int nbLignes);

// supprime la grille et libère la mémoire associée à la grille
void suppressionGrille(Tableau2D*);

// renvoie le caractère à la position donnée dans la grille
char get(const Tableau2D*, unsigned int colonne, unsigned int ligne);

// demande au joueur donné de saisir un numéro de colonne jusqu'à ce qu'il entre un coup valide
// joueur peut être 1 ou 2
// retourne la colonne choisie par le joueur (indexée de 0 à gauche)
unsigned int getCoupJoueur(const Tableau2D* t, unsigned int joueur);

// place le caractère à la position donnée dans la grille sur le caractère donné
void set(Tableau2D*, unsigned int colonne, unsigned int ligne, char);

// renvoie 1 si le joueur peut jouer la colonne donnée, 0 sinon
unsigned int estCoupValide(const Tableau2D* t, unsigned int colonne);

// effectue un coup pour le joueur donné sur la colonne donnée, suppose que le coup est valide
// joueur peut être 1 ou 2
// renvoie 1 si le joueur a gagné, 0 sinon
unsigned int faireCoup(Tableau2D* t, unsigned int joueur, unsigned int colonne);

// renvoie le nombre de caractères consécutifs à gauche à partir du caractère à la position donnée et qui sont identiques au caractère à la position donnée
unsigned int comptageGauche(const Tableau2D* t, unsigned int colonne, unsigned int ligne);

// renvoie le nombre de caractères consécutifs à droite à partir du caractère à la position donnée et qui sont identiques au caractère à la position donnée
unsigned int comptageDroite(const Tableau2D* t, unsigned int colonne, unsigned int ligne);

// renvoie le nombre de caractères consécutifs en bas à partir du caractère à la position donnée et qui sont identiques au caractère à la position donnée
unsigned int comptageBas(const Tableau2D* t, unsigned int colonne, unsigned int ligne);

// renvoie le nombre de caractères consécutifs en haut à gauche à partir du caractère à la position donnée et qui sont identiques au caractère à la position donnée
unsigned int comptageHautGauche(const Tableau2D* t, unsigned int colonne, unsigned int ligne);

// renvoie le nombre de caractères consécutifs en haut à droite à partir du caractère à la position donnée et qui sont identiques au caractère à la position donnée
unsigned int comptageHautDroite(const Tableau2D* t, unsigned int colonne, unsigned int ligne);

// renvoie le nombre de caractères consécutifs en bas à gauche à partir du caractère à la position donnée et qui sont identiques au caractère à la position donnée
unsigned int comptageBasGauche(const Tableau2D* t, unsigned int colonne, unsigned int ligne);

// renvoie le nombre de caractères consécutifs en bas à droite à partir du caractère à la position donnée et qui sont identiques au caractère à la position donnée
unsigned int comptageBasDroite(const Tableau2D* t, unsigned int colonne, unsigned int ligne);

// renvoie 1 s'il y a une ligne horizontale, verticale ou diagonale de 4 caractères consécutivement identiques contenant la cellule donnée, sinon renvoie 0
unsigned int QuatreAlignes(const Tableau2D* t, unsigned int colonne, unsigned int ligne);


#endif // TABLEAU2D_H_INCLUDED
