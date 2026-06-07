#include "run_algorithm.hpp"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#include "../stabil_matching/gale_shapley.hpp"
#include "../graphs/bfs.hpp"
#include "../graphs/dfs.hpp"
#include "../greedy/interval_scheduling.hpp"
#include "../greedy/dijkstras.hpp"
#include "../utils/load_data.hpp"
#include "../utils/generate_data.hpp"
#include "../utils/timer.hpp"

using namespace std;

void runGaleShapley()
{
    string path = "../data/stabil_matching/large_test.txt";
    int element, n;
    cout << "\n--- Gale-Shapley (Stable Matching) ---" << endl;
    cout << "How many elements per group: ";
    cin >> element;

    generateLargeGaleShapley(element, path);

    vector<vector<int>> prefA, prefB;
    if (loadGaleShapleyData(path, n, prefA, prefB))
    {
        map<int, int> matches;
        double time = measureExecution([&]()
                                       { matches = StabilMatching::solveGaleShapley(n, prefA, prefB); });
        cout << "Finished in " << time << " ms. Matches found: " << matches.size() << endl;
    }
}

void runBFS()
{
    string path = "../data/graphs/large_bfs_test.txt";
    int n_nodes, n;
    cout << "\n--- Breadth-First Search ---" << endl;
    cout << "Amount of nodes: ";
    cin >> n_nodes;

    generateRandomGraph(n_nodes, 2, path);

    vector<vector<int>> adj;
    if (loadGraphData(path, n, adj))
    {
        Graphs::BFSResult res;
        double time = measureExecution([&]()
                                       { res = Graphs::solveBFS(0, adj); });
        cout << "BFS finished in " << time << " ms." << endl;
        cout << "First 10 nodes visited: ";
        for (int i = 0; i < min((int)res.traversalOrder.size(), 10); i++)
        {
            cout << res.traversalOrder[i] << " ";
        }
        cout << endl;
    }
}

void runDFS()
{
    string path = "../data/graphs/large_dfs_test.txt";
    int n_nodes, n;
    cout << "\n--- Depth-First Search ---" << endl;
    cout << "Amount of nodes: ";
    cin >> n_nodes;

    generateRandomGraph(n_nodes, 2, path);

    vector<vector<int>> adj;
    if (loadGraphData(path, n, adj))
    {
        Graphs::DFSResult res;
        double time = measureExecution([&]()
                                       { res = Graphs::solveDFS(0, adj); });
        cout << "DFS finished in " << time << " ms." << endl;
        cout << "First 10 nodes visited: ";
        for (int i = 0; i < min((int)res.traversalOrder.size(), 10); i++)
        {
            cout << res.traversalOrder[i] << " ";
        }
        cout << endl;
    }
}

void runIntervalScheduling()
{
    string path = "../data/greedy/large_intervals_test.txt";
    int n_intervals, n;
    cout << "\n--- Interval Scheduling ---" << endl;
    cout << "How many intervals to generate: ";
    cin >> n_intervals;

    generateIntervalData(n_intervals, 1000000, path);
    vector<Greedy::Interval> intervals;
    if (loadIntervalData(path, n, intervals))
    {
        vector<Greedy::Interval> res;
        double time = measureExecution([&]()
                                       { res = Greedy::solveIntervalScheduling(intervals); });

        cout << "Scheduled " << res.size() << " of " << n << " intervals." << endl;
        cout << "Time: " << time << " ms" << endl;
        cout << "First 5 selected intervals:" << endl;
        for (int i = 0; i < min((int)res.size(), 5); i++)
        {
            cout << "  [" << res[i].start << " -> " << res[i].end << "]" << endl;
        }
    }
}

void runDijkstras()
{
    string path = "../data/greedy/large_dijkstra_test.txt";
    int n_nodes, n;
    cout << "\n--- Dijkstra's Algorithm ---" << endl;
    cout << "How many nodes: ";
    cin >> n_nodes;

    generateWeightedGraph(n_nodes, 3, path);

    vector<vector<Greedy::Edge>> adj;
    if (loadWeightedGraphData(path, n, adj))
    {
        Greedy::DijkstraResult res;
        double time = measureExecution([&]()
                                       { res = Greedy::solveDijkstra(0, adj); });

        cout << "Dijkstra finished in " << time << " ms" << endl;
        cout << "Shortest distances from node 0 (first 10):" << endl;
        for (int i = 0; i < min(n, 10); i++)
        {
            cout << "  Node " << i << ": ";
            if (res.distances[i] == numeric_limits<int>::max())
                cout << "Unreachable";
            else
                cout << res.distances[i];
            cout << endl;
        }
    }
}