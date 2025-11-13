<<<<<<< HEAD
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Function to create a new node
Node* newNode(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert function (for creating a BST)
Node* insert(Node* root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
bool isBSTInorder(Node* root, Node*& prev) {
    if (root == NULL)
        return true;

    if (!isBSTInorder(root->left, prev))
        return false;

    if (prev != NULL && root->data <= prev->data)
        return false;

    prev = root;
    return isBSTInorder(root->right, prev);
}
int main() {
    Node* root = NULL;

    // Creating a valid BST
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    Node* prev = nullptr;
    if (isBSTInorder(root, prev))
        cout << "The given tree is a Binary Search Tree." << endl;
    else
        cout << "The given tree is NOT a Binary Search Tree." << endl;

    // Example of invalid tree
    Node* invalid = newNode(10);
    invalid->left = newNode(5);
    invalid->right = newNode(2);  // violates BST property

    Node* prevInvalid = nullptr;
    if (isBSTInorder(invalid, prevInvalid))
        cout << "The second tree is a Binary Search Tree." << endl;
    else
        cout << "The second tree is NOT a Binary Search Tree." << endl;

    return 0;
}
=======
#include <iostream>
#include <algorithm>
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

// Function to find height of BST
int findHeight(Node* root) {
    if (root == nullptr) {
        return -1;  // Height of empty tree is -1
    }
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

// Function to find depth of a node in BST
int findDepth(Node* root, int value, int depth = 0) {
    if (root == nullptr) {
        return -1;  // Node not found
    }
    
    if (root->data == value) {
        return depth;
    }
    
    if (value < root->data) {
        return findDepth(root->left, value, depth + 1);
    }
    return findDepth(root->right, value, depth + 1);
}

int main() {
    Node* root = nullptr;
    int choice, value;
    
    do {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Find Height of Tree" << endl;
        cout << "3. Find Depth of a Node" << endl;
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
                value = findHeight(root);
                if (value == -1) {
                    cout << "Tree is empty!" << endl;
                }
                else {
                    cout << "Height of BST: " << value << endl;
                }
                break;
                
            case 3:
                cout << "Enter value to find depth: ";
                cin >> value;
                int depth = findDepth(root, value);
                if (depth == -1) {
                    cout << "Value not found in BST!" << endl;
                }
                else {
                    cout << "Depth of node " << value << ": " << depth << endl;
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
>>>>>>> 8e15e6fb0e9965461c4b45306ea2c672366046b2
