#include <iostream>
#include <iostream>
using namespace std;

const int MAX = 100;

void computeDiagonalSums(int matrix[][MAX], int n)
{
    int principalDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < n; i++)
    {
        principalDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][n - i - 1];
    }

    cout << "Primary Diagonal Sum: " << principalDiagonalSum << endl;
    cout << "Secondary Diagonal Sum: " << secondaryDiagonalSum << endl;
}

int main()
{
    int n;

    cout << "Input: ";
    cin >> n;

    if (n <= 0 || n > MAX)
    {
        cout << "Invalid matrix size." << endl;
        return 1;
    }

    int matrix[MAX][MAX];

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    computeDiagonalSums(matrix, n);

    return 0;
}