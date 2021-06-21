#include "MancalaBoard.h"
#include <iostream>
#include <vector>

MancalaBoard::MancalaBoard(int temp[14]) {
    for (int i = 0; i < 14; i++) {
        board[i] = temp[i];
    }
}

MancalaBoard::MancalaBoard(const MancalaBoard &m) {
    for (int i = 0; i < 14; i++) {
        board[i] = m.board[i]; // Copies the old board's values into the new board
    }
}

int MancalaBoard::boardSum(int left, int right) {
    int sum = 0;
    for(int i = left; i < right; i++) {
        sum += board[i];
    }
    return sum;
}

int MancalaBoard::util() {
    return board[6] - board[13]; // Player 1 pieces minus number of pieces for player 2
}

bool MancalaBoard::terminal() {
    return boardSum(0,6) + boardSum(7,13) == 0;
}

int MancalaBoard::movePlayer1(int action) {
    int numPieces = board[action];
    int index = action + 1;
    board[action] = 0;
    while (numPieces > 0) {
        if (index == 13) {
            index = 0;
        }
        else {
            board[index] += 1;
            index++;
            numPieces--;
        }
    }
    return index - 1; // Return the index of the last piece placed
}

int MancalaBoard::movePlayer2(int action) {
    int numPieces = board[action];
    int index = action + 1;
    board[action] = 0;
    while (numPieces > 0) {
        if (index == 14) {
            index = 0;
        }
        else if (index == 6) {
            index = 7;
        }
        else {
            board[index] += 1;
            index++;
            numPieces--;
        }
    }
    return index - 1;
}

void MancalaBoard::capture(int lastIndex, int player) {
    if (player == 1 && lastIndex >= 0 && lastIndex <= 5 && board[12 - lastIndex] > 0) {
        board[6] += (board[12 - lastIndex] + 1);
        board[lastIndex] = 0;
        board[12 - lastIndex] = 0;
    }
    else if (player == 2 && lastIndex >= 7 && lastIndex <= 12 && board[12 - lastIndex] > 0) {
        board[13] += (board[12 - lastIndex] + 1);
        board[lastIndex] = 0;
        board[12 - lastIndex] = 0;
    }
}

int MancalaBoard::move(int action, int player) {
    int lastIndex;
    if (player == 1) {
        lastIndex = movePlayer1(action);
    }
    else {
        lastIndex = movePlayer2(action);
    }

    // Checks if pieces need to be captured
    if (board[lastIndex] == 1) {
        capture(lastIndex, player);
    }

    // Check if player 1 side is empty
    if (boardSum(0,6) == 0) {
        int total = 0;
        for (int i = 7; i < 13; i++) {
            total += board[i];
            board[i] = 0;
        }
        board[13] += total;
    }
    // Check if player 2 side is empty
    else if (boardSum(7,13) == 0) {
        int total = 0;
        for (int i = 0; i < 6; i++) {
            total += board[i];
            board[i] = 0;
        }
        board[6] += total;
    }

    if (lastIndex == 6 && player == 1) {
        return 1;
    }
    else if (lastIndex == 13 && player == 2) {
        return 2;
    }
    else {
        return -1 * player + 3;
    }
}

std::vector<int> MancalaBoard::actions(int player) {
    std::vector<int> v;
    if (player == 1) {
        for (int i = 0; i < 6; i++) {
            if (board[i] > 0) {
                v.push_back(i);
            }
        }
    }
    else {
        for (int i = 7; i < 13; i++) {
            if (board[i] > 0) {
                v.push_back(i);
            }
        }
    }
    return v;
}

int MancalaBoard::player1Score() {
    return board[6];
}

int MancalaBoard::player2Score() {
    return board[13];
}

void MancalaBoard::printBoard() {
    std::cout << '\t';
    for (int i = 12; i > 6; i--) {
        std::cout << board[i] << '\t';
    }
    std::cout << "" << std::endl;
    std::cout << board[13] << "\t\t\t\t\t\t\t" << board[6] << std::endl;
    std::cout << '\t';
    for (int i = 0; i < 6; i++) {
        std::cout << board[i] << '\t';
    }
    std::cout << "" << std::endl;
}