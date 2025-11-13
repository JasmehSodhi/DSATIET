<<<<<<< HEAD
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
=======
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a node in BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function to find Lowest Common Ancestor
Node* findLCA(Node* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // If both n1 and n2 are greater than root,
    // LCA lies in right subtree
    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }
    
    // If both n1 and n2 are smaller than root,
    // LCA lies in left subtree
    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }
    
    // If one value is smaller and other is greater,
    // current node is LCA
    return root;
}

// Function to check if a value exists in BST
bool exists(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    
    if (root->data == value) {
        return true;
    }
    
    if (value < root->data) {
        return exists(root->left, value);
    }
    return exists(root->right, value);
}

int main() {
    Node* root = nullptr;
    int choice, value, n1, n2;
    
    do {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Find Lowest Common Ancestor" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                if (root == nullptr) {
                    root = insert(root, value);
                }
                else {
                    insert(root, value);
                }
                cout << "Value inserted successfully!" << endl;
                break;
                
            case 2:
                cout << "Enter first value: ";
                cin >> n1;
                cout << "Enter second value: ";
                cin >> n2;
                
                // First check if both values exist in the BST
                if (!exists(root, n1) || !exists(root, n2)) {
                    cout << "One or both values don't exist in the BST!" << endl;
                }
                else {
                    Node* lca = findLCA(root, n1, n2);
                    if (lca != nullptr) {
                        cout << "Lowest Common Ancestor of " << n1 << " and " 
                             << n2 << " is: " << lca->data << endl;
                    }
                }
                break;
                
            case 3:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 3);
    
    return 0;
}
>>>>>>> 8e15e6fb0e9965461c4b45306ea2c672366046b2
