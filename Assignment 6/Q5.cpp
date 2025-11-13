<<<<<<< HEAD
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next != head)
            temp = temp->next;
        temp->next = newNode;
    }

    // Make it circular manually (for testing)
    void makeCircular() {
        if (head == nullptr)
            return;
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = head; // last node points to head
    }

    bool isCircular() {
        if (head == nullptr)
            return false;

        Node* temp = head->next;
        while (temp != nullptr && temp != head)
            temp = temp->next;

        return (temp == head);
    }
};

int main() {
    LinkedList ll;
    ll.insertAtEnd(2);
    ll.insertAtEnd(4);
    ll.insertAtEnd(6);
    ll.insertAtEnd(7);
    ll.insertAtEnd(5);

    ll.makeCircular(); // makes it circular manually

    if (ll.isCircular())
        cout << "True";
    else
        cout << "False";

    return 0;
=======
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next != head)
            temp = temp->next;
        temp->next = newNode;
    }

    // Make it circular manually (for testing)
    void makeCircular() {
        if (head == nullptr)
            return;
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = head; // last node points to head
    }

    bool isCircular() {
        if (head == nullptr)
            return false;

        Node* temp = head->next;
        while (temp != nullptr && temp != head)
            temp = temp->next;

        return (temp == head);
    }
};

int main() {
    LinkedList ll;
    ll.insertAtEnd(2);
    ll.insertAtEnd(4);
    ll.insertAtEnd(6);
    ll.insertAtEnd(7);
    ll.insertAtEnd(5);

    ll.makeCircular(); // makes it circular manually

    if (ll.isCircular())
        cout << "True";
    else
        cout << "False";

    return 0;
>>>>>>> 8e15e6fb0e9965461c4b45306ea2c672366046b2
}