#pragma once

#include <vector>
#include <iostream>
#include "weightedUnionFind.hpp"



enum spot_status {full, open};

class percolation{
private:
    WeightedUF uf;
    int numofSpots;
    int openSpots = 0;
    bool* status;
    int virTop;
    int virBot;
    

public:
    percolation(int n);
    void open(int r, int c);
    bool isOpen(int r, int c);
    bool isFull(int r, int c);
    int numberOfOpenSites();
    bool percolates();
    int getOpenSpots();

    bool is_valid_index(int r, int c);

    ~percolation();

};