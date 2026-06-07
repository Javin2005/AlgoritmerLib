#include <iostream>
#include "runner/run_algorithm.hpp"

using namespace std;

int main()
{
    while (true)
    {
        cout << "\n--- Algorithm Laboratory ---" << endl;
        cout << "1. Gale-Shapley (Stable Matching)" << endl;
        cout << "2. BFS (Breadth-First Search)" << endl;
        cout << "3. DFS (Depth-First Search)" << endl;
        cout << "4. Interval Scheduling (Greedy)" << endl;
        cout << "5. Dijkstras (Shortest Path)" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an algorithm: ";

        int choice;
        if (!(cin >> choice))
            break;
        if (choice == 0)
            break;

        switch (choice)
        {
        case 1:
            runGaleShapley();
            break;
        case 2:
            runBFS();
            break;
        case 3:
            runDFS();
            break;
        case 4:
            runIntervalScheduling();
            break;
        case 5:
            runDijkstras();
            break;
        default:
            cout << "Invalid choice, try again." << endl;
            break;
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}