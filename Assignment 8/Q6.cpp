#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;
    
    // Helper functions for getting parent and child indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    // Function to heapify up (used after insertion)
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    // Function to heapify down (used after deletion)
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < size && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        
        if (right < size && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }
        
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }
    
public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }
    
    ~MaxHeap() {
        delete[] heap;
    }
    
    // Function to insert a new value
    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        
        // Insert new value at the end
        heap[size] = value;
        size++;
        
        // Restore heap property
        heapifyUp(size - 1);
    }
    
    // Function to delete maximum element
    int deleteMax() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        
        int max = heap[0];
        
        // Replace root with last element
        heap[0] = heap[size - 1];
        size--;
        
        // Restore heap property
        heapifyDown(0);
        
        return max;
    }
    
    // Function to display heap
    void display() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of heap: ";
    cin >> capacity;
    
    MaxHeap heap(capacity);
    int choice, value;
    
    do {
        cout << "\nMax Heap Operations:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Delete maximum element" << endl;
        cout << "3. Display heap" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                heap.insert(value);
                break;
                
            case 2:
                value = heap.deleteMax();
                if (value != -1) {
                    cout << "Deleted maximum element: " << value << endl;
                }
                break;
                
            case 3:
                heap.display();
                break;
                
            case 4:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 4);
    
    return 0;
}