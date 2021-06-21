#include "MancalaBoard.h"
#include "Simulate.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <string>

ValueMovePlayer maxValueSearch(MancalaBoard &board, int alpha, int beta, int depth) {
    // If we have reached the depth or the game is over, we return the board's utility
    if (depth == 0 || board.terminal()) {
        return ValueMovePlayer {board.util(), -1, -1};
    }
    int value = std::numeric_limits<int>::min(), choice = -1, nextPlayer = -1;
    std::vector<int> moves = board.actions(1);
    for (std::vector<int>::iterator it = moves.begin(); it != moves.end(); it++) {
        MancalaBoard nextMove(board);
        int nextToGo = nextMove.move(*it, 1);
        int value2, a2, p2;
        // Depending on which player is next, the appropriate search algorithm is called
        if (nextToGo == 1) {
            ValueMovePlayer stats = maxValueSearch(nextMove, alpha, beta, depth - 1);
            value2 = stats.value;
            a2 = stats.move;
            p2 = stats.player;
        }
        else {
            ValueMovePlayer stats = minValueSearch(nextMove, alpha, beta, depth - 1);
            value2 = stats.value;
            a2 = stats.move;
            p2 = stats.player;
        }

        if (value2 > value) {
            value = value2;
            choice = *it;
            nextPlayer = p2;
            alpha = std::max(alpha, value);
        }

        if (value >= beta) {
            return ValueMovePlayer {value, choice, nextPlayer};
        }
    }

    return ValueMovePlayer {value, choice, nextPlayer};
}

ValueMovePlayer minValueSearch(MancalaBoard &board, int alpha, int beta, int depth) {
    // If we have reached the depth or the game is over, we return the board's utility
    if (depth == 0 || board.terminal()) {
        return ValueMovePlayer {board.util(), -1, -1};
    }
    int value = std::numeric_limits<int>::max(), choice = -1, nextPlayer = -1;
    std::vector<int> moves = board.actions(2);
    for (std::vector<int>::iterator it = moves.begin(); it != moves.end(); it++) {
        MancalaBoard nextMove(board);
        int nextToGo = nextMove.move(*it, 1);
        int value2, a2, p2;
        // Depending on which player is next, the appropriate search algorithm is called
        if (nextToGo == 1) {
            ValueMovePlayer stats = maxValueSearch(nextMove, alpha, beta, depth - 1);
            value2 = stats.value;
            a2 = stats.move;
            p2 = stats.player;
        }
        else {
            ValueMovePlayer stats = minValueSearch(nextMove, alpha, beta, depth - 1);
            value2 = stats.value;
            a2 = stats.move;
            p2 = stats.player;
        }

        if (value2 < value) {
            value = value2;
            choice = *it;
            nextPlayer = p2;
            beta = std::min(beta, value);
        }

        if (value <= alpha) {
            return ValueMovePlayer {value, choice, nextPlayer};
        }
    }

    return ValueMovePlayer {value, choice, nextPlayer};
}

Results runGame (int nums[14], int player1Depth, int player2Depth, bool display) {
    MancalaBoard board(nums); // Create the Mancala Board from the int array
    if (display) {
        board.printBoard();
    }
    int player = 1;
    int turn = 0;
    while (!board.terminal()) {
        turn++;
        if (player == 1) {
            ValueMovePlayer vmp = maxValueSearch(board, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), player1Depth);
            player = board.move(vmp.move, 1);
            if (display) {
                std::cout << "Player 1\tChoice: " << vmp.move << "\tTurn: " << turn << std::endl;
                std::cout << "==========================================================" << std::endl;
                board.printBoard();
            }
        }
        else {
            ValueMovePlayer vmp = minValueSearch(board, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), player2Depth);
            player = board.move(vmp.move, 2);
            if (display) {
                std::cout << "Player 2\tChoice: " << vmp.move << "\tTurn: " << turn << std::endl;
                std::cout << "==========================================================" << std::endl;
                board.printBoard();
            }
        }
    }
    int score = board.util();
    int winner;
    std::string verdict;
    if (score > 0) {
        winner = 1;
        verdict = "Player 1 wins";
    }
    else if (score < 0) {
        winner = 2;
        verdict = "Player 2 wins";
    }
    else {
        winner = 0;
        verdict = "Tie";
    }

    if (display) {
        std::cout << verdict << std::endl;
    }
    return Results {board.player1Score(), board.player2Score(), winner};
}