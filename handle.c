/* 
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 * 
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 * */ 

/*
 * @author MARIE    Julien      <julien.marie@etu.univ-amu.fr>
 * @author MOUTOUH  Alexandre   <alexandre.moutouh2@etu.univ-amu.fr>
 * 
 * @version 0.1.0
 * */

/**
 * @file handle.c
 * @brief ce fichier contient les fonctions 
 *        qui gere le deroulement des parties 
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "handle.h"
#include "init.h"
#include "display.h"
#include "game.h"
#include "score.h"


void pvp() {
    int abandonne = 0;
    printf("Enter pseudo Player  1 : \n\n");
    scanf ("%s", player1);
    current_player = 'B';
    printf("Enter pseudo Player  2 : \n\n");
    scanf ("%s", player2);
    printf("/**************************/\n\n");

    init_grid();
    maj_playable(othello, current_player);

    do {
        printf("\033[H\033[2J"); // clearscreen
        printf("C'est le tour des : %c \n", current_player);
        printf("\n");

        printf("\n");

        display_score();
        display_grid(othello);

        abandonne = input_move(othello, current_player);

    } while(!end_game() && !abandonne);

    printf("\033[H\033[2J"); // clearscreen
    if (abandonne == 1)
        printf("le joueur : %c à abandonne \n", current_player);
     else if(abandonne == 2)
        write_save ();
    else{
        display_score();
        display_grid(othello);
        winner(1);
        write_score();
           
    }   

}


void pve(int difficulty) {
    int choice;
    char human_p;
    int abandonne = 0;
    printf("Voulez vous commencez ? : 1 - Oui | 0 - Non \n");
    scanf("%d", &choice);
    printf("Entrez votre pseudo \n");

    if(!choice) {
        scanf("%s", player2);
        strcpy(player1, "IA");
        human_p = 'W';
    } else {
        scanf("%s", player1);
        strcpy(player2, "IA");
        human_p = 'B';    
    }
    
    printf ("%s", player1);

    current_player = 'B';
    printf("/**************************/\n\n");

    init_grid();
    maj_playable(othello, current_player);

    do {
        printf("\033[H\033[2J"); // clearscreen
        printf("C'est le tour des : %c \n", current_player);
        printf("\n");
        printf("\n");
        display_score();
        display_grid(othello);
        sleep(2);

        if(current_player == human_p) {
            abandonne = input_move(othello, current_player);
        } else {
            ai_play(current_player, DEPTH, difficulty);
        }
    } while(!end_game() && !abandonne);

    printf("\033[H\033[2J"); // clearscreen
    if (abandonne)
        printf("le joueur : %c a abandonne \n", current_player);
    else{
        display_score();
        display_grid(othello);
        winner(1);
        write_score();           
    }   
}


void eve(int difficulty1, int difficulty2) {
    int choice;
    char IA1;
    char next;
    printf("Qui commence ? : 1 - IA 1 | 0 - IA 2 \n");
    scanf("%d", &choice);

    if(!choice) {
        strcpy(player1, "IA 2");
        strcpy(player2, "IA 1");
        IA1 = 'W';
    } else {
        strcpy(player1, "IA 1");
        strcpy(player2, "IA 2");    
        IA1 = 'B';
    }
    
    printf ("%s", player1);

    current_player = 'B';
    printf("/**************************/\n\n");

    init_grid();
    maj_playable(othello, current_player);
    printf ("Entrez un touche pour suivant et q pour quitter");
    scanf ("%c",&next);

    do {
        printf("\033[H\033[2J"); // clearscreen
        printf("C'est le tour des : %c \n", current_player);
        printf("\n");
        printf("\n");
        display_score();
        display_grid(othello);
        //sleep(5);
        printf ("Entrez un touche pour suivant et q pour quitter");
        scanf ("%c",&next);
        if(current_player == IA1) {
            ai_play(current_player, DEPTH, difficulty1);
        } else {
            ai_play(current_player, DEPTH, difficulty2);
        }
    } while(!end_game() && next != 'q');

    printf("\033[H\033[2J"); // clearscreen
    display_score();
    display_grid(othello);
    winner(1);
}

void save_game() {
    int abandonne = 0;

    printf("/**************************/\n\n");
    restore_save ();
    maj_playable(othello, current_player);

    do {
        printf("\033[H\033[2J"); // clearscreen
        printf("C'est le tour des : %c \n", current_player);
        printf("\n");

        printf("\n");

        display_score();
        display_grid(othello);

        abandonne = input_move(othello, current_player);

    } while(!end_game() && !abandonne);

    printf("\033[H\033[2J"); // clearscreen
    if (abandonne == 1)
        printf("le joueur : %c à abandonne \n", current_player);
    else if(abandonne == 2)
        write_save ();

    else{
        display_score();
        display_grid(othello);
        winner(1);
        write_score();
           
    }   
}