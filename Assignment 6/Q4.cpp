#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insertAtEnd(char value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Check if palindrome
    bool isPalindrome() {
        if (head == nullptr)
            return true;

        Node* left = head;
        Node* right = head;

        // Move right to the last node (tail)
        while (right->next != nullptr)
            right = right->next;

        // Compare characters from both ends
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }

        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd('L');
    dll.insertAtEnd('E');
    dll.insertAtEnd('V');
    dll.insertAtEnd('E');
    dll.insertAtEnd('L');

    if (dll.isPalindrome())
        cout << "True";
    else
        cout << "False";

    return 0;
} 