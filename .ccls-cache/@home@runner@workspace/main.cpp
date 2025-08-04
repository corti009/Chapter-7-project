#include <iostream>
#include <vector>
#include <string>
#include <limits>


void displayBoard(const std::vector<char>& board);

int getPlayerChoice(int player, const std::vector<char>& board);

void updateBoard(std::vector<char>& board, int choice, char playerMarker);

bool checkWinner(const std::vector<char>& board, char playerMarker);

bool checkDraw(const std::vector<char>& board);

int main() {
    std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int turn = 1;
    bool gameOver = false;

    while (!gameOver) {
        char playerMarker = (turn % 2 == 1) ? 'X' : 'O';
        int playerNumber = (turn % 2 == 1) ? 1 : 2;

        std::cout << "\nPlayer " << playerNumber << "'s turn (" << playerMarker << ").\n";
        displayBoard(board);

        int choice = getPlayerChoice(playerNumber, board);
        updateBoard(board, choice, playerMarker);

        if (checkWinner(board, playerMarker)) {
            gameOver = true;
            std::cout << "\nCongratulations! Player " << playerNumber << " (" << playerMarker << ") wins!\n";
        } else if (checkDraw(board)) {
            gameOver = true;
            std::cout << "\nGame over. It's a draw!\n";
        }

        if (gameOver) {
            displayBoard(board);
        }

        turn++;
    }

    return 0;
}

void displayBoard(const std::vector<char>& board) {
    std::cout << "-------------\n";
    for (int i = 0; i < 9; ++i) {
        std::cout << "| " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            std::cout << "|\n";
            std::cout << "-------------\n";
        }
    }
}

int getPlayerChoice(int player, const std::vector<char>& board) {
    int choice;
    bool isValid = false;

    while (!isValid) {
        std::cout << "Enter a number (1-9): ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 9) {
            std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            std::cout << "That square is already taken. Please choose another.\n";
        } else {
            isValid = true;
        }
    }
    return choice;
}

void updateBoard(std::vector<char>& board, int choice, char playerMarker) {
    board[choice - 1] = playerMarker;
}

bool checkWinner(const std::vector<char>& board, char playerMarker) {
    
    if ((board[0] == playerMarker && board[1] == playerMarker && board[2] == playerMarker) ||
        (board[3] == playerMarker && board[4] == playerMarker && board[5] == playerMarker) ||
        (board[6] == playerMarker && board[7] == playerMarker && board[8] == playerMarker)) {
        return true;
    }
    
    if ((board[0] == playerMarker && board[3] == playerMarker && board[6] == playerMarker) ||
        (board[1] == playerMarker && board[4] == playerMarker && board[7] == playerMarker) ||
        (board[2] == playerMarker && board[5] == playerMarker && board[8] == playerMarker)) {
        return true;
    }
   
    if ((board[0] == playerMarker && board[4] == playerMarker && board[8] == playerMarker) ||
        (board[2] == playerMarker && board[4] == playerMarker && board[6] == playerMarker)) {
        return true;
    }
    return false;
}

bool checkDraw(const std::vector<char>& board) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}