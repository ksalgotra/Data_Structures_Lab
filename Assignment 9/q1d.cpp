# include<iostream>
# include<vector>
# include<queue>
# include<functional>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src){
    int V = adj.size();

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.emplace(0, src);

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]){
            continue;
        }

        for(pair<int, int>& neighbour : adj[u]){
            int v = neighbour.first;
            int w = neighbour.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    
    return dist;
}
int main(){
    int src = 0;
    vector<vector<pair<int,int>>> adj = {
        { {1, 4}, {2, 8} },{ {0, 4}, {4, 6}, {2, 3} },{ {0, 8}, {3, 2}, {1, 3} },{ {2, 2}, {4, 10} },{ {1, 6}, {3, 10} }
    };

    vector<int> dist = dijkstra(adj, src);
    
    for(int distance : dist){
        cout << distance << " ";
    }
    cout << endl;

return 0;
}
