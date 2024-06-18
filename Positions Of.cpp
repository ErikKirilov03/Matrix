#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> m(rows, vector<int>(cols));

    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            cin >> m[r][c];
        }
    }

    int find;
    cin >> find;

    bool found = false;

    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            if (m[r][c] == find) {
                cout << r << ' ' << c;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "not found";
    }
}