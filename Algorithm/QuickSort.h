#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);
void calculateTimeComplexity(int arr[], int size, int runs);

#endif
