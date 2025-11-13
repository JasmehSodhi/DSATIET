#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;  // using dynamic array for heap

    // Function to heapify up (for insertion)
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    // Function to heapify down (for deletion)
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert a new element
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Remove the highest priority element (root)
    void deleteMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        cout << "Deleted element: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Return highest priority element
    int getMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    // Display heap
    void display() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        cout << "Priority Queue (Max-Heap): ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    do {
        cout << "\n--- PRIORITY QUEUE MENU ---\n";
        cout << "1. Insert\n2. Delete Max\n3. Get Max\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                pq.deleteMax();
                break;
            case 3:
                cout << "Maximum element: " << pq.getMax() << endl;
                break;
            case 4:
                pq.display();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
