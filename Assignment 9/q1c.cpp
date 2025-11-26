#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;


void primMST(int V, const vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    int src = 0;
    pq.push({0, src});
    key[src] = 0;

    int mstWeight = 0;

    cout << "\n--- Prim's Algorithm Output ---\n";

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        if (parent[u] != -1) mstWeight += key[u];

        for (auto& edge : adj[u]) {
            int weight = edge.first;
            int v = edge.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edge\tWeight\n";
    for (int i = 1; i < V; ++i)
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << "\t" << key[i] << "\n";

    cout << "Total Cost of MST (Prim): " << mstWeight << endl;
}

// KRUSKAL'S ALGORITHM
struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rankv;
    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

void kruskalMST(int V, const vector<Edge>& edges) {
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DSU dsu(V);
    int mstWeight = 0;

    cout << "\n--- Kruskal's Algorithm Output ---\n";
    cout << "Edge\tWeight\n";

    for (auto &e : sortedEdges) {
        if (dsu.union_sets(e.u, e.v)) {
            cout << e.u << " - " << e.v << "\t" << e.w << endl;
            mstWeight += e.w;
        }
    }
    cout << "Total Cost of MST (Kruskal): " << mstWeight << endl;
}


int main() {
    int V, E;
    cout << "Enter number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<vector<pii>> adj(V);
    vector<Edge> edgeList;

    cout << "Enter " << E << " edges (u v w):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); 
        edgeList.push_back({u, v, w});
    }

    primMST(V, adj);
    kruskalMST(V, edgeList);

    return 0;
}
