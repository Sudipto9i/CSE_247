/// Full Prim's Algorithm Code
#include<bits/stdc++.h>
using namespace std;
// Store one edge
struct Edge{
    int from, to, weight;
    // Make priority_queue give the smallest weight first
    bool operator<(const Edge& other) const{
        return weight > other.weight;
    }
};
// Prim's Algorithm
void prim(int N, vector<vector<pair<int,int>>>& adj){
    //visited[x] = true means x is already in MST
    vector<bool> visited(N+1,false);
    // Priority queue stores available edges
    priority_queue<Edge> pq;
    // Store the edges selected for MST
    vector<Edge> mst;
    // Total cost of MST
    int totalCost = 0;
    // Start from node 1
    visited[1] = true;
    // Put all edges connected to node 1 into priority queue
    for(auto p:adj[1]){
        pq.push({1,p.first,p.second});
    }
    // Continue until we have N-1 edges
    while(!pq.empty()&&(int)mst.size()<N-1){
        // Get the cheapest available edge
        Edge cur = pq.top();
        pq.pop();
        // If destination is already in MST, skip it
        if(visited[cur.to])
            continue;
        // Add the new node to MST
        visited[cur.to] = true;
        // Add this edge to MST
        mst.push_back(cur);
        // Add its cost
        totalCost += cur.weight;
        // Add edges leaving the newly added node
        for(auto p:adj[cur.to]){
            //Only consider unvisited nodes
            if(!visited[p.first]){
                pq.push({cur.to,p.first,p.second});
            }
        }
    }
    // Print MST
    cout<<"Prim's MST edges:"<<endl;
    for(auto e:mst){
        cout<<e.from<<"-"
            <<e.to
            <<" (cost "<<e.weight<<")"<<endl;
    }
    cout<<"Total cost = "<<totalCost<<endl;
}
int main(){
    int N , E;
    /// Read number of nodes and edges
    cin>>N>>E;
    // Create adjacency list
    vector<vector<pair<int, int>>>adj(N+1);
    // Read all edges
    for(int i=0;i<E ;i++){
        int u,v,w;
        cin>>u>>v>>w;
        // Undirected graph
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    // Run Prim's Algorithm
    prim(N, adj);
    return 0;
}
