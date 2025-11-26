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
Node* insert(Node* root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root; // no duplicates allowed
}
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}
Node* searchIterative(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}
Node* findMax(Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}
Node* inorderSuccessor(Node* root, Node* target) {
    Node* successor = NULL;

    while (root != NULL) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return successor;
}
Node* inorderPredecessor(Node* root, Node* target) {
    Node* predecessor = NULL;

    while (root != NULL) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else
            root = root->left;
    }
    return predecessor;
}
int main() {
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    int key = 15;
    Node* result = searchRecursive(root, key);
    if (result)
        cout << key << " found (recursive)\n";
    else
        cout << key << " not found\n";

    result = searchIterative(root, key);
    if (result)
        cout << key << " found (iterative)\n";

    cout << "Min element: " << findMin(root)->data << endl;
    cout << "Max element: " << findMax(root)->data << endl;

    Node* succ = inorderSuccessor(root, searchRecursive(root, 15));
    if (succ) cout << "Successor of 15: " << succ->data << endl;

    Node* pred = inorderPredecessor(root, searchRecursive(root, 15));
    if (pred) cout << "Predecessor of 15: " << pred->data << endl;

    return 0;
}

