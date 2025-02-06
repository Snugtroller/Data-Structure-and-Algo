#include <bits/stdc++.h>
#include <queue>
using namespace std;
void adjList(vector<vector<int>> &adj, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
vector<int> BFSList(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int node)
{
    vector<int> ans;
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (int neigh : adj[frontNode])
        {
            if (!visited[neigh])
            {
                q.push(neigh);
                visited[neigh] = true;
            }
        }
    }
    return ans;
}
vector<int> BFS(vector<vector<int>> &adj, vector<pair<int, int>> &edges, int V)
{
    unordered_map<int, bool> visited;
    int node = 0;
    adjList(adj, edges);
    return BFSList(adj, visited, node);
}

int main()
{
    int V = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};

    vector<vector<int>> adj(V);
    vector<int> bfsResult = BFS(adj, edges, V);

    cout << "BFS Traversal: ";
    for (int node : bfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}