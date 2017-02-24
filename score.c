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
 * @file score.c
 * @brief contient les fonctions
 *        les fonctions qui permettent la lecture, la suppression 
 *        et l'ecriture de l'historique dans un fichier
 */

#include <stdio.h>
#include <string.h>
#include "init.h"
#include "game.h"


void write_score (){
	int scoreW = calc_score(othello, 'W');
    int scoreB = calc_score(othello, 'B');
	FILE * fic = fopen("grid_score.txt", "a"); // ecrit sans ecraser
	fprintf(fic, "*************************************\n");
	fprintf(fic,  "Player 1 : %s score : %d \n", player1, scoreB);
	fprintf(fic,  "Player 2 : %s score : %d \n", player2, scoreW);
	if (scoreB > scoreW)
		fprintf(fic,  "Gagnant : %s \n", player1);
	else if (scoreB < scoreW)
		fprintf(fic,  "Gagnant : %s \n", player2);
	else 
		fprintf(fic,  "Gagnant : égalité\n");
	fprintf(fic, "*************************************\n");
	fclose (fic);
}


void read_score (){
	FILE * fic = fopen("grid_score.txt", "r");
	
	char chaine [10] ="";
	while (fgets (chaine, 10, fic) != NULL)
		printf ("%s", chaine);
	fclose (fic);
}


void supprimer_score (){
	FILE * fic = fopen("grid_score.txt", "w");
	fclose(fic); 
}

void restore_save(){
	FILE * fic = fopen("player.txt", "r");
	FILE * fic2 = fopen("othellier.txt", "r");	
	int i;
    int j;
    int cpt = 0;

    // récupération/restauration des nom de joueur et du joueur courant
	fscanf(fic, "%s %s %c", player1, player2, &current_player);
	
	char chaine [64] ="";
	char othellier [64] ="";
	// récupération de l'othelier 
	while (fgets (chaine, 64, fic2) != NULL){		
		strcat(othellier, chaine);
	}
	// restauration de l'othelier
    for(i = 0; i < GRIDSIZE; ++i) {
        for(j = 0; j < GRIDSIZE; ++j) {
            t_disk null_disk;
            null_disk.line = i;
            null_disk.column = j;
            null_disk.owner = othellier[cpt];

            othello[i][j] = null_disk;
            cpt++;
        }
    }
    fclose (fic);
    fclose (fic2);
}

void write_save (){
	FILE * fic = fopen("player.txt", "w");
	FILE * fic2 = fopen("othellier.txt", "w");	
	int i, j;
	// sauvegarde des noms de joueurs ainsi que le joueur courant
	fprintf(fic,  "%s %s %c", player1, player2, current_player);
	// sauvegarde de l'othelier
	for (i = 0; i < GRIDSIZE; ++i){
		for (j = 0; j < GRIDSIZE; ++j){
			fprintf(fic2,  "%c", othello[i][j].owner);
		}
	}
	fclose (fic);
	fclose (fic2);
}