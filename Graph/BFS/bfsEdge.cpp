#include<bits/stdc++.h>
using namespace std;

void bfsEdge(vector<vector<int>>& edges, int n, int startNode){
    vector<vector<int>> adjList(n);
    for(const auto& edge: edges){
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line for directed graph
    }

    vector<int>visited(n, 0);
    queue<int>q;
    q.push(startNode);
    visited[startNode]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        for(int j=0; j<adjList[node].size(); j++){
            if(!visited[adjList[node][j]]){
                q.push(adjList[node][j]);
                visited[adjList[node][j]]=1;
            }
        }
    }
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3}
    };

    int startNode=0;

    bfsEdge(edges, 4, startNode);
    return 0;
}