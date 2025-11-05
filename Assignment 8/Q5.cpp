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