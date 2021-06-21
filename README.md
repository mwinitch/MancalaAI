# Mancala AI

This project allows a user to run Mancala games with two AI players. The decision making algorithm used is the [Minimax algorithm](https://en.wikipedia.org/wiki/Minimax#Minimax_algorithm_with_alternate_moves) with [Alpha-beta pruning](https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning) for optimization. The header file `Simulate.h` has the headers for the minimax algorithm. The algorithm is broken up into two functions, `maxValueSearch` and `minValueSearch` for the maximizing and minimizing agent respectively. To actually run the game you can call the `runGame` function, which is also in the `Simulate.h` header file.

The Mancala board is a class whose header file is `MancalaBoard.h`. The class has all the functions needed to make moves along with functions used by the minixmax algorithm, such as `util` to get the current utility of a board. The actual underlying board used in the `MancalaBoard` class is just an array of size 14:

`int board[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};`

Below is how the array becomes the Mancala board. Take note that index 6 and index 13 become the store (the place where each player collects their stones) for player 1 and player 2's stones respectively. 
~~~
    12  11  10  9   8   7
13                          6
    0   1   2   3   4   5
~~~

Player 1's half of the board is array positions 0 - 6 while player 2's part of the board is array positions 7 - 13. The `main` function is `main.cpp` is where you can actually write and run simulations. The funtion currently is set up to run a standard Mancala gain with both players. To run the program type `make` in the command line and then type `./main`. To remove the `*.o` files just type `make clean` in your command line.