#include <iostream>
#include "MancalaBoard.h"
#include "Simulate.h"

// The main function is where we can run our simulations of the game
int main() {
    std::cout << "Starting simulation . . ." << std::endl;
    int nums[] = {4,4,4,4,4,4,0,4,4,4,4,4,4,0};
    Results r = runGame(nums, 7, 7, true);
    std::cout << "Results returned from the game:" << std::endl;
    std::cout << "Player 1 score: " << r.player1Score << std::endl;
    std::cout << "Player 2 score: " << r.player2Score << std::endl;
    std::cout << "Winner: " << r.winner << std::endl;
    return 0;
}