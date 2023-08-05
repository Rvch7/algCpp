#include "percolationStats.hpp"
#include "percolation.hpp"
#include <math.h>


PercolationStats::PercolationStats(int n, int trial) : trials{trial}{
    result = new double[trial];
    srand(time(0));
    int r,c;
    for (int i = 0; i < trial; i++)
    {
        percolation pr(n);
        while(!pr.percolates()){
            r = rand()%n;
            c = rand()%n;
            pr.open(r,c);
        }
        result[i] = (double)pr.numberOfOpenSites()/(n*n);
    }
}

double PercolationStats::mean(){
    double avg;
    for (int i = 0; i < trials; i++)
    { 
        avg += result[i];
    }

    return avg/trials;
}

double PercolationStats::stddev(){
    double mul;
    double avg;
    double mean = PercolationStats::mean();
    for (int i = 0; i < trials; i++)
    {
        mul = (result[i] - mean);
        mul *= mul;
        avg += mul;
    }
    return avg/(trials-1);
}

double PercolationStats::confidenceLo(){
    double mean = PercolationStats::mean();
    double stddev = PercolationStats::stddev();
    double sqTr = sqrt(trials);

    return mean - ((1.96*stddev)/sqTr);
}

double PercolationStats::confidenceHi(){
    double mean = PercolationStats::mean();
    double stddev = PercolationStats::stddev();
    double sqTr = sqrt(trials);

    return mean + ((1.96*stddev)/sqTr);
}