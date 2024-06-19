#include "./QuickSort.h"
#include <iostream>
#include <chrono>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void calculateTimeComplexity(int arr[], int size, int runs)
{
    int *original = new int[size];
    for (int i = 0; i < size; i++)
    {
        original[i] = arr[i];
    }

    long long totalDuration = 0;

    for (int i = 0; i < runs; i++)
    {
        // Reset array to original state
        for (int j = 0; j < size; j++)
        {
            arr[j] = original[j];
        }

        auto start = chrono::high_resolution_clock::now();

        quickSort(arr, 0, size - 1);

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        totalDuration += duration.count();
    }

    cout << "Time Complexity of QuickSort is  " << totalDuration / runs << " microseconds" << endl;

    delete[] original;
}
