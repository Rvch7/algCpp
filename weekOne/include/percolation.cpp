#include "percolation.hpp"
#include <assert.h>

percolation::percolation(int n): numofSpots{n}, uf{WeightedUF(n*n + 2)},virTop{n*n},virBot{n*n+1}{
    assert(n > 0 && "Invalid input");
    status = new bool[n*n+2];
    status[virTop] = spot_status::open;
    status[virBot] = spot_status::open;
}

void percolation::open(int r, int c){
    assert(is_valid_index(r,c) && "Invalid input to Open method");
    int currentSpot = r*numofSpots + c;
    int TopSpot = (r-1)*numofSpots + c;
    int BotSpot = (r+1)*numofSpots + c;
    int leftSpot = r*numofSpots + c-1;
    int rightSpot = r*numofSpots + c+1;
    if(status[currentSpot] != spot_status::open){
        status[currentSpot] = spot_status::open;
        openSpots++; 
        // Four corner and side cases
        if(r == 0){
            uf.Union(currentSpot, virTop);
            if(c == 0){
                if(status[rightSpot] == spot_status::open){
                    uf.Union(currentSpot,rightSpot);
                }
                if(status[BotSpot] == spot_status::open){
                    uf.Union(currentSpot,BotSpot);
            }else if(c == numofSpots - 1){
            
                if(status[leftSpot] == spot_status::open){
                    uf.Union(currentSpot,leftSpot);
                }
                if(status[BotSpot] == spot_status::open){
                    uf.Union(currentSpot,BotSpot);
                }
            }   
            }
        }
        
        if(r == numofSpots - 1){
            uf.Union(currentSpot, virBot);
            if(c == 0){
                if(status[rightSpot] == spot_status::open){
                    uf.Union(currentSpot,rightSpot);
                }
                if(status[TopSpot] == spot_status::open){
                    uf.Union(currentSpot,TopSpot);
                }
            }else if(c == numofSpots - 1){
                if(status[leftSpot] == spot_status::open){
                    uf.Union(currentSpot,leftSpot);
                }
                if(status[TopSpot] == spot_status::open){
                    uf.Union(currentSpot,TopSpot);
                }
            }
        }


        // All other spots
        if(r != 0 && status[TopSpot] == spot_status::open){
            uf.Union(currentSpot,TopSpot);
        }
        if(r != numofSpots - 1 && status[BotSpot] == spot_status::open){
            uf.Union(currentSpot,BotSpot);
        }
        if(c != 0 && status[leftSpot] == spot_status::open){
            uf.Union(currentSpot,leftSpot);
        }
        if(c != numofSpots - 1 && status[rightSpot] == spot_status::open){
            uf.Union(currentSpot,rightSpot);
        }
    }
    

    

}

bool percolation::isOpen(int r, int c){
    assert(is_valid_index(r,c) && "Invalid input to isOpen method");
    return (status[r*numofSpots + c]) ? true : false;
}

bool percolation::isFull(int r, int c){
    assert(is_valid_index(r,c) && "Invalid input to isFull method");
    return (status[r*numofSpots + c]) ? true : false;
}

int percolation::numberOfOpenSites(){
    return openSpots;
}

bool percolation::percolates(){
    return uf.Find(virTop,virBot);
}

bool percolation::is_valid_index(int r, int c){
    return (r >= 0 && c >= 0 && r < numofSpots && c < numofSpots) ? true : false;
}

percolation::~percolation(){
    // std::cout << "percolation terminated..." << std::endl;
    delete status;
}

