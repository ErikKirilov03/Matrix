#include <iostream>
#include <vector>
#include <sstream>

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

void printReverseDiagonals(const vector<vector<int>>& m, int row, int col) {
    while (row >= 0 && col < m[0].size()) {
        cout << m[row][col] << ' ';
        row--; col++;
    }
    cout << endl;
}

int main()
{
    int rows, cols;
    vector<vector<int>> m;
    readMatrix(cin, m, rows, cols);

    for (int c = cols - 1; c >= 0; c--) {
        printReverseDiagonals(m, rows - 1, c);
    }

    for (int r = rows - 2; r >= 0; r--) {
        printReverseDiagonals(m, r, 0);
    }
    return 0;
}