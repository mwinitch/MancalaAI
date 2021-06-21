#ifndef MANCALABOARD_H
#define MANCALABOARD_H
#include <iostream>
#include <vector>

/*
    This class represents the Mancala board that is used in the simulations. The
    board is represented as an array with index 6 and index 13 representing the
    pits for player 1 and 2 respectively. 
*/
class MancalaBoard {
private:
    // This array is the underlying representation of the board
    int board[14];

    // Used to get a sum of a subset of the board
    int boardSum(int left, int right);
    
    // Helper method for player one's turn
    int movePlayer1(int action);
    
    // Helper method for player two's turn
    int movePlayer2(int action);
    
    // Handles the capturing rules of the game
    void capture(int lastIndex, int player);
public:
    
    // Constructor that takes in an integer array
    MancalaBoard(int temp[14]);
    
    // Copy constructor
    MancalaBoard(const MancalaBoard &m);

    // Calculates the utility of the board for the minimax algorithm
    int util();
    
    // Return true if the game is finished
    bool terminal();

     // Takes a move on the board given an action and the current 
    int move(int action, int player);
    
    // Returns a vector representing the possible moves a player can make
    std::vector<int> actions(int player);
    
    // Return's player one's score
    int player1Score();
    
    // Return player two's score
    int player2Score();
    
    // Function to display the board
    void printBoard();
};

#endif