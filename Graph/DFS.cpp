#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
void DFSofGraph(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);
    for (int neigh : adj[node])
    {
        if (!visited[neigh])
        {
            DFSofGraph(neigh, adj, visited, component);
        }
    }
}
vector<vector<int>> DFS(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj = adjList(V, edges);
    vector<vector<int>> ans;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            DFSofGraph(i, adj, visited, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{
    int V = 6; 
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {3, 4}, {4, 5}};

    vector<vector<int>> dfsTraversals = DFS(V, edges);

    cout << "DFS Traversals of all connected components:\n";
    for (int i = 0; i < dfsTraversals.size(); i++)
    {
        cout << "Component " << i + 1 << ": ";
        for (int node : dfsTraversals[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}