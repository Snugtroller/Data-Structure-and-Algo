#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int start, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, vector<vector<int>> &adj)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neigh : adj[frontNode])
        {
            if (!visited[neigh])
            {
                visited[neigh] = true;
                parent[neigh] = frontNode;
                q.push(neigh);
            }
            else if (neigh != parent[frontNode])
            {
                return true; // Cycle detected
            }
        }
    }
    return false;
}

bool CycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n); // Initialize adjacency list with 'n' empty lists
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCyclic(i, visited, parent, adj))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    bool hasCycle = CycleDetection(edges, n, m);

    if (hasCycle)
    {
        cout << "Graph contains a cycle" << endl;
    }
    else
    {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
