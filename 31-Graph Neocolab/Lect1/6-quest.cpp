/*
Problem Statement



Rithu is currently working on a system to monitor and analyze dependencies between tasks within a project. Each task is represented as a node in a directed graph, and dependencies between tasks are represented as directed edges between nodes.



The goal is to help Rithu find the longest chain of tasks linked together in the project using the Depth-First Search (DFS) approach.

Input format :
The first line of input consists of two integers, "n" and "m," separated by a space. "n" represents the number of tasks in the project, and "m" represents the number of task dependencies (directed edges).

The next "m" lines each contain two integers, "u" and "v," separated by a space, indicating a task dependency where task "u" depends on task "v."

Output format :
The output displays a single integer representing the length of the longest chain of tasks in the project.



Refer to the sample output for the formatting specifications.

Code constraints :
The test cases will fall under the following constraints:

2 ≤ n ≤ 10

0 ≤ m ≤ n*(n-1)/2

1 ≤ u, v ≤ n, u ≠ v

Sample test cases :
Input 1 :
4 5
2 3 
1 3
1 4
1 2
3 4
Output 1 :
3
Input 2 :
3 2
0 1
1 2
Output 2 :
1


// You are using GCC
#include <iostream>

#define MAXN 100

using namespace std;

int dfs(int node, int adj[][MAXN], int dp[], bool vis[], int n) {
    if (vis[node]) {
        return dp[node];
    }

    vis[node] = true;
    int maxPath = 0;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            maxPath = max(maxPath, 1 + dfs(i, adj, dp, vis, n));
        }
    }

    dp[node] = maxPath;
    return maxPath;
}

void addEdge(int adj[][MAXN], int u, int v) {
    adj[u][v] = 1;
}

int findLongestPath(int adj[][MAXN], int n) 
{
    //Type your code
}

int main() {
    int n, m;  
    cin >> n;
    
    int adj[MAXN][MAXN] = {0};
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u - 1, v - 1); 
    }

    cout << findLongestPath(adj, n);
    return 0;
}
*/


#include <iostream>
#include <algorithm>
#define MAXN 100
using namespace std;

int dfs(int node, int adj[][MAXN], int dp[], bool vis[], int n) {
    if (vis[node]) {
        return dp[node];
    }
    vis[node] = true;
    int maxPath = 0;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            maxPath = max(maxPath, 1 + dfs(i, adj, dp, vis, n));
        }
    }
    dp[node] = maxPath;
    return maxPath;
}

void addEdge(int adj[][MAXN], int u, int v) {
    adj[u][v] = 1;
}

int findLongestPath(int adj[][MAXN], int n) {
    int dp[MAXN] = {0};
    bool vis[MAXN] = {false};
    int longestPath = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            longestPath = max(longestPath, dfs(i, adj, dp, vis, n));
        }
    }

    return longestPath;
}

int main() {
    int n, m;  
    cin >> n >> m;
    
    int adj[MAXN][MAXN] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u - 1, v - 1); 
    }

    cout << findLongestPath(adj, n);
    return 0;
}


