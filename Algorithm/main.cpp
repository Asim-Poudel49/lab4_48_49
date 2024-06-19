#include "./QuickSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;

int main()
{
    int n = 10000;
    int runs = 10; // Number of runs to average the time complexity

    int *arr = new int[n];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 999);

    for (int i = 0; i < n; i++)
    {
        arr[i] = dis(gen);
    }

    // cout << "Original array: ";
    // printArray(arr, n);

    std::sort(arr, arr + n);

    calculateTimeComplexity(arr, n, runs);

    // cout << "Sorted array: ";
    // printArray(arr, n);

    delete[] arr;
    return 0;
}
