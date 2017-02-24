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
 * @file handle.h
 * @brief ce fichier contient les fonctions 
 *        qui gere le deroulement des parties 
 * 
 */

#ifndef _HANDLE_H_ 
#define _HANDLE_H_

/*
 * @brief : 		    cette fonction gere les partie 
 *          		    joueur contre joueur, en demandant 
 *          		    dans un premier temps de rentrer 
 *          		    les pseudos.
 */
void pvp();

/*
 * @brief :             cette fonction gere les partie 
 *                      joueur contre IA, en demandant 
 *          		    dans un premier temps si le joueur veux commencer
 *          		    puis  dans un second temps de rentrer 
 *          		    son pseudos.
 * @param diffuculty :  difficulte de l'ia 
 * 
 */
void pve(int difficulty);
/*
 * @brief : 		    cette fonction gere les partie 
 *          		    IA contre IA, en demandant 
 *          		    dans un premier temps quelle IA commence
 * @param diffuculty1 : difficulte de l'ia 1
 * @param diffuculty2 : difficulte de l'ia 2 
 * 
 */
void eve(int difficulty1, int difficulty2);

/*
 * @brief : cette fonction gere la restauration 
 *          de sauvegarde d une partie, ne marche que  
 *          pour le mode joueur contre joueur
 */
void save_game();
#endif
