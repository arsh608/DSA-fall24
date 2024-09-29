#include <iostream>

using namespace std;

bool is_safe(int **board, int size, int row, int col) {
    for (int i = 0; i < size; ++i)
        if (board[row][i] || board[i][col])
            return false;

    for (int i = 0; i < size; ++i) {
        if (row - i >= 0 && col - i >= 0 && board[row - i][col - i])
            return false;
        if (row + i < size && col + i < size && board[row + i][col + i])
            return false;
        if (row - i >= 0 && col + i < size && board[row - i][col + i])
            return false;
        if (row + i < size && col - i >= 0 && board[row + i][col - i])
            return false;
    }

    return true;
}

bool place_queens(int **board, int size, int col) {
    if (col >= size) return true;

    for (int row = 0; row < size; ++row) {
        if (is_safe(board, size, row, col)) {
            board[row][col] = 1;
            if (place_queens(board, size, col + 1)) return true;
            board[row][col] = 0;  // Backtrack
        }
    }

    return false;
}

int **initialize_board(int size) {
    int **board = new int*[size];
    for (int i = 0; i < size; ++i)
        board[i] = new int[size]();
    place_queens(board, size, 0);
    return board;
}

int main() {
    int n;
    cin >> n;
    int **board = initialize_board(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << (board[i][j] ? 'Q' : '.') << " ";
        cout << endl;
    }

    for (int i = 0; i < n; ++i)
        delete[] board[i];
    delete[] board;

    return 0;
}
