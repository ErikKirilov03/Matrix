#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int N;
    string buff;
    getline(cin, buff, ',');
    N = stoi(buff);

    char whichAlg;
    cin >> whichAlg;

    vector<vector<int>> matrix(N, vector<int>(N));

    int r = 0;
    int c = 0;
    int direction = 1;
    for (int curr = 1; curr <= N * N; curr++) {
        matrix[r][c] = curr;

        r += direction;

        if (whichAlg == 'A') {
            if (r >= N) {
                c++;
                r = 0;
            }
        }
        else {
            if (r < 0 || r >= N) {
                c++;
                if (direction > 0) {
                    r = N - 1;
                }
                else {
                    r = 0;
                }
                direction = -direction;
            }
        }
    }

    for (size_t r = 0; r < N; r++) {
        for (size_t c = 0; c < N; c++) {
            cout << matrix[r][c] << ' ';
            cout << endl;
        }
    }
}