#include "load_data.hpp"
#include <fstream>
#include <iostream>

using namespace std;

static bool openFile(ifstream &file, const string &filename)
{
    file.open(filename);
    if (!file.is_open())
    {
        cerr << "  [Error] Failed to open: " << filename << endl;
        return false;
    }
    return true;
}

bool loadPointPlane(const string &filename, int &n, vector<DivideAndConquer::Point> &points)
{
    ifstream file;
    if (!openFile(file, filename))
        return false;
    file >> n;
    points.clear();
    points.reserve(n);
    for (int i = 0; i < n; i++)
    {
        double x, y;
        file >> x >> y;
        points.push_back({x, y});
    }
    return true;
}

bool loadListData(const string &filename, int &n, vector<int> &list)
{
    ifstream file;
    if (!openFile(file, filename))
        return false;
    file >> n;
    list.clear();
    list.reserve(n);
    int val;
    while (file >> val)
        list.push_back(val);
    return true;
}

bool loadEdgeListData(const string &filename, int &n, vector<Greedy::KruskalEdge> &edges)
{
    ifstream file;
    if (!openFile(file, filename))
        return false;
    file >> n;
    edges.clear();
    int u, numNeighbors, v, weight;
    while (file >> u >> numNeighbors)
    {
        for (int i = 0; i < numNeighbors; i++)
        {
            file >> v >> weight;
            if (u < v)
                edges.push_back({u, v, weight});
        }
    }
    return true;
}

bool loadWeightedGraphData(const string &filename, int &n, vector<vector<Greedy::DijkstraEdge>> &adj)
{
    ifstream file;
    if (!openFile(file, filename))
        return false;
    file >> n;
    adj.assign(n, vector<Greedy::DijkstraEdge>());
    int u, numNeighbors, v, weight;
    while (file >> u >> numNeighbors)
    {
        for (int i = 0; i < numNeighbors; i++)
        {
            file >> v >> weight;
            adj[u].push_back({v, weight});
        }
    }
    return true;
}

bool loadIntervalData(const string &filename, int &n, vector<Greedy::Interval> &intervals)
{
    ifstream file;
    if (!openFile(file, filename))
        return false;
    file >> n;
    intervals.clear();
    for (int i = 0; i < n; i++)
    {
        int s, e;
        file >> s >> e;
        intervals.push_back({s, e, i});
    }
    return true;
}

bool loadGaleShapleyData(const string &filename, int &n, vector<vector<int>> &prefA, vector<vector<int>> &prefB)
{
    ifstream file;
    if (!openFile(file, filename))
        return false;
    file >> n;
    auto readPrefs = [&](vector<vector<int>> &target)
    {
        target.assign(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                file >> target[i][j];
    };
    readPrefs(prefA);
    readPrefs(prefB);
    return true;
}

bool loadGraphData(const string &filename, int &n, vector<vector<int>> &adj)
{
    ifstream file;
    if (!openFile(file, filename))
        return false;
    file >> n;
    adj.assign(n, vector<int>());
    int u, numNeighbors, v;
    while (file >> u >> numNeighbors)
    {
        for (int i = 0; i < numNeighbors; i++)
        {
            file >> v;
            adj[u].push_back(v);
        }
    }
    return true;
}