
#include <random>
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void calculateTimeComplexity(int arr[], int n) {
    auto start = chrono::high_resolution_clock::now(); // Start measuring time

    insertionSort(arr,n );

    auto end = chrono::high_resolution_clock::now(); // Stop measuring time
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Calculate the duration in microseconds

    cout << "Time Complexity of InsertionSort: " << duration.count() << "microseconds" << endl;
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n],revArr[n];
     random_device rd;
     mt19937 gen(rd());
     uniform_int_distribution<> dis(0, 999);
    for(int i = 0; i < n; i++) {
         arr[i]= dis(gen);
    }
    cout << "Original array: ";
    printArray(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);
    
    for(int i = 0; i < n; i++) {
         revArr[n-i-1]=arr[i];
    }

    calculateTimeComplexity(arr, n);
    calculateTimeComplexity(revArr, n);
   

    return 0;



}





















/*#include <iostream>
#include <random>

int main() {
    // Create a Mersenne Twister engine
     mt19937 mt_engine( random_device{}());

    // Generate a random number between 0 and 99
     uniform_int_distribution<int> dist(0, 99);
    int random_number = dist(mt_engine);

    // Print the random number
     cout << "Random number: " << random_number <<  endl;

    return 0;
}*/