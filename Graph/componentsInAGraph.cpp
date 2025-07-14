#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<int> adjList[], int node, vector<bool> &visited, int &componentSize)
    {
        visited[node] = true;
        componentSize++;

        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfs(adjList, neighbor, visited, componentSize);
            }
        }
    }

    vector<int> connectedComponents(vector<int> adjList[], int maxVertex)
    {
        vector<bool> visited(maxVertex + 1, false);
        vector<int> componentSizes;

        for (int i = 1; i <= maxVertex; i++)
        {
            if (!visited[i] && !adjList[i].empty())
            {
                int componentSize = 0;
                dfs(adjList, i, visited, componentSize);
                if (componentSize >= 2)
                {
                    componentSizes.push_back(componentSize);
                }
            }
        }

        int minSize = *min_element(componentSizes.begin(), componentSizes.end());
        int maxSize = *max_element(componentSizes.begin(), componentSizes.end());

        return {minSize, maxSize};
    }
};

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> bg(N, vector<int>(2));
    int maxVertex = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> bg[i][0] >> bg[i][1];
        maxVertex = max(maxVertex, max(bg[i][0], bg[i][1]));
    }

    vector<int> adjList[maxVertex + 1];

    for (int i = 0; i < N; i++)
    {
        int u = bg[i][0];
        int v = bg[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    Solution soln;

    vector<int> result = soln.connectedComponents(adjList, maxVertex);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}