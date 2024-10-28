/*
Sanju loves graph theory and has recently started learning about Breadth-First Search (BFS) algorithms. He is given a directed graph represented as an adjacency matrix, and he wants to implement the BFS algorithm to traverse the graph starting from a given vertex.

Input format :
The first line of input consists of the two integers, V and E, separated by a space, representing the number of vertices and edges in the network, respectively.

The next E lines consist of two integers, u and v, separated by a space, representing an edge between vertex u and vertex v.

Output format :
The output displays a single line containing the vertices visited during the BFS traversal, separated by a space.

Code constraints :
The test cases will fall under the following constraints:

1 <= V <= 10

0 <= E <= V*(V-1)/2

0 <= u, v < V

Sample test cases :
Input 1 :
5 4
0 1
0 2 
0 3
2 4
Output 1 :
0 1 2 3 4 
Input 2 :
3 2
0 1
0 2
Output 2 :
0 1 2 


// You are using GCC
#include <iostream>
using namespace std;

#define MAX_V 100

void enqueue(int* queue, int& rear, int vertex) {
    queue[++rear] = vertex;
}

int dequeue(int* queue, int& front) {
    return queue[++front];
}

void bfsOfGraph(int V, int adjList[MAX_V][MAX_V]) 
{
    //Write your code here
}

int main() {
    int V, E;
    cin >> V >> E;

    int adjList[MAX_V][MAX_V] = {0};

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
    }

    bfsOfGraph(V, adjList);

    return 0;
}
*/


#include <iostream>
using namespace std;
#define MAX_V 100

void enqueue(int* queue, int& rear, int vertex) {
    queue[++rear] = vertex;
}

int dequeue(int* queue, int& front) {
    return queue[++front];
}

void bfsOfGraph(int V, int adjList[MAX_V][MAX_V]) {
    int queue[MAX_V];
    int front = -1, rear = -1;
    bool visited[MAX_V] = {false};

    int startVertex;
    // cout << "Enter the starting vertex: ";
    cin >> startVertex;

    // cout << "BFS Traversal: ";
    enqueue(queue, rear, startVertex);
    visited[startVertex] = true;

    while (front != rear) {
        int currentVertex = dequeue(queue, front);
        cout << currentVertex << " ";

        for (int i = 0; i < V; ++i) {
            if (adjList[currentVertex][i] == 1 && !visited[i]) {
                enqueue(queue, rear, i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
}

int main() {
    int V, E;
    cin >> V >> E;
    int adjList[MAX_V][MAX_V] = {0};

    // cout << "Enter the edges:\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
    }

    bfsOfGraph(V, adjList);

    return 0;
}



