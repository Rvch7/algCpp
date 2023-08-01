#include "percolation.hpp"

percolation::percolation(int n): n{n}{
   spots = Grid(n, std::vector<int>(n,spot_status::full));
}

void percolation::open(int r, int c){
    spots[r][c] = spot_status::open;
}

bool percolation::isOpen(int r, int c){
    return (spots[r][c] == spot_status::open) ? true : false;
}

bool percolation::isFull(int r, int c){
    return (spots[r][c] == spot_status::full) ? true : false;
}

int percolation::numberOfOpenSites(){
    return openSpots;
}


//TODO add own union find call for grid data structure
bool percolation::percolates(){
    if (wuf.Find(virTop,virBot)){
        return true;
    }else{
        return false;
    }
}