#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool Read2x2(const vector<vector<char>>& m, size_t startRow, size_t startCol) {
    return  m[startRow][startCol] == m[startRow][startCol + 1] &&
        m[startRow][startCol] == m[startRow + 1][startCol] &&
        m[startRow][startCol] == m[startRow + 1][startCol + 1];
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> m(rows, vector<char>(cols));

    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            cin >> m[r][c];
        }
    }

    size_t if2x2 = 0;

    for (size_t r = 0; r < rows - 1; r++) {
        for (size_t c = 0; c < cols - 1; c++) {
            if (Read2x2(m, r, c)) {
                if2x2++;
            }
        }
    }
    cout << if2x2 << ' ' << endl;
}