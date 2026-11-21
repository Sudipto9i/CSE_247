#include <bits/stdc++.h>
using namespace std;

// ---------- Edge with operator overloading (smallest weight on top) ----------
struct Edge
{
    int from, to, weight;
    bool operator<(const Edge& other) const
    {
        return weight > other.weight;
    }
};

// ---------- Disjoint Set Union (for Kruskal) ----------
vector<int> parent;

int findLeader(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = findLeader(parent[x]);
}

bool mergeGroups(int a, int b)
{
    a = findLeader(a);
    b = findLeader(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

// ---------- Prim ----------
void prim(int N, vector<vector<pair<int,int>>>& adj)
{
    vector<bool> visited(N + 1, false);
    priority_queue<Edge> pq;
    vector<Edge> mst;
    int totalCost = 0;

    visited[1] = true;
    for (auto p : adj[1]) pq.push({1, p.first, p.second});

    while (!pq.empty() && (int)mst.size() < N - 1)
    {
        Edge cur = pq.top();
        pq.pop();
        if (visited[cur.to]) continue;

        visited[cur.to] = true;
        mst.push_back(cur);
        totalCost += cur.weight;

        for (auto p : adj[cur.to])
        {
            if (!visited[p.first]) pq.push({cur.to, p.first, p.second});
        }
    }

    cout << "Prim's MST edges:" << endl;
    for (auto e : mst) cout << e.from << " - " << e.to << " (cost " << e.weight <<
                                ")" << endl;
    cout << "Total cost = " << totalCost << endl;
}

// ---------- Kruskal ----------
void kruskal(int N, vector<vector<pair<int,int>>>& adj)
{
    vector<Edge> edges;
    for (int u = 1; u <= N; u++)
    {
        for (auto p : adj[u])
        {
            if (u < p.first) edges.push_back({u, p.first, p.second});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
    {
        return a.weight < b.weight;
    });

    parent.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) parent[i] = i;

    vector<Edge> mst;
    int totalCost = 0;

    for (auto e : edges)
    {
        if (mergeGroups(e.from, e.to))
        {
            mst.push_back(e);
            totalCost += e.weight;
            if ((int)mst.size() == N - 1) break;
        }
    }

    cout << "Kruskal's MST edges:" << endl;
    for (auto e : mst) cout << e.from << " - " << e.to << " (cost " << e.weight <<
                                ")" << endl;
    cout << "Total cost = " << totalCost << endl;
}

int main()
{
    int N, E;
    cin >> N >> E;

    vector<vector<pair<int,int>>> adj(N + 1);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prim(N, adj);
    cout << endl;
    kruskal(N, adj);
    return 0;
}
