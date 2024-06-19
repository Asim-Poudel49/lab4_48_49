#include <iostream>
#include <chrono> // For measuring time
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to calculate the time complexity of QuickSort
void calculateTimeComplexity(int arr[], int size) {
    auto start = chrono::high_resolution_clock::now(); // Start measuring time

    quickSort(arr, 0, size - 1);

    auto end = chrono::high_resolution_clock::now(); // Stop measuring time
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Calculate the duration in microseconds

    cout << "Time Complexity of QuickSort: " << duration.count() << " microseconds" << endl;
}

// Driver code
int main() {
    int arr[] = { 64, 25, 12, 22, 11,55, 33, 44, 66, 77, 88, 99, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    calculateTimeComplexity(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}