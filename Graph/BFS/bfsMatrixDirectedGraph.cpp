#include<bits/stdc++.h>
using namespace std;
// This is a directed graph
void bfsMatrix(int graph[][3], int n, int startNode){
    // int n = sizeof(graph)/sizeof(graph[0]);  // line5 and 6 are not needed
    // int m = sizeof(graph[0])/sizeof(graph[0][0]);

    // if it is a directed graph then we don't need to make 2D visited matrix
    int visited[n] = {0};
    queue<int>q;

    // pushing in the queue and then mark the element visited
    q.push(startNode);
    visited[0]=1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        for(int neighbor=0; neighbor< n; neighbor++){
            if(!visited[neighbor] && graph[node][neighbor]==1){
                visited[neighbor]=1;
                q.push(neighbor);
            }
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

    bfsMatrix(graph, 3, startNode);

    return 0;
}