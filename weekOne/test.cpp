#include "include/percolationStats.hpp"
#include <assert.h>



int main(int argc, char const *argv[])
{
    int N = 1000;
    int trials = 10;

    PercolationStats PS(N,trials);
    std::cout << "mean: " << PS.mean() << std::endl;
    std::cout << "stddev: " << PS.stddev() << std::endl;
    std::cout << "95 per confidence interval : [" << PS.confidenceLo() << ", " << PS.confidenceHi() << " ]" << std::endl;


    // percolation pr(N);
    
    
    // std::cout << pr.isOpen(0,0) << std::endl;
    // std::cout << pr.isOpen(N-1,N-1) << std::endl;
    

    // std::cout << pr.numberOfOpenSites() << std::endl;

    // pr.open(1,1);
    // pr.open(0,1);
    // pr.open(N-1, N-1);

    // pr. open(5,5);

    // pr.open(5,4);
    // std::cout << pr.isOpen(0,0) << std::endl;
    // std::cout << pr.isOpen(N-1,N-1) << std::endl;

    // std::cout << pr.numberOfOpenSites() << std::endl;
    // srand(time(0));
    // std::cout << (rand()%N) << std::endl;

    return 0;
}
