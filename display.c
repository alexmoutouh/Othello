/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author MARIE    Julien      <julien.marie@etu.univ-amu.fr>
 * @author MOUTOUH  Alexandre   <alexandre.moutouh2@etu.univ-amu.fr>
 *
 * @version 0.0.1 
 */

/**
 * @file display.c
 * @brief ce fichier contient toutes 
 * les fonctions effectuant un affichage
 */

#include <stdio.h>
#include "init.h"
#include "display.h"
#include "game.h"


void display_grid(t_disk Grid[][GRIDSIZE]) {
    unsigned i;
    unsigned j;

    printf("\t");

    for (i = 0; i < GRIDSIZE; ++i) {
        printf("%d ", i);
    } // affichage des coordonnées

    printf("\n\n");

    // parcours de l'othellier case par case
    for (i = 0; i < GRIDSIZE; ++i) {
        printf("%d\t", i);

        for (j = 0; j < GRIDSIZE; ++j) {
            if(Grid[i][j].owner == 'B') {
	            printf("\033[31m");
            } else if(Grid[i][j].owner == 'W') {
	            printf("\033[34m");
            }

            printf("%c ", Grid[i][j].owner);

            printf("\033[0m");
        }

        printf("\n\n");
    }  
}


void display_score() {
    int scoreW = calc_score(othello, 'W');
    int scoreB = calc_score(othello, 'B');
    printf("Score %s W : %d ------------------- Score %s B : %d \n", player2, scoreW, player1, scoreB);
}
