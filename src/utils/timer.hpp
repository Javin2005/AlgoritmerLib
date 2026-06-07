#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <iostream>
#include <functional>

template <typename T>
double measureExecution(T func)
{
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

#endif