#include "dfs.hpp"

using namespace std;
namespace Graphs
{
    void dfsRecursive(int u, const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order)
    {
        visited[u] = true;
        order.push_back(u);

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                dfsRecursive(v, adj, visited, order);
            }
        }
    }

    DFSResult solveDFS(int startNode, const vector<vector<int>> &adj)
    {
        int n = adj.size();
        DFSResult result;
        result.visited.assign(n, false);

        if (n > 0)
        {
            dfsRecursive(startNode, adj, result.visited, result.traversalOrder);
        }

        return result;
    }
}