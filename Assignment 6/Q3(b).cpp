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

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;  // make it circular
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    int getSize() {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node* temp = head;
        while (true) {
            count++;
            temp = temp->next;
            if (temp == head)
                break;
        }
        return count;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        while (true) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == head)
                break;
        }
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);

    cll.display();
    cout << "Size of Circular Linked List = " << cll.getSize() << endl;

    return 0;
}