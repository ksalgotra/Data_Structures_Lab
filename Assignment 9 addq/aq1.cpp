#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, visited, adj);
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    vector<bool> visited(V, false);
    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj);
            components++;
        }
    }

    cout << "Number of Connected Components: " << components << endl;
    return 0;
}
