#include <iostream>
#include <array>
#include <sstream>

using namespace std;

void readMatrix(istream& input, array<array<int, 10>, 10>& m, int& row, int& col) {
    input >> row; cin.ignore();

    for (int r = 0; r < row; r++) {
        string buffer;
        getline(input, buffer);
        istringstream iss(buffer);

        col = 0;
        while (iss >> m[r][col]) {
            col++;
        }
    }
}

bool compare(int row1, int col1, const array<array<int, 10>, 10>& m1, int row2, int col2, const array<array<int, 10>, 10>& m2) {
    if (row1 != row2 || col1 != col2) {
        return false;
    }

    for (int r = 0; r < row1; r++) {
        for (int c = 0; c < col1; c++) {
            if (m1[r][c] != m2[r][c]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int rows1, cols1, rows2, cols2;
    array<array<int, 10>, 10> m1, m2;

    readMatrix(cin, m1, rows1, cols1);
    readMatrix(cin, m2, rows2, cols2);

    cout << (compare(rows1, cols1, m1, rows2, cols2, m2) ? "equal" : "not equal");
}