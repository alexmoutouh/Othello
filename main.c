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
 * @file main.c
 * @brief Point d'entre du programme 
 */
#include <stdio.h>
#include "handle.h"
#include "menu.h"
#include "score.h"

/*
 * @brief : c'est ici que l'utilisateur
 *          choisi ce quelles type de partie
 *          il veut faire, bien si il veut
 *          afficher/supprimer l'historique
 */
int main() {
    int difficulty;
    int difficulty2;
    int choice;

    do {
        choice = choose_mode();

        switch (choice) {
            case 1 :
                pvp();
                break;
            case 2 : 
                difficulty = choose_difficulty();
                pve(difficulty);
                break;
            case 3 : 
                difficulty = choose_difficulty();
                difficulty2 = choose_difficulty();
                eve(difficulty, difficulty2);
                break;
            case 4 :
                read_score();
                break;
            case 5 :
                supprimer_score();
                break;
            case 6 :
                save_game();
                break;
            default :
                choice = -1;
                break;
        }
    } while (choice >= 0);       

    printf("A bientot\n");

    return 0;
}
