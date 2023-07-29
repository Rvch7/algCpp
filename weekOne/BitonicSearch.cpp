#include <iostream>
#include <stdlib.h>

int ascBinarySearch(int * arr, int n, int hiLim, int loLim){
    int index = (hiLim+loLim)/2;

    if(arr[index] == n){
        return index;
    }else if(hiLim == loLim){
        return -1;
    }else if (n < arr[index]) {
        return ascBinarySearch(arr, n, index - 1, loLim);
    }else if (n > arr[index]){
        return ascBinarySearch(arr, n, hiLim, index + 1  );
    }else{
        return -1;
    }
}

int dscBinarySearch(int * arr, int n, int hiLim, int loLim){
    int index = (hiLim+loLim)/2;

    if(arr[index] == n){
        return index;
    }else if(hiLim == loLim){
        return -1;
    }else if (n > arr[index]) {
        return dscBinarySearch(arr, n, index - 1, loLim);
    }else if (n < arr[index]){
        return dscBinarySearch(arr, n, hiLim, index + 1  );
    }else{
        return -1;
    }
}


int bitonic_search(int* arr, int size, int n){

    int hiLimit = size;
    int loLimit = 0;

    int index = (hiLimit+loLimit)/2;

    if(arr[index] == n){
        return (size/2);
    }else if(n > arr[index]){
        //hiLimit = ((hiLimit-loLimit)/2) - 1;
        return ascBinarySearch(arr,n,index - 1, loLimit);
    }else{
        return dscBinarySearch(arr,n,hiLimit - 1, index+1);
    }


}


int main(int argc, char const *argv[])
{
    int size = 16;
    int n = 15;
    int* Bitonicarr = new int[size]; 
    for(int i = 0; i < size/2; i++){
        Bitonicarr[i] = size/2 + i;
        Bitonicarr[i + size/2] = size/2 - i - 1 ;
    }
    for (size_t i = 0; i < size; i++)
    {
        std::cout << " " << Bitonicarr[i];
    }
    

    
    std::cout << "\nindex of " <<  n <<  " is: " << bitonic_search(Bitonicarr, size, n) << std::endl;



    return 0;
}

