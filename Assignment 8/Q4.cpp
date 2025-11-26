
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
