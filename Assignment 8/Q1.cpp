#include <iostream>
using namespace std;

// Node structure for BST
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

// Function for inorder traversal
void inorder(Node* root) {
    if (root == nullptr) return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function for preorder traversal
void preorder(Node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function for postorder traversal
void postorder(Node* root) {
    if (root == nullptr) return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int choice, value;
    
    do {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Inorder Traversal" << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Postorder Traversal" << endl;
        cout << "5. Exit" << endl;
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
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
                
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
                
            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
                
            case 5:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 5);
    
    return 0;
}
