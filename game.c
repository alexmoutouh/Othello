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
 * @file game.c
 * @brief ce fichier contient toute les fonctions 
 *        concernant le traitement du jeu 
 */

#include <stdio.h>
#include <limits.h>
#include "init.h"
#include "display.h"
#include "game.h"

void ai_play(char player, int depth, int difficulty) {
    char curr_player_sav = current_player;
    int alpha;
    int beta;

    alpha = INT_MIN;
    beta = INT_MAX;

    t_disk useful_or_not;
    alphabeta(othello, player, depth, alpha, beta, difficulty, useful_or_not);

    current_player = curr_player_sav;
    move(othello, current_player, move_pos.line, move_pos.column, 1);
    printf("i%d j%d", move_pos.line, move_pos.column);
}

int alphabeta(t_disk grid[][GRIDSIZE], char player, int depth, int alpha, int beta, int difficulty, t_disk move_hard_mode) {
    if(end_game() || depth <= 0) {
        if(difficulty == HARD) {
            return get_pos_val(grid, move_hard_mode);
        } else if(difficulty == NORMAL) {
            return calc_score(grid, player);
        } else {
            return get_moves(grid);
        }
    }

    t_disk bestMove;                    // contiendra le meilleur coup a jouer
    t_disk copy[GRIDSIZE][GRIDSIZE];    // copie de l'othello, on y jouera le coup
    int i;
    int j;

    // cas IA : maximisation
    if(player == current_player) { 
        for(i = 0; i < GRIDSIZE; ++i) {
            for(j = 0; j < GRIDSIZE; ++j) {
                if(grid[i][j].owner == 'X') {
                    t_disk this_move;
                    this_move.line = i;
                    this_move.column = j;

                    copy_grid(grid, copy);
                    move(copy, current_player, i, j, 0); // coup possible joue

                    int score;
                    score = alphabeta(copy, player, depth - 1, 
                    alpha, beta, difficulty, this_move);

                    current_player = opposite_player(current_player);

                    // a partir de la difficulte normale, l'IA evite au mieux
                    // les zones sensibles autour des coins
                    if(depth == DEPTH && difficulty >= NORMAL && get_pos_val(grid, this_move) < 0) {
                        score = get_pos_val(grid, this_move);
                    }

                    if(score > alpha) {
                        alpha = score;
                        bestMove.line = i;
                        bestMove.column = j;

                        // une fois que la meilleure valeur est remontee jusqu'a
                        // la racine de l'arbre alpha-beta, le 1er coup qui
                        // permet d'y acceder, est assigne au mouvement a jouer par l'IA
                        if(depth == DEPTH) {
                            move_pos = bestMove;
                        }

                        if(alpha >= beta) {
                            break; 
                        }
                    }
                }
            }
        }

        return alpha ;
    // cas adversaire : minimisation
    } else {
        for(i = 0; i < GRIDSIZE; ++i) {
            for(j = 0; j < GRIDSIZE; ++j) {
                if(grid[i][j].owner == 'X') {
                    t_disk this_move;
                    this_move.line = i;
                    this_move.column = j;

                    copy_grid(grid, copy);
                    move(copy, current_player, i, j, 0); // coup possible joue

                    int score;
                    score = alphabeta(copy, player, depth - 1, 
                    alpha, beta, difficulty, this_move);

                    current_player = opposite_player(current_player);

                    if(score < beta) {
                        beta = score;

                        if(alpha >= beta) {
                            break; 
                        }
                    }
                }
            }
        }

        return beta;
    }
}

void copy_grid(t_disk grid[GRIDSIZE][GRIDSIZE], t_disk copy[GRIDSIZE][GRIDSIZE]) {
    int i;
    int j;

    for(i = 0; i < GRIDSIZE; ++i) {
        for(j = 0; j < GRIDSIZE; ++j) {
            copy[i][j] = grid[i][j];
        }
    }
}

void reset_playable(t_disk grid[GRIDSIZE][GRIDSIZE]) {
    int i;
    int j;

    for(i = 0; i < GRIDSIZE; ++i) {
        for(j = 0; j < GRIDSIZE; ++j) {
            if(grid[i][j].owner == 'X') {
                grid[i][j].owner = '0';
            }
        }
    }
}

void direction_test(t_disk grid[GRIDSIZE][GRIDSIZE], int li, int co, char player, t_direction direction) {
    if(player != '0') {
        int playable = 0;
        char opponent = opposite_player(player);
        int i = li + direction.x;
        int j = co + direction.y;

        while(0 <= i && i < GRIDSIZE && 0 <= j && j < GRIDSIZE &&
                grid[i][j].owner == opponent && !playable) {

            i += direction.x;
            j += direction.y;

            // des qu'on tombe sur une case vide c'est une case jouable
            if(0 <= i && i < GRIDSIZE && 0 <= j && j < GRIDSIZE && grid[i][j].owner == '0') {
                playable = 1;
                grid[i][j].owner = 'X';
            }
        }
    }
}

void maj_playable(t_disk grid[GRIDSIZE][GRIDSIZE], char player) {
    int li;
    int col;
    int i;

    for(li = 0; li < GRIDSIZE; ++li) {
        for(col = 0; col < GRIDSIZE; ++col) {
            if(grid[li][col].owner == current_player) {
                for(i = 0; i < 8; ++i) {
                    direction_test(grid, li, col, player, directions[i]);
                }
            }
        }
    }
}

