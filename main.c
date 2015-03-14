/* Tic Tac Toe
 * Umang Galaiya
 * umanghome@gmail.com
 * February 1, 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBoard (int* board);
int checkEntry (int* board, int index);
int checkForWin (int* board, int player, int index);

int main()
{
    char playerX[10], playerO[10];
    int board[9];
    int enteredLocation;
    int turnCounter = 0;
    int player;
    int i;

    // Initialize board.
    for (i = 0; i < 9; i++) {
        board[i] = 0;
    }

    // Get players' names.
    printf("Enter the name of the player who will use X: ");
    gets(playerX);
    printf("Enter the name of the player who will use O: ");
    gets(playerO);

    // Loop until someone wins or the game is a tie.
    while (1) {

        // Print the board.
        printf("\n");
        printBoard(board);

        // Exit if maximum possible turns are played.
        if (turnCounter == 9) {
            printf("\nTie!\n");
            return 0;
        }

        // Decide player's turn to play.
        player = (turnCounter % 2) + 1;
        if (player == 1) {
            printf("\n%s's turn! Enter location: ", playerX);
        }
        else if (player == 2) {
            printf("\n%s's turn! Enter location: ", playerO);
        }

        // Get location of the move.
        scanf("%d", &enteredLocation);

        // Check if the location is already in use.
        while (checkEntry(board, enteredLocation) != 1) {
            printf("Location already in use! Enter a different location: ");
            scanf("%d", &enteredLocation);
        }

        // Insert into board.
        board[enteredLocation - 1] = player;

        // Check if someone won.
        if (checkForWin(board, player, enteredLocation) == 1) {
            if (player == 1) {
                printBoard(board);
                printf("\nCongratulations! %s has won!\n", playerX);                ;
            }
            else if (player == 2) {
                printBoard(board);
                printf("\nCongratulations! %s has won!\n", playerO);
            }
            return 0;
        }

        // Increment turn.
        turnCounter++;
    }
}


// Prints the board.
void printBoard (int* board) {
    int i;
    printf("\n");
    for (i = 0; i < 9; i++) {
        if (board[i] == 1) {
            printf("X ");
        }
        else if (board[i] == 2) {
            printf("O ");
        }
        else {
            printf("_ ");
        }
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
    return;
}


// Returns 1 if possible to enter, 0 otherwise.
int checkEntry (int* board, int index) {
    if (board[index - 1] == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// Returns 1 if user has won, 0 otherwise.
int checkForWin (int* board, int player, int index) {

    // Check horizontally
    if (index == 1 || index == 2 || index == 3) {
        if (board[0] == player && board[1] == player && board[2] == player) {
            return 1;
        }
    }
    else if (index == 4 || index == 5 || index == 6) {
        if (board[3] == player && board[4] == player && board[5] == player) {
            return 1;
        }
    }
    else if (index == 7 || index == 8 || index == 9) {
        if (board[6] == player && board[7] == player && board[8] == player) {
            return 1;
        }
    }

    // Check vertically
    if (index == 1 || index == 4 || index == 7) {
        if (board[0] == player && board[3] == player && board[6] == player) {
            return 1;
        }
    }
    else if (index == 2 || index == 5 || index == 8) {
        if (board[1] == player && board[4] == player && board[7] == player) {
            return 1;
        }
    }
    else if (index == 3 || index == 6 || index == 9) {
        if (board[2] == player && board[5] == player && board[8] == player) {
            return 1;
        }
    }

    // Check for slant if index is 5
    if (index == 5) {
        if ((board[0] == player && board[4] == player && board[8] == player) || (board[2] == player && board[4] == player && board[6] == player)) {
            return 1;
        }
    }

    return 0;
}
