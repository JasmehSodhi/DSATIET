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

// Function to find minimum value in BST
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    
    // Keep going left until we reach the leftmost leaf
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

// Function to find maximum value in BST
int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    
    // Keep going right until we reach the rightmost leaf
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

int main() {
    Node* root = nullptr;
    int choice, value;
    
    do {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Find Minimum Value" << endl;
        cout << "3. Find Maximum Value" << endl;
        cout << "4. Exit" << endl;
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
                value = findMin(root);
                if (value != -1) {
                    cout << "Minimum value in BST: " << value << endl;
                }
                break;
                
            case 3:
                value = findMax(root);
                if (value != -1) {
                    cout << "Maximum value in BST: " << value << endl;
                }
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