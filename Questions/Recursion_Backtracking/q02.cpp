#include <iostream>
using namespace std;

const int N = 5;  //input grid (rows)
const int M = 5;  //input grid (columns)

int dx[] = {-1, 1, 0, 0}; //Up, Down, Left, Right
int dy[] = {0, 0, -1, 1};

int dfs(char grid[N][M], int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M || grid[x][y] != 'T') {
        return 0;
    }

    grid[x][y] = 'W';     //cell visited

    int size = 1;

    for (int i = 0; i < 4; i++) {
        size += dfs(grid, x + dx[i], y + dy[i]);
    }

    return size;
}

int largestForest(char grid[N][M]) {
    int maxSize = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'T') {
                int forestSize = dfs(grid, i, j);
                maxSize = max(maxSize, forestSize);
            }
        }
    }

    return maxSize;
}

int main() {
    char grid[N][M] = {
        {'T', 'T', 'T', 'W', 'W'},
        {'T', 'W', 'T', 'T', 'W'},
        {'W', 'W', 'T', 'T', 'T'},
        {'W', 'T', 'T', 'W', 'W'},
        {'W', 'T', 'T', 'T', 'W'}
    };

    cout << "The size of the largest forest is: " << largestForest(grid) << endl;

    return 0;
}
