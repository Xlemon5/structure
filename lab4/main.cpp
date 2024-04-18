

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& board, int N);
void printSolution(vector<vector<int>>& board);
bool solveKnightTourUtil(int x, int y, int movei, vector<vector<int>>& board, vector<int>& xMove, vector<int>& yMove, int N);

bool solveKnightTour(int N) {
    vector<vector<int>> board(N, vector<int>(N, -1));
    vector<int> xMove = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> yMove = {1, 2, 2, 1, -1, -2, -2, -1};
    board[0][0] = 0;

    if (!solveKnightTourUtil(0, 0, 1, board, xMove, yMove, N)) {
        cout << "Solution does not exist";
        return false;
    } else {
        printSolution(board);
    }

    return true;
}

bool solveKnightTourUtil(int x, int y, int movei, vector<vector<int>>& board, vector<int>& xMove, vector<int>& yMove, int N) {
    if (movei == N * N) {
        return true;
    }

    for (int k = 0; k < 8; k++) {
        int nextX = x + xMove[k];
        int nextY = y + yMove[k];
        if (isSafe(nextX, nextY, board, N)) {
            board[nextX][nextY] = movei;
            if (solveKnightTourUtil(nextX, nextY, movei + 1, board, xMove, yMove, N)) {
                return true;
            } else {
                board[nextX][nextY] = -1; // backtracking
            }
        }
    }

    return false;
}

bool isSafe(int x, int y, vector<vector<int>>& board, int N) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

void printSolution(vector<vector<int>>& board) {
    for (auto &i : board) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int N = 8; // размер доски
    solveKnightTour(N);
    return 0;
}