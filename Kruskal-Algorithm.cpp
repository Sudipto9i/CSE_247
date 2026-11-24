#include <bits/stdc++.h>
using namespace std;

/// Structure to store one edge
struct Edge {
    int from, to, weight;
};

/// Parent array for DSU
vector<int> parent;

/// Find the root of a node
int findParent(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

/// Join two sets
void unionSet(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a != b)
        parent[b] = a;
}

/// Kruskal's Algorithm
void kruskal(int N, vector<vector<pair<int,int>>>& adj) {

    vector<Edge> edges;

    /// Convert adjacency list into edge list
    for (int u = 1; u <= N; u++) {
        for (auto p : adj[u]) {

            int v = p.first;
            int w = p.second;

            /// Add each undirected edge only once
            if (u < v) {
                edges.push_back({u, v, w});
            }
        }
    }

    /// Sort edges by increasing weight
    sort(edges.begin(), edges.end(),
        [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

    /// Initialize DSU
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    vector<Edge> mst;
    int totalCost = 0;

    /// Process edges from smallest to largest
    for (auto e : edges) {

        int rootU = findParent(e.from);
        int rootV = findParent(e.to);

        /// If roots are different, no cycle is created
        if (rootU != rootV) {

            mst.push_back(e);
            totalCost += e.weight;

            unionSet(rootU, rootV);
        }

        /// MST needs exactly N-1 edges
        if ((int)mst.size() == N - 1)
            break;
    }

    /// Print MST
    cout << "Kruskal's MST edges:" << endl;

    for (auto e : mst) {
        cout << e.from << " - "
             << e.to
             << " (cost " << e.weight << ")" << endl;
    }

    cout << "Total cost = " << totalCost << endl;
}

int main() {

    int N, E;

    /// Read number of vertices and edges
    cin >> N >> E;

    /// Create adjacency list
    vector<vector<pair<int,int>>> adj(N + 1);

    /// Read all edges
    for (int i = 0; i < E; i++) {

        int u, v, w;

        cin >> u >> v >> w;

        /// Undirected graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    /// Run Kruskal
    kruskal(N, adj);

    return 0;
}
