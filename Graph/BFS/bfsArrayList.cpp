#include <bits/stdc++.h>
using namespace std;

void bfsArrayList(vector<vector<int>>& adjList, int startNode){
    int n = adjList.size();

    // making visited vector by initilizating with 0 and also making queue
    queue<int>q;
    vector<int>visited(n, 0);

    q.push(startNode);
    visited[startNode]=1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int j=0; j<adjList[node].size(); j++){
            if(visited[adjList[node][j]]!=1 ){
                q.push(adjList[node][j]);
                visited[adjList[node][j]]=1;
            }
        }
    }
}

int main()
{
    vector<vector<int>> adjList = {
        {2, 3, 1}, // neighbors of node 0
        {0},       // neighbors of node 1
        {0, 4},    // neighbors of node 2
        {0},       // neighbors of node 3
        {2}        // neighbors of node 4
    };

    int startNode =0;

    bfsArrayList(adjList, startNode);
    return 0;
}