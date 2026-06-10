#ifndef LOAD_DATA_HPP
#define LOAD_DATA_HPP

#include <vector>
#include <string>
#include <map>
#include "../greedy/interval_scheduling.hpp"
#include "../greedy/dijkstras.hpp"
#include "../greedy/kruskals.hpp"
#include "../divide_and_conquer/closest_point.hpp"

bool loadPointPlane(const std::string &filename, int &n, std::vector<DivideAndConquer::Point> &points);
bool loadListData(const std::string &filename, int &n, std::vector<int> &list);
bool loadEdgeListData(const std::string &filename, int &n, std::vector<Greedy::KruskalEdge> &edges);
bool loadWeightedGraphData(const std::string &filename, int &n, std::vector<std::vector<Greedy::DijkstraEdge>> &adj);
bool loadIntervalData(const std::string &filename, int &n, std::vector<Greedy::Interval> &intervals);
bool loadGaleShapleyData(const std::string &filename, int &n, std::vector<std::vector<int>> &prefA, std::vector<std::vector<int>> &prefB);
bool loadGraphData(const std::string &filename, int &n, std::vector<std::vector<int>> &adj);

#endif