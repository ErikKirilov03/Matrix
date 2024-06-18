#include <iostream>
#include <sstream>
#include <vector>
#include<array>

using namespace std;

void readMatrix(istream& input, vector<vector<int>>& m, int& row, int& column) {
    input >> row >> column;

    m.resize(row, vector<int>(column, 0));

    for (size_t r = 0; r < row; r++) {
        for (size_t c = 0; c < column; c++) {
            cin >> m[r][c];
        }
    }
}

int sum3x3(const vector<vector<int>>& m, int startRow, int startCol) {
    int sum = 0;

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            sum += m[startRow + r][startCol + c];
        }
    }

    return sum;
}

int main()
{
    int rows;
    int cols;

    vector<vector<int>> matrix;
    readMatrix(cin, matrix, rows, cols);

    int MaxSum = INT_MIN;
    int maxSumOfStartRow = 0;
    int maxSumOfStartCol = 0;

    for (int r = 0; r <= rows - 2; r++) {
        for (int c = 0; c <= cols - 2; c++) {
            int currSum = sum3x3(matrix, r, c);
            if (currSum > MaxSum) {
                MaxSum = currSum;
                maxSumOfStartRow = r;
                maxSumOfStartCol = c;
            }
        }
    }

    cout << "MaxSum = " << MaxSum << endl;

    for (int r = maxSumOfStartRow; r < maxSumOfStartRow + 3; r++) {
        for (int c = maxSumOfStartCol; c < maxSumOfStartCol + 3; c++) {
            cout << matrix[r][c] << ' ';
        }
    }
}