#ifndef SIMULATE_H
#define SIMULATE_H

#include "MancalaBoard.h"
#include <iostream>
#include <limits>
#include <algorithm>

/*
    This struct holds the value a board gives a player, the next move that should be taken,
    and the next player to go. This struct is used in the minimax algorithm to keep track
    of the best move. 
*/
struct ValueMovePlayer {
    int value;
    int move;
    int player;
};

/*
    This struct is returned after a simulation of the game, and will return some information
    that could be used for further analysis.
*/
struct Results {
    int player1Score;
    int player2Score;
    int winner;
};

// The maximizing agent in the minimax algorithm (in this case is player 1)
ValueMovePlayer maxValueSearch(MancalaBoard &board, int alpha, int beta, int depth);

// The minimizing agent in the minimax algorithm (in this case is player 2)
ValueMovePlayer minValueSearch(MancalaBoard &board, int alpha, int beta, int depth);

// Allows you to run a Mancala game and choose starting board, each player's depth, 
// and if you want results to be printed.
Results runGame (int nums[14], int player1Depth, int player2Depth, bool display);

#endif