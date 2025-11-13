#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
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

    // Display list from beginning to end
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Doubly Linked List (forward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display list from end to beginning
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        cout << "Doubly Linked List (backward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Insert at beginning
    void insertAtBegin(int value) {
        Node* newNode = new Node(value);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        cout << "Inserted " << value << " at beginning.\n";
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted " << value << " at end.\n";
    }

    // Insert after specific node
    void insertAfter(int key, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = newNode;

        temp->next = newNode;
        cout << "Inserted " << value << " after " << key << ".\n";
    }

    // Insert before specific node
    void insertBefore(int key, int value) {
        Node* temp = head;

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // If inserting before the first node
        if (head->data == key) {
            insertAtBegin(value);
            return;
        }

        while (temp != nullptr && temp->data != key)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;

        cout << "Inserted " << value << " before " << key << ".\n";
    }

    // Delete node by value
    void deleteNode(int key) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        // Case 1: delete head node
        if (temp->data == key) {
            head = temp->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
            cout << "Deleted node " << key << ".\n";
            return;
        }

        // Case 2: delete in middle or end
        while (temp != nullptr && temp->data != key)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;

        delete temp;
        cout << "Deleted node " << key << ".\n";
    }

    // Search for node
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }
};

// ---------------- MAIN MENU -----------------
int main() {
    DoublyLinkedList dll;
    int choice, value, key;

    while (true) {
        cout << "\n--- Doubly Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search for a Node\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            dll.insertAtBegin(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            dll.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter existing node value (after which to insert): ";
            cin >> key;
            cout << "Enter new node value: ";
            cin >> value;
            dll.insertAfter(key, value);
            break;
        case 4:
            cout << "Enter existing node value (before which to insert): ";
            cin >> key;
            cout << "Enter new node value: ";
            cin >> value;
            dll.insertBefore(key, value);
            break;
        case 5:
            cout << "Enter node value to delete: ";
            cin >> key;
            dll.deleteNode(key);
            break;
        case 6:
            cout << "Enter node value to search: ";
            cin >> key;
            dll.search(key);
            break;
        case 7:
            dll.displayForward();
            break;
        case 8:
            dll.displayBackward();
            break;
        case 9:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
