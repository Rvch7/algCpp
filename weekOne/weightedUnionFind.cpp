#include "weightedUnionFind.hpp"

int WeightedUF::root(int i){
	if( i < 0 || i >= N){
		std::cout << " invalid input to root " << std::endl;

		return -1;
	}
	while( i != id[i]) i = id[i];
	return i;
}

WeightedUF::WeightedUF(int N):N(N){
	size = new int[N];
	id = new int[N];
	for(int i=0; i<N; i++){
		id[i] = i;
		size[i] = 1;
	}
}
bool WeightedUF::Find(int p,int q){
	if(root(p) == root(q)){
		return true;
	}else{
		return false;
	}
}	

void WeightedUF::Union(int p,int q){
	if(p!=q){
		int rootp = root(p); 
		int rootq = root(q);
		
		if(size[rootp] < size[rootq]){
			id[rootp] = rootq;
			size[rootq] = size[rootq] + size[rootp];
		}else{
			id[rootq] = rootp;
			size[rootq] = size[rootp] + size[rootq];
		}
		std::cout << p << " and " << q << " are union\n";
	}
}

WeightedUF::~WeightedUF(){
	delete id;
}
