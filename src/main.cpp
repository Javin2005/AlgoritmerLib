#include <iostream>
#include "stabil_matching/gale_shapley.hpp"
#include "graphs/bfs.hpp"
#include "graphs/dfs.hpp"
#include "utils/generate_data.hpp"
#include <chrono>

#include <fstream>
using namespace std;

bool loadGaleShapleyData(string filename, int &n, vector<vector<int>> &prefA,
                         vector<vector<int>> &prefB)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Kunde inte öppna filen: " << filename << endl;
        return false;
    }

    file >> n;

    prefA.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> prefA[i][j];
        }
    }

    prefB.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> prefB[i][j];
        }
    }

    file.close();
    return true;
}

bool loadGraphData(string filename, int &n, vector<vector<int>> &adj)
{
    ifstream file(filename);
    if (!file.is_open())
        return false;

    file >> n;
    adj.assign(n, vector<int>());

    for (int i = 0; i < n; i++)
    {
        int nodeID, numNeighbors;
        file >> nodeID >> numNeighbors;
        for (int j = 0; j < numNeighbors; j++)
        {
            int neighbor;
            file >> neighbor;
            adj[nodeID].push_back(neighbor);
        }
    }
    file.close();
    return true;
}

int main()
{
    cout << "1. Gale-Shapley" << endl;
    cout << "2. BFS (Breadth-First Search)" << endl;
    cout << "3. DFS (Depth-First Search)" << endl;
    cout << "Välj algoritm:" << endl;

    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        string path = "../data/stabil_matching/large_test.txt";

        cout << "Hur många element: ";
        int element;
        cin >> element;

        generateLargeGaleShapley(element, path);

        int n;
        vector<vector<int>> prefA, prefB;

        if (loadGaleShapleyData(path, n, prefA, prefB))
        {
            auto start = chrono::high_resolution_clock::now();

            auto matches = StabilMatching::solveGaleShapley(n, prefA, prefB);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, milli> duration = end - start;

            cout << "Stabila matchingar hittade för n=" << n << ":" << endl;
            cout << "Tid det tog: " << duration.count() << " ms" << endl;
            int count = 0;
            for (auto const &[b, a] : matches)
            {
                if (count < 5)
                    cout << "Person B" << b << " matches med Person A" << a << endl;
                count++;
            }
            cout << "... och " << n - 5 << " till." << endl;
        }
    }

    if (choice == 2)
    {
        cout << "Hur många noder ska grafen ha: ";
        int n_nodes;
        cin >> n_nodes;

        string path = "../data/graphs/large_bfs_test.txt";
        generateRandomGraph(n_nodes, 2, path);

        int n;
        vector<vector<int>> adj;
        if (loadGraphData(path, n, adj))
        {
            cout << "Graf inläst! Redo att köra BFS." << endl;
            auto start = chrono::high_resolution_clock::now();

            auto res = Graphs::solveBFS(0, adj);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            cout << "BFS klar på " << duration.count() << " ms" << endl;
            cout << "Besöksordning (första 10): ";
            for (int i = 0; i < min((int)res.traversalOrder.size(), 10); i++)
            {
                cout << res.traversalOrder[i] << " ";
            }
            cout << endl;
        }
    }

    if (choice == 3)
    {
        cout << "Hur många noder ska grafen ha: ";
        int n_nodes;
        cin >> n_nodes;

        string path = "../data/graphs/large_bfs_test.txt";
        generateRandomGraph(n_nodes, 2, path);

        int n;
        vector<vector<int>> adj;
        if (loadGraphData(path, n, adj))
        {
            cout << "Graf inläst! Redo att köra DFS." << endl;

            auto start = chrono::high_resolution_clock::now();

            auto res = Graphs::solveDFS(0, adj);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            cout << "DFS klar på " << duration.count() << " ms" << endl;
            cout << "Besöksordning (första 10): ";
            for (int i = 0; i < min((int)res.traversalOrder.size(), 10); i++)
            {
                cout << res.traversalOrder[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}