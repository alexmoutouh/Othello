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
 * @file menu.c
 * @brief fichier qui contient l'affichage du menu
 *        et des difficultes
 */

#include <stdio.h>
#include <stdlib.h>

int choose_difficulty(){
	int choice;
	printf("Choisissez le mode de difficulté :\n");
	printf("0 : Facile\n");
	printf("1 : Normal\n");
	printf("2 : Difficile\n");

	scanf("%d", &choice);

    if(choice < 0 || 2 < choice) {
	    return 0;
    } else {
        return choice;
    }
}

int choose_mode(){
    int choice;

    printf("Menu :\n");
    printf("1 : Joueur contre Joueur \n");
    printf("2 : Joueur contre IA \n");
    printf("3 : IA contre IA\n");
    printf("4 : Afficher historique\n");
    printf("5 : Supprimer historique\n");
    printf("6 : Restaurer une partie sauvegarde\n");

    printf("Autre pour sortir \n");

    scanf("%d", &choice);
    return choice;
}
