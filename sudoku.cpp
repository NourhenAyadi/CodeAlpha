#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

// Function to print the Sudoku grid
void printGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << grid[i][j] << " ";
            if ((j + 1) % 3 == 0 && j != SIZE - 1) cout << "| ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i != SIZE - 1) cout << "---------------------" << endl;
    }
}

// Function to check if a number can be placed at a given position
bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
    // Check if the number exists in the same row or column
    for (int i = 0; i < SIZE; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) return false;
    }
    
    // Check if the number exists in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
    
    return true;
}

// Function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
    bool isEmpty = true;
    
    // Find the first empty cell
    for (row = 0; row < SIZE; ++row) {
        for (col = 0; col < SIZE; ++col) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) break;
    }
    
    // If no empty cell found, puzzle is solved
    if (isEmpty) return true;
    
    // Try placing numbers in the empty cell
    for (int num = 1; num <= SIZE; ++num) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            
            // Recursively solve the puzzle
            if (solveSudoku(grid)) return true;
            
            // If placing num at (row, col) doesn't lead to solution, backtrack
            grid[row][col] = 0;
        }
    }
    
    return false;
}

int main() {
    // Example Sudoku grid (0 represents empty cells)
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    cout << "Sudoku puzzle to solve:" << endl;
    printGrid(grid);
    
    cout << "\nSolving the Sudoku puzzle...\n" << endl;
    if (solveSudoku(grid)) {
        cout << "Sudoku puzzle solved successfully!" << endl;
        cout << "\nSolution:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }
    
    return 0;
}
