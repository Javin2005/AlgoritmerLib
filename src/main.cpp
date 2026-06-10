#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include "runner/run_algorithm.hpp"

using namespace std;

struct AlgorithmEntry
{
    string name;
    void (*function)();
};

int main()
{
    const vector<AlgorithmEntry> algorithms = {
        {"Gale-Shapley (Stable Matching)", runGaleShapley},
        {"BFS (Breadth-First Search)", runBFS},
        {"DFS (Depth-First Search)", runDFS},
        {"Interval Scheduling (Greedy)", runIntervalScheduling},
        {"Dijkstras (Shortest Path)", runDijkstras},
        {"Kruskals (MST)", runKruskals},
        {"MergeSort (Divide and Conquer)", runMergeSort},
        {"Closest Points (Divide and Conquer)", runClosestPoints}};

    while (true)
    {
        cout << "\n"
             << string(45, '=') << endl;
        cout << "    ALGORITHM LABORATORY COMMAND CENTER" << endl;
        cout << string(45, '=') << endl;

        for (size_t i = 0; i < algorithms.size(); ++i)
        {
            cout << "  " << setw(2) << i + 1 << ". " << algorithms[i].name << endl;
        }

        cout << "   0. Exit" << endl;
        cout << string(45, '-') << endl;
        cout << "  Select [0-" << algorithms.size() << "]: ";

        int choice;
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 0)
            break;

        if (choice >= 1 && choice <= static_cast<int>(algorithms.size()))
        {
            algorithms[choice - 1].function();
        }
        else
        {
            cout << "\n  [!] Invalid selection. Please try again." << endl;
        }
    }

    cout << "\n  Exiting laboratory. Goodbye!" << endl;
    return 0;
}