//
// Created by Miguel Mercado on 26/11/23.
//

// This is a simple C++ algorithm called "Quick Sort" that sorts an array of integers in ascending order.
// The algorithm is based on the divide and conquer approach, and it is implemented recursively.
// The algorithm is not stable, and it has a time complexity of O(n log n) in the average case, and O(n^2) in the worst case.
// The algorithm is in-place, and it has a space complexity of O(log n) in the average case, and O(n) in the worst case.

#include <iostream>
using namespace std;

void quickSort(int *array, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = array[(left + right) / 2];

    // Partition
    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            // Swap
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    };

    // Recursion
    if (left < j)
        quickSort(array, left, j);
    if (i < right)
        quickSort(array, i, right);
}

// Example
int main() {
    int array[] = { 3, 2, 1, 5, 6, 4 };
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    quickSort(array, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}
