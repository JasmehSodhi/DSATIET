#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Function to display queue contents without modifying the queue
void displayQueue(queue<int> q) {
    cout << "Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// Function to get minimum index in unsorted part
int minIndex(queue<int>& q, int sortedIndex) {
    if (q.empty()) return -1;  // Handle empty queue
    
    int min_index = -1;
    int min_value = INT_MAX;
    int n = q.size();

    // Make a copy of current state of queue
    queue<int> temp = q;
    
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        // if current element is smaller than min_value and in unsorted part
        if (curr < min_value && i < sortedIndex) {
            min_value = curr;
            min_index = i;
        }
        q.push(curr);
    }
    return min_index;
}

// Function to move minimum element to rear
void insertMinToRear(queue<int>& q, int min_index) {
    if (min_index == -1) return;  // Handle invalid index
    
    int n = q.size();
    int min_value;

    // Remove all elements except min and re-insert them
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        
        if (i != min_index)
            q.push(curr);
        else
            min_value = curr;
    }
    // Push the minimum value at the end
    q.push(min_value);
}

// Function to sort the queue
void sortQueue(queue<int>& q) {
    if (q.empty()) return;  // Handle empty queue
    
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int min_index = minIndex(q, n - i);
        insertMinToRear(q, min_index);
        
        // Display intermediate steps (optional, for understanding)
        cout << "After iteration " << i + 1 << ": ";
        displayQueue(q);
    }
}

int main() {
    queue<int> q;
    int n, value;

    // Get input from user
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a valid number of elements (greater than 0)" << endl;
        return 1;
    }

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    // Display original queue
    cout << "\nOriginal ";
    displayQueue(q);

    // Sort the queue
    cout << "\nSorting steps:" << endl;
    sortQueue(q);

    // Display final sorted queue
    cout << "\nFinal Sorted ";
    displayQueue(q);

    return 0;
}