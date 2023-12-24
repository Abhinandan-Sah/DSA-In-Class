/*
Problem Statement



In an academic institution, courses are organized such that some courses are prerequisites for others. The course curriculum can be represented as a graph, where each course is a node and prerequisites between courses are edges.



Your task is to implement a program that uses Breadth-First Search (BFS) traversal to discover and map these dependencies, starting with a specified course.

Input format :
The first line of input consists of two space-separated integers, V and E, representing the total number of courses and prerequisites, respectively.

The next lines of input consists of two space-separated integers, Details about each prerequisite are represented by two integers u and v, where u is a prerequisite for course v.

Output format :
The output should display the discovered courses in the order they were visited during the BFS traversal, separated by spaces. This provides a map of the course dependencies, showing which courses are prerequisites for others.

Code constraints :
The test cases will fall under the following constraints:

1 <= V <= 10

0 <= E <= V*(V-1)/2

0 <= u, v < V

Sample test cases :
Input 1 :
6 8
0 1
0 2
1 3
2 3
2 4
3 4
4 5
5 0
Output 1 :
0 1 2 3 4 5 



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
