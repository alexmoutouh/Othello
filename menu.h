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
 * @file menu.h
 * @brief fichier qui contient l'affichage du menu
 *        et des difficultes
 */


#ifndef _MENU_H_ 
#define _MENU_H_

/*
 * @return : retourne la difficulte choisie
 * @brief  : demande à l'utilisateur d'entrer
 *           la diffilculte de l'ia
 */
int choose_difficulty();

/*
 * @return : le choix de l'utilisateur
 * @brief  : demande a l'utilisateur 
 *           ce qu'il veut comme mode
 */
int choose_mode();

#endif
