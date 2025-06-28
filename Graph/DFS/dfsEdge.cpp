#include <bits/stdc++.h>
using namespace std;

vector<int> visited(4, 0);

// DFS traversal
void dfsEdges(vector<vector<int>>& adjList, int node) {
    visited[node] = 1;
    cout << node << " ";

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfsEdges(adjList, neighbor);
        }
    }
}

int main() {
    int vertex = 4;
    vector<pair<int, int>> edges = {
        {2, 1},
        {1, 2},
        {2, 3}
    };

    vector<vector<int>> adjList(vertex);

    // Build the adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // since undirected
    }

    dfsEdges(adjList, 1); // Start DFS from node 1

    return 0;
}
