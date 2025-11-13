#include <iostream>
using namespace std;

// Function to heapify a subtree rooted with node i (for Max Heap)
void heapifyMax(int arr[], int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // left child
    int right = 2 * i + 2;     // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

// Function to heapify for Min Heap
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

// Heap Sort using Max-Heap (for Increasing Order)
void heapSortIncreasing(int arr[], int n) {
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapifyMax(arr, i, 0); // call heapify on reduced heap
    }
}

// Heap Sort using Min-Heap (for Decreasing Order)
void heapSortDecreasing(int arr[], int n) {
    // Build Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

// Function to display array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {20, 5, 15, 22, 40, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    display(arr, n);

    // Increasing Order
    heapSortIncreasing(arr, n);
    cout << "\nSorted in Increasing Order: ";
    display(arr, n);

    // Reset array for decreasing order
    int arr2[] = {20, 5, 15, 22, 40, 10};
    heapSortDecreasing(arr2, n);
    cout << "Sorted in Decreasing Order: ";
    display(arr2, n);

    return 0;
}
