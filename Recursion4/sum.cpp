#include<iostream>
using namespace std;

int main()
{
    int n; 
    cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int max=arr[0];
    int cnt=1;
    for(int i=0; i<n; i++){
        if(max<arr[i]){
            cnt++;
            max=arr[i];
        }
    }
    cout<<cnt;

    
    return 0;
}       




// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<int> shortestReach(int n, int m, vector<vector<int>>& edges, int s) {
//         vector<vector<int>> adj(n + 1);
        
//         // Build adjacency list
//         for (auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u); // undirected
//         }

//         vector<int> dist(n + 1, -1); // distance initialized to -1
//         queue<int> q;
//         q.push(s);
//         dist[s] = 0;

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             for (int neighbor : adj[node]) {
//                 if (dist[neighbor] == -1) {
//                     dist[neighbor] = dist[node] + 6;
//                     q.push(neighbor);
//                 }
//             }
//         }

//         // Prepare the result excluding the source node
//         vector<int> result;
//         for (int i = 1; i <= n; i++) {
//             if (i != s) {
//                 result.push_back(dist[i]);
//             }
//         }
//         return result;
//     }
// };

// int main() {
//     int q;
//     cin >> q;
//     Solution sol;

//     while (q--) {
//         int n, m;
//         cin >> n >> m;
//         vector<vector<int>> edges;

//         for (int i = 0; i < m; i++) {
//             int u, v;
//             cin >> u >> v;
//             edges.push_back({u, v});
//         }

//         int s;
//         cin >> s;
//         vector<int> res = sol.shortestReach(n, m, edges, s);

//         for (int d : res) {
//             cout << d << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
