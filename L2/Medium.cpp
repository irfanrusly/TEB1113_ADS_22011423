/*
name : muhammad adam irfan bin rusli
id : 22011423
group : 1
lab : 2 (Medium) - Rotate a Matrix by 180 degree
problem: https://geeksforgeeks.org/rotate-matrix-180-degree/
*/

#include <iostream>
using namespace std;

const int MAX = 100;

int main()
{
    int n;
    cout << "Input: ";
    cin >> n;

    // Input validation
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

    // Output 180-degree rotated matrix
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
