#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* node = new Node();
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int searchInorder(int inorder[], int inStart, int inEnd, int val) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

Node* buildTreeFromPreIn(int inorder[], int preorder[], int inStart, int inEnd, int &preIndex) {
    if (inStart > inEnd)
        return NULL;
    int curr = preorder[preIndex++];
    Node* node = newNode(curr);
    if (inStart == inEnd)
        return node;
    int inIndex = searchInorder(inorder, inStart, inEnd, curr);
    node->left = buildTreeFromPreIn(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTreeFromPreIn(inorder, preorder, inIndex + 1, inEnd, preIndex);
    return node;
}

void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};
    int n = 5;
    int preIndex = 0;
    Node* root = buildTreeFromPreIn(inorder, preorder, 0, n - 1, preIndex);
    inorderTraversal(root);
    cout << endl;
    return 0;
}