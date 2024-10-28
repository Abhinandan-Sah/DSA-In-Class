/*
Alex is creating an application for managing files on a computer. Each directory in the system is considered a node in the graph, and the files are edges connecting the directories.



Your job is to assist Alex in developing a program that should start from a specified root directory and explore the file system using Depth First Traversal, listing the directories and files encountered.

Input format :
The first line consists of two integers, "V" and "E," separated by a space. "V" represents the number of directories or nodes in the file system, and "E" represents the number of connections (edges) between directories.

The next "E" lines each contain two integers, "v" and "w," separated by a space. These integers indicate a connection between directory "v" and directory "w."

The last line consists of a single integer, "startVertex," representing the root directory where the exploration should begin.

Output format :
The output displays a message indicating "Depth First Traversal starting from vertex [startVertex]:" on a new line.

where [startVertex] is the integer representing the root directory.

After that, it should list the visited directories and files in DFS traversal order, separated by spaces.



Refer to the sample output for the exact format.

Code constraints :
The test cases will fall under the following constraints:

2 ≤ V ≤ 10

0 <= E <= V*(V-1)/2

0 <= v, w < V

0 <= startVertex <= V

Sample test cases :
Input 1 :
5 6
0 1
0 2
1 3
2 4
3 1
4 2
0
Output 1 :
Depth First Traversal starting from vertex 0:
0 1 3 2 4 
Input 2 :
4 6
2 0
0 2
1 2
0 1
3 0
1 3
2
Output 2 :
Depth First Traversal starting from vertex 2:
2 0 1 3 


// You are using GCC
#include <iostream>
using namespace std;
#define MAX_VERTICES 100

void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int v, int w) {
    adj[v][w] = 1;
}

void DFS(int adj[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int V, int v) 
{
    //Write your code
}

int main() {
    int V, E;
    cin >> V;
    cin >> E;

    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        addEdge(adj, v, w);
    }

    int startVertex;
    cin >> startVertex;

    cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
    DFS(adj, visited, V, startVertex);

    return 0;
}
*/



#include <iostream>
#include <vector>
using namespace std;

#define MAX_VERTICES 100

void addEdge(vector<vector<int>>& adj, int v, int w) {
    adj[v][w] = 1;
}

void DFS(vector<vector<int>>& adj, vector<int>& visited, int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 0; i < adj.size(); ++i) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(adj, visited, i);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(MAX_VERTICES, vector<int>(MAX_VERTICES, 0));
    vector<int> visited(MAX_VERTICES, 0);

    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        addEdge(adj, v, w);
    }

    int startVertex;
    cin >> startVertex;
    cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
    DFS(adj, visited, startVertex);
    cout << endl;

    return 0;
}
