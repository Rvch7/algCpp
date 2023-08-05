#include <stdlib.h>
#include <iostream>
#include <memory>


template< typename T >
struct array_deleter
{
  void operator ()( T const * p)
  { 
    delete[] p; 
  }
};



class WeightedUF{
private:
	int* id;
	int* size;
	int N;
	int root(int i);
public:
	WeightedUF(int N);
	WeightedUF() = default;
	bool Find(int p,int q);
	void Union(int p,int q);
	~WeightedUF();
};