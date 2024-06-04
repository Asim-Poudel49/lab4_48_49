
#include <random>
#include "QuickSort.h"
#include <iostream>
using namespace std;

int main(){
    int n = 00;
    int arr[n];
     random_device rd;
     mt19937 gen(rd());
     uniform_int_distribution<> dis(0, 999);
     cout << "Using MT:\n" <<  endl;
    for(int i = 0; i < n; i++) {
        arr[i] =dis(gen);
    }
     cout <<  endl;

     cout << "Original array: ";
    printArray(arr, n);

    calculateTimeComplexity(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

    
