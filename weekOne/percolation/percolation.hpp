#include <vector>
#include "../weightedUnionFind.hpp"
using Grid = std::vector<std::vector<int>>;
enum spot_status {full, open};

class percolation{
private:
    int n;
    Grid spots;
    int openSpots;
    int virTop;
    int virBot;
    WeightedUF wuf;

public:
    percolation(int n);
    void open(int r, int c);
    bool isOpen(int r, int c);
    bool isFull(int r, int c);
    int numberOfOpenSites();
    bool percolates();

};