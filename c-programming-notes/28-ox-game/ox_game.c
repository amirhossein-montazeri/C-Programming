/*
 * O/X game (tic-tac-toe) - you (O) against the computer (X).
 *
 * Structure:  1. libraries   2. #define SIZE 3
 *             3. printMatrix(), checkWinner(), main()
 *
 * You enter row and column (1..SIZE); the computer plays a random free cell.
 * The game ends when somebody completes a row, a column or a diagonal, or
 * when the board is full (draw).
 *
 * Usage: ./ox_game [seed]     (a seed makes the computer's moves repeatable)
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 3

void printMatrix(char matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
}

bool checkWinner(char matrix[SIZE][SIZE], char player) {
    /* rows and columns */
    for (int i = 0; i < SIZE; i++) {
        bool row = true, col = true;
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] != player) row = false;
            if (matrix[j][i] != player) col = false;
        }
        if (row || col) return true;
    }
    /* the two diagonals */
    bool diag1 = true, diag2 = true;
    for (int i = 0; i < SIZE; i++) {
        if (matrix[i][i] != player)            diag1 = false;
        if (matrix[i][SIZE - 1 - i] != player) diag2 = false;
    }
    return diag1 || diag2;
}

static bool boardFull(char matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (matrix[i][j] == '_') return false;
    return true;
}

int main(int argc, char *argv[]) {
    char matrix[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = '_';

    int count = 0;
    char winner = '\0';          /* 'U' = user, 'P' = computer player, 'D' = draw */

    srand(argc > 1 ? (unsigned)atoi(argv[1]) : (unsigned)time(NULL));

    printMatrix(matrix);
    while (winner == '\0') {
        int row1, col1, row2, col2;
        count++;

        /* --- user move (O) --- */
        for (;;) {
            printf("Enter a number as row (1-%d): ", SIZE);
            if (scanf("%d", &row1) != 1) { printf("\nInput ended.\n"); return 1; }
            printf("Enter a number as column (1-%d): ", SIZE);
            if (scanf("%d", &col1) != 1) { printf("\nInput ended.\n"); return 1; }
            row1--; col1--;
            if (row1 >= 0 && row1 < SIZE && col1 >= 0 && col1 < SIZE &&
                matrix[row1][col1] == '_')
                break;
            printf("Invalid or occupied cell, try again.\n");
        }
        matrix[row1][col1] = 'O';

        if (checkWinner(matrix, 'O')) {
            winner = 'U';
        } else if (boardFull(matrix)) {
            winner = 'D';
        } else {
            /* --- computer move (X): random free cell --- */
            do {
                row2 = rand() % SIZE;
                col2 = rand() % SIZE;
            } while (matrix[row2][col2] != '_');
            matrix[row2][col2] = 'X';

            if (checkWinner(matrix, 'X'))
                winner = 'P';
            else if (boardFull(matrix))
                winner = 'D';
        }

        printMatrix(matrix);
    }

    if (winner == 'U')
        printf("User wins the match after %d hands\n", count);
    else if (winner == 'P')
        printf("Player (computer) wins the match after %d hands\n", count);
    else
        printf("Draw after %d hands\n", count);

    return 0;
}
