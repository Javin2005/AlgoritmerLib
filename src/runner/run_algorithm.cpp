#include "run_algorithm.hpp"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <string>

#include "../stabil_matching/gale_shapley.hpp"
#include "../graphs/bfs.hpp"
#include "../graphs/dfs.hpp"
#include "../greedy/interval_scheduling.hpp"
#include "../greedy/dijkstras.hpp"
#include "../greedy/kruskals.hpp"
#include "../divide_and_conquer/mergesort.hpp"
#include "../divide_and_conquer/closest_point.hpp"
#include "../utils/load_data.hpp"
#include "../utils/generate_data.hpp"
#include "../utils/timer.hpp"

using namespace std;

void printSectionHeader(const string &title)
{
    cout << "\n"
         << string(60, '=') << endl;
    cout << "  " << title << endl;
    cout << string(60, '=') << endl;
}

void printStat(const string &label, const string &value)
{
    cout << "  " << left << setw(25) << label << ": " << value << endl;
}

void printStat(const string &label, double value, const string &unit = "")
{
    cout << "  " << left << setw(25) << label << ": " << fixed << setprecision(3) << value << " " << unit << endl;
}

void runGaleShapley()
{
    printSectionHeader("GALE-SHAPLEY STABLE MATCHING");
    string path = "../data/stabil_matching/large_test.txt";
    int n, element;

    cout << "  Enter elements per group: ";
    cin >> element;

    generateLargeGaleShapley(element, path);

    vector<vector<int>> prefA, prefB;
    if (loadGaleShapleyData(path, n, prefA, prefB))
    {
        map<int, int> matches;
        double time = measureExecution([&]()
                                       { matches = StabilMatching::solveGaleShapley(n, prefA, prefB); });

        printStat("Input size (n)", to_string(n));
        printStat("Execution time", time, "ms");
        printStat("Total matches", to_string(matches.size()));
    }
}

void runBFS()
{
    printSectionHeader("BREADTH-FIRST SEARCH");
    string path = "../data/graphs/large_bfs_test.txt";
    int n, n_nodes;

    cout << "  Enter number of nodes: ";
    cin >> n_nodes;

    generateRandomGraph(n_nodes, 2, path);

    vector<vector<int>> adj;
    if (loadGraphData(path, n, adj))
    {
        Graphs::BFSResult res;
        double time = measureExecution([&]()
                                       { res = Graphs::solveBFS(0, adj); });

        printStat("Nodes processed", n);
        printStat("Execution time", time, "ms");
        cout << "  First 10 nodes: ";
        for (int i = 0; i < min((int)res.traversalOrder.size(), 10); i++)
            cout << res.traversalOrder[i] << " ";
        cout << endl;
    }
}

void runDFS()
{
    printSectionHeader("DEPTH-FIRST SEARCH");
    string path = "../data/graphs/large_dfs_test.txt";
    int n, n_nodes;

    cout << "  Enter number of nodes: ";
    cin >> n_nodes;

    generateRandomGraph(n_nodes, 2, path);

    vector<vector<int>> adj;
    if (loadGraphData(path, n, adj))
    {
        Graphs::DFSResult res;
        double time = measureExecution([&]()
                                       { res = Graphs::solveDFS(0, adj); });

        printStat("Nodes processed", n);
        printStat("Execution time", time, "ms");
        cout << "  First 10 nodes: ";
        for (int i = 0; i < min((int)res.traversalOrder.size(), 10); i++)
            cout << res.traversalOrder[i] << " ";
        cout << endl;
    }
}

void runIntervalScheduling()
{
    printSectionHeader("GREEDY INTERVAL SCHEDULING");
    string path = "../data/greedy/large_intervals_test.txt";
    int n, n_intervals;

    cout << "  Enter amount of intervals: ";
    cin >> n_intervals;

    generateIntervalData(n_intervals, 1000000, path);

    vector<Greedy::Interval> intervals;
    if (loadIntervalData(path, n, intervals))
    {
        vector<Greedy::Interval> res;
        double time = measureExecution([&]()
                                       { res = Greedy::solveIntervalScheduling(intervals); });

        printStat("Total candidates", n);
        printStat("Scheduled items", (int)res.size());
        printStat("Execution time", time, "ms");
    }
}

void runDijkstras()
{
    printSectionHeader("DIJKSTRA'S SHORTEST PATH");
    string path = "../data/greedy/large_dijkstra_test.txt";
    int n, n_nodes;

    cout << "  Enter number of nodes: ";
    cin >> n_nodes;

    generateWeightedGraph(n_nodes, 3, path);

    vector<vector<Greedy::DijkstraEdge>> adj;
    if (loadWeightedGraphData(path, n, adj))
    {
        Greedy::DijkstraResult res;
        double time = measureExecution([&]()
                                       { res = Greedy::solveDijkstra(0, adj); });

        printStat("Nodes", n);
        printStat("Execution time", time, "ms");
        cout << "  Distances from node 0 (first 5 nodes):" << endl;
        for (int i = 0; i < min(n, 5); i++)
        {
            string d = (res.distances[i] == numeric_limits<int>::max()) ? "INF" : to_string(res.distances[i]);
            printStat("  -> Node " + to_string(i), d);
        }
    }
}

void runKruskals()
{
    printSectionHeader("KRUSKAL'S MINIMUM SPANNING TREE");
    string path = "../data/greedy/large_kruskals_test.txt";
    int n, n_nodes;

    cout << "  Enter number of nodes: ";
    cin >> n_nodes;

    generateWeightedGraph(n_nodes, 3, path);

    vector<Greedy::KruskalEdge> edg;
    if (loadEdgeListData(path, n, edg))
    {
        Greedy::KruskalsResult res;
        double time = measureExecution([&]()
                                       { res = Greedy::solveKruskals(n, edg); });

        printStat("Nodes", n);
        printStat("Total edges", (int)edg.size());
        printStat("MST Total Weight", res.totalWeight);
        printStat("Execution time", time, "ms");
    }
}

void runMergeSort()
{
    printSectionHeader("MERGE SORT");
    string path = "../data/divide_and_conquer/large_list_test.txt";
    int n, size;

    cout << "  Enter list size: ";
    cin >> size;

    generateRandomList(size, path);

    vector<int> list;
    if (loadListData(path, n, list))
    {
        DivideAndConquer::mergeSortResult res;
        double time = measureExecution([&]()
                                       { res = DivideAndConquer::solveMergeSort(list); });

        printStat("List size", n);
        printStat("Recursive divides", res.amountOfDivides);
        printStat("Execution time", time, "ms");
        cout << "  Sorted sample: ";
        for (int i = 0; i < min(n, 5); i++)
            cout << res.SortedList[i] << " ";
        cout << "..." << endl;
    }
}

void runClosestPoints()
{
    printSectionHeader("CLOSEST PAIR OF POINTS");
    string path = "../data/divide_and_conquer/large_point_Plane_test.txt";
    int n, amount;

    cout << "  Enter point count: ";
    cin >> amount;

    generatePointsInPlane(amount, path);

    vector<DivideAndConquer::Point> points;
    if (loadPointPlane(path, n, points))
    {
        DivideAndConquer::ClosestResult res;
        double time = measureExecution([&]()
                                       { res = DivideAndConquer::solveClosestPoints(points); });

        printStat("Number of points", n);
        printStat("Min distance", res.dist);
        printStat("Point A", "(" + to_string(res.p1.x) + ", " + to_string(res.p1.y) + ")");
        printStat("Point B", "(" + to_string(res.p2.x) + ", " + to_string(res.p2.y) + ")");
        printStat("Execution time", time, "ms");
    }
}