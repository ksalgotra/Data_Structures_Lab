#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
        return;
    
    grid[x][y] = 0; // mark visited
    
    dfs(x+1, y, grid);
    dfs(x-1, y, grid);
    dfs(x, y+1, grid);
    dfs(x, y-1, grid);
}

int countIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), count = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                count++;
                dfs(i, j, grid);
            }
        }
    }
    return count;
}

int main() {
    int m, n;
    cout << "Enter grid size (m n): ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter grid values (0/1):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << "Number of islands: " << countIslands(grid) << endl;
    return 0;
}
