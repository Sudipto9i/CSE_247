#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

struct Edge {
    int from, to, weight;
};

// ---------- Bellman-Ford ----------
void bellmanFord(int N, int source, vector<vector<pair<int,int>>>& adj) {
    vector<Edge> edges;
    for (int u = 1; u <= N; u++)
        for (auto p : adj[u])
            edges.push_back({u, p.first, p.second});

    vector<int> dist(N + 1, INF);
    vector<int> par(N + 1, -1);
    dist[source] = 0;

    for (int pass = 1; pass <= N - 1; pass++) {
        bool changed = false;
        for (auto e : edges) {
            if (dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.weight;
                par[e.to] = e.from;
                changed = true;
            }
        }
        if (!changed) break;
    }

    for (auto e : edges) {
        if (dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to]) {
            cout << "Negative cycle detected! Shortest paths do not exist." << endl;
            return;
        }
    }

    cout << "Bellman-Ford: shortest distances from node " << source << endl;
    for (int i = 1; i <= N; i++) {
        cout << source << " -> " << i << " : ";
        if (dist[i] == INF) { cout << "unreachable" << endl; continue; }
        cout << dist[i] << "   path: ";
        vector<int> path;
        for (int x = i; x != -1; x = par[x]) path.push_back(x);
        reverse(path.begin(), path.end());
        for (int k = 0; k < (int)path.size(); k++) {
            if (k) cout << " -> ";
            cout << path[k];
        }
        cout << endl;
    }
}

// ---------- Floyd-Warshall ----------
void floydWarshall(int N, vector<vector<pair<int,int>>>& adj) {
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++) dist[i][i] = 0;
    for (int u = 1; u <= N; u++)
        for (auto p : adj[u])
            dist[u][p.first] = min(dist[u][p.first], p.second);

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 1; i <= N; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected! Shortest paths do not exist." << endl;
            return;
        }
    }

    cout << "Floyd-Warshall: all-pairs shortest distances" << endl;
    cout << "     ";
    for (int j = 1; j <= N; j++) cout << setw(5) << j;
    cout << endl;
    for (int i = 1; i <= N; i++) {
        cout << setw(4) << i << " ";
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF) cout << setw(5) << "INF";
            else cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<pair<int,int>>> adj(N + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    /// Source Vertex for Bellman-Ford
    int source;
    cin>>source;

    ///Run Bellman-Ford
    bellmanFord(N,source,adj);
    ///Run Floyd-Warshall
    floydWarshall(N,adj);
    return 0;
}
