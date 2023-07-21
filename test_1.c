#include <stdio.h>
#include <stdbool.h>

// Function to check if the game is won
int checkWin(char board[3][3]) {
    // Check rows for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    // Check columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }

    // No win yet
    return 0;
}


// Function to perform the unit test
bool performUnitTest(char board[3][3], int expectedResult) {
    int result = checkWin(board);
    if (result == expectedResult) {
        return true;
    } else {
        printf("Unit test failed!\n");
        printf("Expected result: %d, Actual result: %d\n", expectedResult, result);
        return false;
    }
}

int main() {
    // Test 1: Horizontal win for 'X'
    char board1[3][3] = {
        {'X', 'X', 'X'},
        {' ', 'O', 'O'},
        {'O', 'X', 'O'}
    };
    bool test1Passed = performUnitTest(board1, 1);

    // Test 2: Vertical win for 'O'
    char board2[3][3] = {
        {'X', 'O', 'X'},
        {' ', 'O', 'O'},
        {'X', 'O', 'X'}
    };
    bool test2Passed = performUnitTest(board2, 1);

    // Test 3: Diagonal win for 'X'
    char board3[3][3] = {
        {'X', 'O', 'X'},
        {' ', 'X', 'O'},
        {'O', 'X', 'O'}
    };
    bool test3Passed = performUnitTest(board3, 1);

    // Test 4: No win yet
    char board4[3][3] = {
        {'X', 'O', 'X'},
        {' ', ' ', 'O'},
        {'O', 'X', 'O'}
    };
    bool test4Passed = performUnitTest(board4, 0);

    // Check overall test results
    if (test1Passed && test2Passed && test3Passed && test4Passed) {
        printf("All unit tests passed!\n");
    } else {
        printf("Some unit tests failed.\n");
    }

    return 0;
}
