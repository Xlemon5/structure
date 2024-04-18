#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Проверка по горизонтали
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Проверка верхней диагонали
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Проверка нижней диагонали
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int N) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1, N)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0, N)) {
        cout << "Решение не найдено" << endl;
        return;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N = 8;
    solveNQueens(N);

    return 0;
}