// // For Undirected graph
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int vertex, edges;
//     cin>>vertex>>edges;

//     vector<int>AdjList[vertex];

//     int u, v;
//     for(int i=0; i<edges; i++){
//         cin>>u>>v;

//         AdjList[u].push_back(v);
//         AdjList[v].push_back(u);
//     }

//     // Print List 
//     for(int i=0; i<vertex; i++){
//         cout<<i<<" -> ";
//         for(int j=0; j<AdjList[i].size(); j++){
//             cout<<AdjList[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }


// For Undirected weighted graph
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertex, edges;
    cin>>vertex>>edges;

    vector<pair<int,int>>AdjList[vertex];

    int u, v, weight;
    for(int i=0; i<edges; i++){
        cin>>u>>v>>weight;

        AdjList[u].push_back(make_pair(v, weight));
        AdjList[v].push_back(make_pair(u, weight));
    }

    // Print List 
    for(int i=0; i<vertex; i++){
        cout<<i<<" -> ";
        for(int j=0; j<AdjList[i].size(); j++){
            cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<" ";
        }
        cout<<endl;
    }

    return 0;
}