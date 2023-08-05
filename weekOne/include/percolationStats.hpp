#pragma once
#include "percolation.hpp"

class PercolationStats{
private:
    int trials;
    

public:
    double* result;
    PercolationStats(int n, int trials);
    double mean();
    double stddev();
    double confidenceLo();
    double confidenceHi();
};