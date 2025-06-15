/*
name : muhammad adam irfan bin rusli
id : 22011423
group : 1
lab : 2 (Hard) - A Boolean Matrix Question
problem: https://geeksforgeeks.org/a-boolean-matrix-question/
*/

#include <iostream>
using namespace std;

const int MAX = 10;

void markMatrix(int matrix[][MAX], int row, int column, bool rowMark[], bool columnMark[]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (rowMark[i] || columnMark[j]) {
                matrix[i][j] = 1;
            }
        }
    }
}

void printMatrix(int matrix[][MAX], int row, int column) {
    cout << "Output:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row, column;

    cout << "Input: ";
    cin >> row >> column;

    if (row <= 0 || column <= 0 || row > MAX || column > MAX) {
        cout << "Error: Row and column must be between 1 and " << MAX << "." << endl;
        return 1;
    }

    int matrix[MAX][MAX];
    bool rowMark[MAX] = {false};
    bool columnMark[MAX] = {false};

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                rowMark[i] = true;
                columnMark[j] = true;
            }
        }
    }

    markMatrix(matrix, row, column, rowMark, columnMark);
    printMatrix(matrix, row, column);

    return 0;
}