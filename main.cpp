#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to initialize board
void initializeBoard() {
    char position = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = position++;
        }
    }
}

// Function to display board
void displayBoard() {
    cout << "\n";
    cout << "     TIC TAC TOE GAME\n\n";

    for (int i = 0; i < 3; i++) {
        cout << "     ";

        for (int j = 0; j < 3; j++) {
            cout << board[i][j];

            if (j < 2)
                cout << "  |  ";
        }

        cout << "\n";

        if (i < 2)
            cout << "   -------------------\n";
    }

    cout << "\n";
}

// Function to change player
void switchPlayer() {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

// Function to place mark on board
bool makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    // Check valid move
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

// Function to check winner
bool checkWinner() {

    // Row checking
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer) {
            return true;
        }
    }

    // Column checking
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer) {
            return true;
        }
    }

    // Diagonal checking
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer) {
        return true;
    }

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer) {
        return true;
    }

    return false;
}

// Function to check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

int main() {

    char playAgain;

    do {

        initializeBoard();
        currentPlayer = 'X';

        int choice;
        bool gameOver = false;

        while (!gameOver) {

            displayBoard();

            cout << "Player " << currentPlayer
                 << " Enter Position (1-9): ";

            cin >> choice;

            // Input validation
            if (choice < 1 || choice > 9) {
                cout << "\nInvalid Position! Try Again.\n";
                continue;
            }

            // Move validation
            if (!makeMove(choice)) {
                cout << "\nPosition Already Used! Try Again.\n";
                continue;
            }

            // Winner checking
            if (checkWinner()) {
                displayBoard();
                cout << "Player " << currentPlayer
                     << " Wins the Game!\n";
                gameOver = true;
            }

            // Draw checking
            else if (checkDraw()) {
                displayBoard();
                cout << "Game Draw!\n";
                gameOver = true;
            }

            // Switch player
            else {
                switchPlayer();
            }
        }

        cout << "\nDo You Want to Play Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank You for Playing!\n";

    return 0;
}