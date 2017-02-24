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
 * @file init.c
 * @brief Ce fichier contient l'inatialisation 
 *        et declaration de toutes les variables
 *        global
 */

#include <stdio.h>
#include "init.h"

t_direction directions[8] = {
    {0, 1}, {0, -1},
    {-1, 0},{1, 0},
    {-1, 1},{1, 1},
    {-1,-1},{1,-1}
};

// tableau comportant les valeurs des cases
// pour l'alpha beta
int pos_val[8][8] = {
{500,   -150,   30, 10, 10, 30, -150, 500},
{-150, -250,    0,  0,  0,  0,  -250, -150},
{30,    0,      1,  2,  2,  1,  0,      30},
{10,    0,      2,  16, 16, 2,  0,      10},
{10,    0,      2,  16, 16, 2,  0,      10},
{30,    0,      1,  2,  2,  1,  0,      30},
{-150, -250,    0,  0,  0,  0, -250, -150},
{500, -150,     30, 10, 10, 30, -150, 500}};

void init_grid() {
    int i;
    int j;


    for(i = 0; i < GRIDSIZE; ++i) {
        for(j = 0; j < GRIDSIZE; ++j) {
            t_disk null_disk;
            null_disk.line = i;
            null_disk.column = j;
            null_disk.owner = '0';

            othello[i][j] = null_disk;
        }
    }

    othello[GRIDSIZE / 2 - 1][GRIDSIZE / 2 - 1].owner = 'W';
    othello[GRIDSIZE / 2 - 1][GRIDSIZE / 2].owner = 'B';
    othello[GRIDSIZE / 2][GRIDSIZE / 2 - 1].owner = 'B';
    othello[GRIDSIZE / 2][GRIDSIZE / 2].owner = 'W';
}

