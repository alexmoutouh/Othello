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
 * @file display.h
 * @brief ce fichier contient toutes 
 * les fonctions effectuant un affichage
 */
#ifndef _DISPLAY_H_ 
#define _DISPLAY_H_


/* 
 * @brief : 			     Cette fonction affiche l'othellier
 *            				 en attribuant des couleurs aux 
 *            				 différents pions
 * @param Grid[][GRIDSIZE] : l'othellier
 */
void display_grid(t_disk Grid[][GRIDSIZE]);

/*
 * @brief : cette fonction afffichera 
 *          simplement le score des 2 joueurs
 */
void display_score();

#endif
