#include <iostream>
#include "stabil_matching/gale_shapley.hpp"

int main()
{
    std::cout << "Välj algoritm:" << std::endl;
    std::cout << "1. Gale-Shapley" << std::endl;

    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "Kör Gale-Shapley..." << std::endl;
    }

    return 0;
}