#ifndef GENERATE_DATA_HPP
#define GENERATE_DATA_HPP

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

void generateLargeGaleShapley(int n, string filename)
{
    ofstream file(filename);
    file << n << endl;

    vector<int> prefs(n);
    iota(prefs.begin(), prefs.end(), 0);

    random_device rd;
    mt19937 g(rd());

    for (int i = 0; i < n; i++)
    {
        shuffle(prefs.begin(), prefs.end(), g);
        for (int val : prefs)
        {
            file << val << " ";
        }
        file << endl;
    }

    for (int i = 0; i < n; i++)
    {
        shuffle(prefs.begin(), prefs.end(), g);
        for (int val : prefs)
        {
            file << val << " ";
        }
        file << endl;
    }

    file.close();
    cout << "Filen " << filename << " med n=" << n << " har skapats!" << endl;
}

void generateRandomGraph(int n, int edgesPerNode, string filename)
{
    ofstream file(filename);
    if (!file.is_open())
        return;

    file << n << endl;

    random_device rd;
    mt19937 g(rd());

    uniform_int_distribution<int> dist(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        file << i << " " << edgesPerNode << " ";
        for (int j = 0; j < edgesPerNode; j++)
        {
            int neighbor = dist(g);

            while (neighbor == i)
                neighbor = dist(g);
            file << neighbor << " ";
        }
        file << endl;
    }
    file.close();
    cout << "Graf med " << n << " noder skapad i " << filename << endl;
}

#endif