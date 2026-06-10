#include "generate_data.hpp"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

static mt19937 &get_rng()
{
    static random_device rd;
    static mt19937 g(rd());
    return g;
}

static ofstream openWriter(const string &filename, const string &msg, int n)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cerr << "  [Error] Could not create: " << filename << endl;
    }
    else
    {
        cout << "  [Data] " << msg << " (" << n << ") -> " << filename << endl;
    }
    return file;
}

void generateLargeGaleShapley(int n, const string &filename)
{
    auto file = openWriter(filename, "Gale-Shapley preferences", n);
    if (!file.is_open())
        return;
    file << n << endl;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < n; i++)
        {
            shuffle(p.begin(), p.end(), get_rng());
            for (int x : p)
                file << x << " ";
            file << endl;
        }
    }
}

void generateRandomGraph(int n, int edgesPerNode, const string &filename)
{
    auto file = openWriter(filename, "Unweighted graph", n);
    if (!file.is_open())
        return;
    file << n << endl;
    uniform_int_distribution<int> dist(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        file << i << " " << edgesPerNode << " ";
        for (int j = 0; j < edgesPerNode; j++)
        {
            int target = dist(get_rng());
            file << (target == i ? (target + 1) % n : target) << " ";
        }
        file << endl;
    }
}

void generateIntervalData(int n, int maxRange, const string &filename)
{
    auto file = openWriter(filename, "Intervals", n);
    if (!file.is_open())
        return;
    file << n << endl;
    uniform_int_distribution<int> sDist(0, maxRange - 11);
    uniform_int_distribution<int> dDist(1, 10);
    for (int i = 0; i < n; i++)
    {
        int s = sDist(get_rng());
        file << s << " " << s + dDist(get_rng()) << endl;
    }
}

void generateWeightedGraph(int n, int edgesPerNode, const string &filename)
{
    auto file = openWriter(filename, "Weighted graph", n);
    if (!file.is_open())
        return;
    file << n << endl;
    uniform_int_distribution<int> nDist(0, n - 1);
    uniform_int_distribution<int> wDist(1, 20);
    for (int i = 0; i < n; i++)
    {
        file << i << " " << edgesPerNode << " ";
        for (int j = 0; j < edgesPerNode; j++)
        {
            int target = nDist(get_rng());
            file << (target == i ? (target + 1) % n : target) << " " << wDist(get_rng()) << " ";
        }
        file << endl;
    }
}

void generateRandomList(int n, const string &filename)
{
    auto file = openWriter(filename, "Randomized list", n);
    if (!file.is_open())
        return;
    file << n << endl;
    uniform_int_distribution<int> dist(0, 1000000);
    for (int i = 0; i < n; i++)
        file << dist(get_rng()) << " ";
    file << endl;
}

void generatePointsInPlane(int n, const string &filename)
{
    auto file = openWriter(filename, "2D Points", n);
    if (!file.is_open())
        return;
    file << n << endl;
    uniform_real_distribution<double> dist(-10000.0, 10000.0);
    for (int i = 0; i < n; i++)
        file << dist(get_rng()) << " " << dist(get_rng()) << endl;
}