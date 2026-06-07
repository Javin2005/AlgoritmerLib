#ifndef DFS_HPP
#define DFS_HPP

#include <vector>

namespace Graphs
{
    struct DFSResult
    {
        std::vector<int> traversalOrder;
        std::vector<bool> visited;
    };

    DFSResult solveDFS(int startNode, const std::vector<std::vector<int>> &adj);
}
#endif