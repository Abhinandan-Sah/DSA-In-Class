#include<bits/stdc++.h>
using namespace std;

const int N = 3;
int visited[N];

// Perform DFS starting from node 'node'
void dfsMatrix(int graph[][3], int node) {
    visited[node] = 1;
    cout << "Visited Node: " << node << endl;

    for (int neighbor = 0; neighbor < N; neighbor++) {
        // If there's an edge from node to neighbor and neighbor is unvisited
        if (graph[node][neighbor] == 1 && !visited[neighbor]) {
            dfsMatrix(graph, neighbor);
        }
    }
}

int main()
{
    int graph[3][3]= {
        {0, 1, 1}, 
        {1, 0, 1},
        {1, 1, 0}
    };
    // int graph[3][3]= {
    //     {0, 1, 0}, 
    //     {0, 0, 1},
    //     {1, 0, 0}
    // };
    int startNode= 0;

    vector<vector<int>> visited;
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};

    dfsMatrix(graph, startNode);

    return 0;
}