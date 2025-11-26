#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<pair<int,int>>> adj(N+1);
    for (auto& t : times)
        adj[t[0]].push_back({t[1], t[2]});
    
    vector<int> dist(N+1, INT_MAX);
    dist[K] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, K});
    
    while (!pq.empty()) {
        auto [d,u] = pq.top(); 
        pq.pop();
        
        for (auto& e : adj[u]) {
            int v = e.first, w = e.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    int maxDelay = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INT_MAX) return -1;
        maxDelay = max(maxDelay, dist[i]);
    }
    return maxDelay;
}

int main() {
    int N, E, K;
    cout << "Enter number of nodes, edges, and source: ";
    cin >> N >> E >> K;

    vector<vector<int>> times(E, vector<int>(3));
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++)
        cin >> times[i][0] >> times[i][1] >> times[i][2];

    cout << "Network delay time: " << networkDelayTime(times, N, K) << endl;
    return 0;
}
