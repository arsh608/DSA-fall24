#include <iostream>
#include <string>
using namespace std;

const int N = 4; //matrix size

void findPaths(int mat[N][N], int x, int y, string path) {
    if (x == N - 1 && y == N - 1) {
        cout << path << endl;
        return;
    }

    mat[x][y] = 0; //current cell as visited

    if (x + 1 < N && mat[x + 1][y] == 1) {     // Move Down (D)
        findPaths(mat, x + 1, y, path + 'D');
    }

    if (y + 1 < N && mat[x][y + 1] == 1) {    // Move Right (R)
        findPaths(mat, x, y + 1, path + 'R');
    }

    if (x - 1 >= 0 && mat[x - 1][y] == 1) {    // Move Up (U)
        findPaths(mat, x - 1, y, path + 'U');
    }

    if (y - 1 >= 0 && mat[x][y - 1] == 1) {    // Move Left (L)
        findPaths(mat, x, y - 1, path + 'L');
    }

    mat[x][y] = 1; //unmark and backtrack
}

int main() {
    int mat[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    cout << "All possible paths are:" << endl;
    findPaths(mat, 0, 0, "");

    return 0;
}
