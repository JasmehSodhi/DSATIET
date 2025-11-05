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

// Function to search a value in BST
bool search(Node* root, int value) {
    // Base case: root is null or value is found
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    
    // If value is less than root's data, search in left subtree
    if (value < root->data) {
        return search(root->left, value);
    }
    
    // If value is greater than root's data, search in right subtree
    return search(root->right, value);
}

int main() {
    Node* root = nullptr;
    int choice, value;
    
    do {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Search a value" << endl;
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
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Value " << value << " found in the BST!" << endl;
                }
                else {
                    cout << "Value " << value << " not found in the BST!" << endl;
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