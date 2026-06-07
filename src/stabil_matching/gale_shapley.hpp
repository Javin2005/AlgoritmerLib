#ifndef GALE_SHAPLEY_HPP
#define GALE_SHAPLEY_HPP

#include <vector>
#include <map>
#include <string>

namespace StabilMatching
{
    // Vi returnerar en map där nyckeln är personen i Grupp B och värdet är personen i Grupp A
    std::map<int, int> solveGaleShapley(
        int n,
        std::vector<std::vector<int>> &prefA,
        std::vector<std::vector<int>> &prefB);
}

#endif