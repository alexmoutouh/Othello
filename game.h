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
 * @version 0.7.5
 * */

/**
 * @file game.h
 * @brief ce fichier contient toute les fonctions 
 *        concernant le traitement du jeu 
 */


#ifndef _GAME_H_ 
#define _GAME_H_

/* @brief           fonction qui fait jouer l'IA lors de son tour. Appelante de
 *                  l'alphabeta
 *
 * @param player    la couleur jouee par l'IA
 * @param depth     profondeur de l'arbre alpha-beta lors de l'appel de sa
 *                  fonction
 * @param difficulty    difficulte de l'IA. Parametre pour l'alphabeta
 * */
void ai_play(char player, int depth, int difficulty);


/* @brief           alpha-beta calculant le meilleur coup possible.
 *
 * @param grid[][]  othellier sur lequel travailler (peut etre l'othellier ou
 *                  une copie fictive utilisee lors de calculs
 * @param player    joueur pour qui calculer le coup
 * @param depth     profondeur de l'arbre alpha-beta (traduit le nombre de coups
 *                  a anticiper)
 * @param alpha     borne alpha
 * @param beta      borne beta
 * @param difficulty        strategie a adopter pour la recherche du coup (traduit la
 *                          difficutee de l'IA). Selon sa valeur la fonction appelee
 *                          lors de la condition de sortie est differente
 * @param move_hard_mode    parametre utilise que pour le mode difficile. Le
 *                          coup y est enregistre pour pouvoir appeler get_pos_val
 *
 * @return          renvoie la valeur du coup choisi
 * */
int alphabeta(t_disk grid[][GRIDSIZE], char player, int depth, int alpha, int beta, int difficulty, t_disk move_hard_mode);

/* @brief           fonction qui copie une grille dans copy qui sera utilisee
 *                  dans l'alphabeta lors de chaque descente le long d'une branche.
 *
 * @param grid[][]  grille a copier. Contiendra essentiellement, l'othellier ou
 *                  une de ses copies.
 * @param copy[][]  copie de la grille. Contiendra effectivement la copie a la
 *                  sortie de la fonction
 * */
void copy_grid(t_disk grid[GRIDSIZE][GRIDSIZE], t_disk copy[GRIDSIZE][GRIDSIZE]);


/*
 * @brief :             reinitialise la grille des mouvements possibles du 
 *                      joueur courant
 * @param grid[][] :    othellier
 */
void reset_playable(t_disk grid[GRIDSIZE][GRIDSIZE]);


/*
 * @brief :             cette fonction permet de connaitre les mouvements jouables
 *                      pour le joueur courant en fonction d'une position deja
 *                      occupee par un de ses pions
 * @param grid [][] :   othellier
 * @param li :          numero de ligne
 * @param co :          numero de colonne
 * @param player :      joueur courant
 * @param direction :   direction a tester vers laquelle tester
 */
void direction_test(t_disk grid[GRIDSIZE][GRIDSIZE], int li, int co, char player, t_direction direction);


/*
 * @brief :             met a jour les differentes positions jouables sur l'othellier
 * @param grid [][] :   othellier
 * @param player :      joueur courant
 */
void maj_playable(t_disk grid[GRIDSIZE][GRIDSIZE], char player);


/*
 * @brief :             fonction qui va realiser les retournements de pions
 * @param grid [][] :   othellier
 * @param li :          numero de ligne de la position ou le coup a ete joue
 * @param co :          numero de sa colonne
 * @param player :      joueur courant
 * @param direction :   direction dans laquelle retourner
 */
void flip(t_disk grid[GRIDSIZE][GRIDSIZE], int li, int col, t_direction direction, char player);


/*
 * @brief :             fonction qui effectue tous les retournements valides
 *                      lorsqu'un coup a ete joue
 * @param grid [][] :   othellier
 * @param player :      joueur courant
 * @param li :          numero de ligne du coup joue
 * @param co :          numero de colonne du coup joue
 */
void capture(t_disk grid[GRIDSIZE][GRIDSIZE], char player, int li, int col);


/*
 * @brief :             effectue l'ajout du nouveau pion, appelle la fonction 
 *                      de capture et effectue le changement de tour
 * @param grid [][] :   othellier
 * @param player :      joueur courant
 * @param li :          numero de ligne
 * @param co :          numero de colonne
 * @param v :           activation ou non du mode verbeux (afficher diverses 
 *                      informations telles que l'indication de passage de tour)
 */
void move(t_disk grid[GRIDSIZE][GRIDSIZE], char player, int li, int col, int v);


/*
 * @brief :         fonction qui utilise l'alpha beta afin de donnee au joueur 
 *                  une aide pour jouer son prochain coup
 * @param player :      joueur courant
 */
void help(char player) ;


/*
 * @brief :             demande au joueur de saisir son coup et le joue s'il est
 *                      valide
 * @param grid [][] :   othellier
 * @param player :      joueur courant
 * @return              booleen qui indique si le joueur a abandonne ou pas
 */
int input_move(t_disk grid[GRIDSIZE][GRIDSIZE], char player);


/*
 * @brief :     parcours l'othellier pour calculer le score du joueur. Utilisee
 *              aussi en tant que fonction d'evaluation dans l'alphabeta
 * @param grid [][] :   othellier
 * @param player :      joueur 
 * @return :            score du joueur
 */
int calc_score(t_disk grid[GRIDSIZE][GRIDSIZE], char player);


/*
 * @brief :             renvoie le poids, en terme d'interet strategique, de la
 *                      case passee en parametre. Utilisee comme fonction d'evaluation 
 *                      par l'alphabeta
 * @param grid[][] :    othellier
 * @param pos :         case a evaluer
 * @return              poids de la case
 */
int get_pos_val(t_disk grid[GRIDSIZE][GRIDSIZE], t_disk pos);


/*
 * @brief :             renvoie le nombre de coups possibles pour le joueur
 *                      courant. Utilisee comme fonction d'evaluation par l'alphabeta
 * @param grid[][] :    othellier
 * @return              nombre de coups possibles
 */
int get_moves(t_disk grid[GRIDSIZE][GRIDSIZE]);


/*
 * @brief :         indique s'il est possible de jouer des coups au moment de
 *                  l'appel de la fonction
 * @param grid :    grille sur laquelle effectuer la verification
 * @return          1 si vrai, 0 sinon
 */
int can_play(t_disk grid[GRIDSIZE][GRIDSIZE]);


/*
 * @brief :         retourne le caractere de l'adversaire
 * @param player :  joueur 
 * @return :        joueur adverse
 */
char opposite_player(char player);


/*
 * @brief :         passe au tour suivant et change le joueur courant
 * @param player :  othellier
 * @param v :       mode verbeux (passage de tour, fin de partie)
 */
void next_turn(t_disk grid[GRIDSIZE][GRIDSIZE], int v);


/*
 * @brief :         Indique si la partie est terminee ou pas
 */
int end_game();


/*
 * @brief :         Donne le vainqueur de la partie
 * @param v :       mode verbeux
 * @return :        retourne le score du vainqueur
 */
int winner(int v);

#endif
