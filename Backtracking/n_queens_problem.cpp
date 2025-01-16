#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<int>& board) {
    for (int row : board) {
        for (int col = 0; col < board.size(); col++) {
            cout << (col == row ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<int>& board, int row, int col) {
    // Check for conflicts with previously placed queens
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||                        // Same column
            board[i] - i == col - row ||              // Same diagonal (/)
            board[i] + i == col + row) {              // Same diagonal (\)
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& board, vector<vector<int>>& solutions) {
    if (row == n) {
        // Found a valid solution, store it
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;          // Place the queen
            solveNQueens(n, row + 1, board, solutions); // Recur for the next row
            board[row] = -1;           // Backtrack (remove the queen)
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<int> board(n, -1);           // Initialize the board (-1 means no queen placed)
    vector<vector<int>> solutions;     // To store all solutions
    solveNQueens(n, 0, board, solutions);
    return solutions;
}

int main() {
    int n = 8; // Change this to solve for different board sizes
    vector<vector<int>> solutions = solveNQueens(n);

    cout << "Number of solutions for " << n << "-Queens: " << solutions.size() << endl;
    for (int i = 0; i < min(3, (int)solutions.size()); i++) { // Print up to 3 solutions
        cout << "Solution " << i + 1 << ":\n";
        printSolution(solutions[i]);
    }

    return 0;
}