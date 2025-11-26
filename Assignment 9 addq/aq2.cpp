#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dijkstraGrid(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    
    priority_queue<pair<int, pair<int,int>>, 
                   vector<pair<int, pair<int,int>>>, 
                   greater<pair<int, pair<int,int>>>> pq;
    
    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});
    
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    while (!pq.empty()) {
        auto [cost, pos] = pq.top(); pq.pop();
        int x = pos.first, y = pos.second;
        
        if (x == m-1 && y == n-1) return cost;
        
        for (auto& d : dir) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int newCost = cost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }
    return -1;
}

int main() {
    int m, n;
    cout << "Enter grid size (m n): ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter grid values:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << "Minimum cost to reach bottom-right: " << dijkstraGrid(grid) << endl;
    return 0;
}