void flip(t_disk grid[GRIDSIZE][GRIDSIZE], int li, int col, t_direction direction, char player) {

    /* on se deplace dans la meme direction
     * tant que l'on rencontre un pion adverse
     */
    do {
        li += direction.x;
        col += direction.y;
        player = grid[li][col].owner;
    } while(player == opposite_player(current_player));


    if(grid[li][col].owner == current_player && (li >= 0 && li <= GRIDSIZE-1 && col >= 0 && col <= GRIDSIZE - 1)) {
        /* on parcours l'othellier dans le sens 
         * inverse et on retourne au passage les 
         * pions adverses 
         */
        do {
            grid[li][col].owner = current_player;
            li -= direction.x;
            col -= direction.y;
            player = grid[li][col].owner;
        } while (player != current_player);
    }
}

void capture(t_disk grid[GRIDSIZE][GRIDSIZE], char player, int li, int col) {
    int i;

    for(i = 0; i < 8; ++i) {
        if(grid[li + directions[i].x][col+directions[i].y].owner == opposite_player(player)) {
            flip(grid, li, col, directions[i], opposite_player(player));
        }
    }
}

void move(t_disk grid[GRIDSIZE][GRIDSIZE], char player, int li, int col, int v) {
    grid[li][col].owner = player;
    capture(grid, player, li, col);
    next_turn(grid, v);
}

void help(char player) {
    char curr_player_sav = current_player;
    int alpha;
    int beta;

    alpha = INT_MIN;
    beta = INT_MAX;

    t_disk useful_or_not;
    alphabeta(othello, player, DEPTH, alpha, beta, HARD, useful_or_not);

    current_player = curr_player_sav;
    printf(" Mouvement conseille : i = %d j = %d \n", move_pos.line, move_pos.column);
}

int input_move(t_disk grid[GRIDSIZE][GRIDSIZE], char player) {
    unsigned li, col;
    int valid = 0;
    int abandonne = 0;
    printf ("Entrez le numero de ligne");
    printf("\n - 10 pour l'aide\n - 11 pour abandonner \n");
    printf("- 12 pour sauvegarder (si vous etes contre l'IA equivalent a abandonner\n");
    
    do {
        scanf("%d", &li);
        
        if(li  == 10) { // si le joueur choisi l'aide 
            help(current_player);
            scanf("%d", &li);
        } else if(li  == 11) { // si le joueur choisi d'abandonner 
            abandonne = 1;
            valid = 1;
        }
        else if(li == 12){
            abandonne = 2;
            valid = 1;
        }

        if(!abandonne) {
            printf ("Entrer le numero de colonne \n");
            scanf("%d", &col);
            
            if (col < GRIDSIZE && col >= 0 && li >= 0 && li < GRIDSIZE) {
                if(grid[li][col].owner == 'X') {
                    move(grid, player, li, col, 1);
                    valid = 1;
                } else {
                    valid = 0;
                    printf("Le coup n'est pas valide veuillez saisir de nouveau !\n");
                }
            } else {
                valid = 0;
                printf("Le coup n'est pas valide veuillez saisir de nouveau !\n");
            }
        }
    } while(!valid);
    return abandonne;
}

int calc_score(t_disk grid[GRIDSIZE][GRIDSIZE], char player) {
    int score = 0;
    int i;
    int j;

    for(i = 0; i < GRIDSIZE; ++i) {
        for(j = 0; j < GRIDSIZE; ++j) {
            if(grid[i][j].owner == player) {
                ++score;
            }
        }
    }

    return score;
}

int get_pos_val(t_disk grid[GRIDSIZE][GRIDSIZE], t_disk pos) {
    return pos_val[pos.line][pos.column];
}


int get_moves(t_disk grid[GRIDSIZE][GRIDSIZE]) {
    int i;
    int j;
    int cpt;

    for(i = 0; i < GRIDSIZE; ++i) {
        for(j = 0; j < GRIDSIZE; ++j) {
            if(grid[i][j].owner == 'X') {
                ++cpt;
            }
        }
    }

    return cpt;
}

int can_play(t_disk grid[GRIDSIZE][GRIDSIZE]) {
    int i;
    int j;
    int end = 0;

    for(i = 0; i < GRIDSIZE && end == 0; ++i) {
        for(j = 0; j < GRIDSIZE && end == 0; ++j) {
            if(grid[i][j].owner == 'X') {
                end = 1;
            }
        }
    }

    return end;
}

char opposite_player(char player) {
    if(player == 'W') {
        return 'B';
    } else if(player == 'B') {
        return 'W';
    } else {
        return '0';
    }
}

void next_turn(t_disk grid[GRIDSIZE][GRIDSIZE], int v) {
    current_player = opposite_player(current_player);
    reset_playable(grid);
    maj_playable(grid, current_player);

    if (!can_play(grid)) {
        if(v) {
            printf("Pass!\n");
        }
    
        current_player = opposite_player(current_player);
        reset_playable(grid);
        maj_playable(grid, current_player);
       
        if (!can_play(grid)) {
            if(v) {
                printf("And done!\n");
            }

            current_player = '0';
        }
    }
}

int end_game() {
    if(current_player == '0') {
        return 1;
    } else {
        return 0;
    }
}

int winner(int v) {
    int scoreW = calc_score(othello, 'W');
    int scoreB = calc_score(othello, 'B');
 
    if(scoreW > scoreB) {
        if(v) {
            printf("victoire W\n" );
        }

        return scoreW;
    } else if(scoreW < scoreB) {
        if(v) {
            printf("victoire B\n" );
        }

        return scoreB;
    } else{
        if(v) {
            printf("egalite\n" );
        }

        return 0;
    }
}

