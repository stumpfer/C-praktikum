#include <iostream>
#include <vector>

const int N = 8; // Size of the chessboard

// All possible knight moves (L-shaped moves)
int rowMoves[] = {2, 1, -1, -2, -2, -1, 1, 2};
int colMoves[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Print the chessboard path
void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << board[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Check if a cell is within the board and unvisited
bool isSafe(int x, int y, const std::vector<std::vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Recursive function to find the knight's path
bool findPath(std::vector<std::vector<int>>& board, int moveCount, int currentRow, int currentCol) {
    if (moveCount == N * N) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int nextRow = currentRow + rowMoves[i];
        int nextCol = currentCol + colMoves[i];

        if (isSafe(nextRow, nextCol, board)) {
            board[nextRow][nextCol] = moveCount;
            if (findPath(board, moveCount + 1, nextRow, nextCol)) {
                return true;
            }
            board[nextRow][nextCol] = -1; // Backtrack: undo the move
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, -1));

    board[0][0] = 0; // Initial position marked as 0

    if (findPath(board, 1, 0, 0)) {
        std::cout << "Knight's tour found:" << std::endl;
        printBoard(board);
    } else {
        std::cout << "No knight's tour found." << std::endl;
    }

    return 0;
}