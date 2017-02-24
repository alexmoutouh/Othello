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
 * @file init.h
 * @brief Ce fichier contient l'inatialisation 
 *        et declaration de toutes les variables
 *        global
 */
#ifndef _INITIATION_H_ 
#define _INITIATION_H_

#define GRIDSIZE 8
#define DEPTH 5
#define EASY 0
#define NORMAL 1
#define HARD 2

typedef struct direction {
    int x;
    int y;
} t_direction, *t_ptr_direction;

typedef struct disk {
    int line;
    int column;
    char owner;
} t_disk, *t_ptr_disk;

t_direction directions[8];
t_disk othello[GRIDSIZE][GRIDSIZE];
t_disk move_pos;

int pos_val[8][8];

char player1[50];
char player2[50];
char current_player;

/*
 * @brief fonction d'initialisation de l'othelier
 * 		  elle permet en outre de placer les 
 *   	  4 premier pions sur l'othelier
 *
 */
void init_grid();

#endif
