#ifndef GENERATE_DATA_HPP
#define GENERATE_DATA_HPP

#include <string>

void generateLargeGaleShapley(int n, const std::string &filename);
void generateRandomGraph(int n, int edgesPerNode, const std::string &filename);
void generateIntervalData(int n, int maxRange, const std::string &filename);
void generateWeightedGraph(int n, int edgesPerNode, const std::string &filename);
void generateRandomList(int n, const std::string &filename);
void generatePointsInPlane(int n, const std::string &filename);

#endif