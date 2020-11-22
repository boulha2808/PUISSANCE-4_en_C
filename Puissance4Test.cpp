#include <stdio.h>
#include <string.h>
#include "Tableau2D.h"
#include "Puissance4Test.h"
#include "unittest.h"

void testPuissance4() {

    
    Tableau2D t;
    init(&t, 7, 6);

   // vérifie si l'initialisation est correcte
    assertTrue(t->cellules != NULL, "t->cellules != NULL");

    assertEquals(6u, t->nbLignes, "comptage du nombre de lignes");
    assertFalse(t->nbLignes==7u, "comptage du nombre de lignes ");
    assertFalse(t->nbLignes==5u, "comptage du nombre de lignes ");
    assertTrue(t->nbLignes==6u, "comptage du nombre de lignes ");

    assertEquals(7u, t->nbColonnes, "comptage du nombre de colonnes");
    assertFalse(t->nbColonnes==8u, "comptage du nombre de colonnes ");
    assertFalse(t->nbColonnes==6u, "comptage du nombre de colonnes ");
    assertTrue(t->nbColonnes==7u, "comptage du nombre de colonnes ");

    assertEquals(42u, (t->nbColonnes)*(t->nbLignes), "comptage du nombre de cellules");
    assertFalse(t->nbColonnes*t->nbLignes==41u, "comptage du nombre de cellules ");
    assertFalse(t->nbColonnes*t->nbLignes==43u, "comptage du nombre de cellules ");
    assertTrue(t->nbColonnes*t->nbLignes==42u, "comptage du nombre de cellules");


    // joueur 1 joue la première colonne
    faireCoup(&t, 0, 0);
    // vérifie si la grille est à jour
    assertTrue(get(&t, 0, 5) == 'o', "joueur 1 joue la première colonne");
    assertFalse(get(&t, 1, 5) == 'o', "joueur 1 joue la première colonne");
    assertFalse(get(&t, 5, 0) == 'o', "joueur 2 joue la première colonne ");


    // joueur 2 joue la première colonne après le joueur 1
    faireCoup(&t, 1, 0);
    // verifie si la grille est à jour
    assertTrue(get(&t, 0, 4) == 'x', "joueur 2 joue la première colonne après que joueur 1 a joué colonne 1");
    assertFalse(get(&t, 1, 4) == 'x', "joueur 2 joue la première colonne après que joueur 1 a joué colonne 1");
    assertFalse(get(&t, 4, 0) == 'x', "joueur 2 joue la première colonne après que joueur 1 a joué colonne 1");
    //vérifie si le coup du joueur 1 est toujours là
    assertTrue(get(&t, 0, 5) == 'o', "coup du joueur 1 toujours présent");



    //Remplir colonne 1 en laissant une seule place
      init(&t, 7, 6);
    set(&t, 0, 1, 'x');
    set(&t, 0, 2, 'x');
    set(&t, 0, 3, 'x');
    set(&t, 0, 4, 'x');
    set(&t, 0, 5, 'x');

    assertTrue(estCoupValide(&t, 0), "coup valide sur colonne laissant 1 place libre");



    set(&t, 0, 0, 'x');
    // essai d'un coup sur  colonne remplie
    assertFalse(estCoupValide(&t, 0), "coup non valide colonne remplie");

    assertTrue(QuatreAlignes(&t, 0, 1), "QuatreAlignes test");
    assertTrue(QuatreAlignes(&t, 0, 2), "QuatreAlignes test");



    // change le caractère d'une cellule
    set(&t, 0, 5, 'x');
    // vérifie si la grille a bien été mis à jour
    assertTrue(get(&t, 0, 5) == 'x', "modification manuelle de la grille");
    assertFalse(get(&t, 0, 5) == 'o', "modification manuelle de la grille");
    assertFalse(get(&t, 0, 5) == 'z', "modification manuelle de la grille");


    // change le caractère d'une cellule
    set(&t, 2, 6, 'x');
    // vérifie si la grille a bien été mis à jour
    assertTrue(get(&t, 2, 6) == 'x', "modification manuelle de la grille");
    assertFalse(get(&t, 2, 6) == 'o', "modification manuelle de la grille");
    assertFalse(get(&t, 2, 6) == 'z', "modification manuelle de la grille");



    // essai d'un coup hors de la grille

    assertFalse(estCoupValide(&t, -1), "coup non valide -1");
    assertFalse(estCoupValide(&t, 7), "coup non valide 7");
    assertFalse(estCoupValide(&t, 10), "coup non valide 10");
    assertFalse(estCoupValide(&t, 11), "coup non valide 11");

    assertFalse(estCoupValide(&t, 0), "coup valide 0");
    assertTrue(estCoupValide(&t, 1), "coup valide 1");
    assertTrue(estCoupValide(&t, 2), "coup valide 2");
    assertTrue(estCoupValide(&t, 3), "coup valide 3");
    assertTrue(estCoupValide(&t, 4), "coup valide 4");
    assertTrue(estCoupValide(&t, 5), "coup valide 5");
    assertTrue(estCoupValide(&t, 6), "coup valide 6");



    // fait ligne verticale
        init(&t, 7, 6);

    set(&t, 0, 0, 'x');
    set(&t, 0, 1, 'x');
    set(&t, 0, 2, 'x');
    set(&t, 0, 3, 'x');
    set(&t, 0, 4, 'x');
    set(&t, 0, 5, 'x');


    // test comptageBas
    assertEquals(5u, comptageBas(&t, 0, 0), "comptageBas test");
    assertEquals(4u, comptageBas(&t, 0, 1), "comptageBas test");
    assertEquals(3u, comptageBas(&t, 0, 2), "comptageBas test");
    assertEquals(2u, comptageBas(&t, 0, 3), "comptageBas test");
    assertEquals(1u, comptageBas(&t, 0, 4), "comptageBas test");
    assertEquals(0u, comptageBas(&t, 0, 5), "comptageBas test");

    // fait ligne verticale
        init(&t, 7, 6);

    set(&t, 0, 5, 'x');
    set(&t, 1, 5, 'x');
    set(&t, 2, 5, 'x');
    set(&t, 3, 5, 'x');
    set(&t, 4, 5, 'x');
    set(&t, 5, 5, 'x');
    set(&t, 6, 5, 'x');

   // test comptageGauche
    assertEquals(0u, comptageGauche(&t, 0, 5), "comptageGauche test");
    assertEquals(1u, comptageGauche(&t, 1, 5), "comptageGauche test");
    assertEquals(2u, comptageGauche(&t, 2, 5), "comptageGauche test");
    assertEquals(3u, comptageGauche(&t, 3, 5), "comptageGauche test");
    assertEquals(4u, comptageGauche(&t, 4, 5), "comptageGauche test");
    assertEquals(5u, comptageGauche(&t, 5, 5), "comptageGauche test");
    assertEquals(6u, comptageGauche(&t, 6, 5), "comptageGauche test");

    // test comptageDroite
    assertEquals(6u, comptageDroite(&t, 0, 5), "comptageDroite test");
    assertEquals(5u, comptageDroite(&t, 1, 5), "comptageDroite test");
    assertEquals(4u, comptageDroite(&t, 2, 5), "comptageDroite test");
    assertEquals(3u, comptageDroite(&t, 3, 5), "comptageDroite test");
    assertEquals(2u, comptageDroite(&t, 4, 5), "comptageDroite test");
    assertEquals(1u, comptageDroite(&t, 5, 5), "comptageDroite test");
    assertEquals(0u, comptageDroite(&t, 6, 5), "comptageDroite test");

    // fait une diagonale d'en haut à gauche vers en bas à droite 
    init(&t, 7, 6);


    set(&t, 0, 0, 'x');
    set(&t, 1, 1, 'x');
    set(&t, 2, 2, 'x');
    set(&t, 3, 3, 'x');
    set(&t, 4, 4, 'x');
    set(&t, 5, 5, 'x');

    // test comptageBasDroite
    assertEquals(5u, comptageBasDroite(&t, 0, 0), "comptageBasDroite test");
    assertEquals(4u, comptageBasDroite(&t, 1, 1), "comptageBasDroite test");
    assertEquals(3u, comptageBasDroite(&t, 2, 2), "comptageBasDroite test");
    assertEquals(2u, comptageBasDroite(&t, 3, 3), "comptageBasDroite test");
    assertEquals(1u, comptageBasDroite(&t, 4, 4), "comptageBasDroite test");
    assertEquals(0u, comptageBasDroite(&t, 5, 5), "comptageBasDroite test");

    // test comptageHautGauche
 /*  assertEquals(5u, comptageHautGauche(&t, 5, 5), "comptageHautGauche test");
    assertEquals(4u, comptageHautGauche(&t, 4, 4), "comptageHautGauche test");
    assertEquals(3u, comptageHautGauche(&t, 3, 3), "comptageHautGauche test");
    assertEquals(2u, comptageHautGauche(&t, 2, 2), "comptageHautGauche test");
    assertEquals(1u, comptageHautGauche(&t, 1, 1), "comptageHautGauche test");
    assertEquals(0u, comptageHautGauche(&t, 0, 0), "comptageHautGauche test");    */

    // fait une diagonale d'en haut à droite à en bas à gauche 
    init(&t, 7, 6);

    set(&t, 6, 0, 'o');
    set(&t, 5, 1, 'o');
    set(&t, 4, 2, 'o');
    set(&t, 3, 3, 'o');
    set(&t, 2, 4, 'o');
    set(&t, 1, 5, 'o');

   // test comptageBasGauche
    assertEquals(5u, comptageBasGauche(&t, 6, 0), "comptageBasGauche test");
    assertEquals(4u, comptageBasGauche(&t, 5, 1), "comptageBasGauche test");
    assertEquals(3u, comptageBasGauche(&t, 4, 2), "comptageBasGauche test");
    assertEquals(2u, comptageBasGauche(&t, 3, 3), "comptageBasGauche test");
    assertEquals(1u, comptageBasGauche(&t, 2, 4), "comptageBasGauche test");
    assertEquals(0u, comptageBasGauche(&t, 1, 5), "comptageBasGauche test");

     // test comptageHautDroite
    assertEquals(0u, comptageHautDroite(&t, 6, 0), "comptageHautDroite test");
    assertEquals(1u, comptageHautDroite(&t, 5, 1), "comptageHautDroite test");
    assertEquals(2u, comptageHautDroite(&t, 4, 2), "comptageHautDroite test");
    assertEquals(3u, comptageHautDroite(&t, 3, 3), "comptageHautDroite test");
    assertEquals(4u, comptageHautDroite(&t, 2, 4), "comptageHautDroite test");
    assertEquals(5u, comptageHautDroite(&t, 1, 5), "comptageHautDroite test");

    // test QuatreAlignes
    assertEquals(1u, QuatreAlignes(&t, 4, 2), "QuatreAlignes test");
    assertEquals(1u, QuatreAlignes(&t, 3, 3), "QuatreAlignes test");
    assertEquals(1u, QuatreAlignes(&t, 3, 2), "QuatreAlignes test");
    assertEquals(1u, QuatreAlignes(&t, 6, 5), "QuatreAlignes test");
    assertTrue(QuatreAlignes(&t, 4, 2), "QuatreAlignes test");
    assertTrue(QuatreAlignes(&t, 3, 3), "QuatreAlignes test");
    assertTrue(QuatreAlignes(&t, 3, 2), "QuatreAlignes test");
    assertTrue(QuatreAlignes(&t, 6, 5), "QuatreAlignes test");

     faireCoup(&t, 1, 0);
     faireCoup(&t, 1, 0);
     faireCoup(&t, 1, 0);
     assertFalse(QuatreAlignes(&t, 0, 3), "QuatreAlignes test");
     faireCoup(&t, 1, 0);
     assertTrue(QuatreAlignes(&t, 0, 2), "QuatreAlignes test");

     init(&t, 7, 6);
     faireCoup(&t, 5, 5);
     faireCoup(&t, 4, 5);
     faireCoup(&t, 3, 5);
     faireCoup(&t, 2, 5);
     assertTrue(QuatreAlignes(&t, 2, 5), "QuatreAlignes test");


}

/*
int main() {

    testPuissance4();

    return 0;
}
*/
