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
 * @file score.h
 * @brief contient les fonctions
 *        les fonctions qui permettent la lecture, la suppression 
 *        et l'ecriture de l'historique dans un fichier
 */

#ifndef _UPDATESCORE_H_ 
#define _UPDATESCORE_H_

/* 
 * @brief : fonction qui ecrit les 
 *          scores dans le ainsi que le 
 *          gagnant dans le fichier   
 */
void write_score ();

/* 
 * @brief : fonction qui lit ce qui est
 *          ecrit dans le fichier de l'historique
 *          
 */
void read_score ();

/* 
 * @brief : fonction qui supprime le 
 *          contenue du fichier d'historique           
 */
void supprimer_score ();

/* 
 * @brief : fonction qui va sauvegarder dans un 
 *          fichier, le nom des joueurs ainsi que
 *          le joueur courant, puis dans un second
 *          fichier l othelier.           
 */
void write_save ();

/* 
 * @brief : fonction qui va permettre de restaurer
 *          une partie entre joueur, en outre elle 
 *          va chercher les nom des joueurs ainsi 
 *          que le joueur courant dans un fichier 
 *          et l'othelier dans un autre            
 */
void restore_save();
#endif