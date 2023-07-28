#include <stdlib.h>
#include <iostream>

class WeightedUF{
private:
	int* id;
	int* size;
	int N;
	int root(int i){
		if( i < 0 || i >= N){
			std::cout << " invalid input to root " << std::endl;

			return -1;
		}
		while( i != id[i]) i = id[i];
		return i;
	}
public:
	WeightedUF(int N):N(N){
		size = new int[N];
		id = new int[N];
		for(int i=0; i<N; i++){
			id[i] = i;
			size[i] = 1;
		}
	}
	bool Find(int p,int q){
		if(root(p) == root(q)){
			return true;
		}else{
			return false;
		}
	}	

	void Union(int p,int q){
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

	~WeightedUF(){
		delete id;
	}
};

int main(int argc, char* argv[]){
	WeightedUF WUF{10};
	WUF.Union(3,4);
	WUF.Union(3,5);

	std::cout << WUF.Find(4,5)<<std::endl;
	std::cout << WUF.Find(4,6)<<std::endl;
	std::cout << WUF.Find(4,10)<<std::endl;
	
	
	return 0;
}
