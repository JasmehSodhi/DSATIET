//Circular Linked List
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class CircularLinkedList{
    private:
    Node* head;
    public:
    CircularLinkedList(){
        head=nullptr;
    }

    void display(){
        if(head==nullptr){
            cout<<"List is empty";
            return;
        }
        Node* temp = head;
        while(temp!=head){
            cout<<temp->data<<""<<endl;
            temp=temp->next;
        }
    }

    void insertatbeg(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
            newNode->next=head;
            return;
        }
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
            temp->next=newNode;
            newNode->next=head;
            head=newNode;
        }}

    void insertatend(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
            newNode->next=head;
            return;
        }
        Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
            temp->next=newNode;
            newNode->next=head;
        }}

    void insertAfter(int x,int val){
        Node* temp=head;
        do{
            if(temp->data==x){
                Node* newNode=new Node(val);
                newNode->next=temp->next;
                temp->next=newNode;
                return;
            }
            temp=temp->next;
        }while(temp!=head);
    }

    void insertBefore(int x,int val){
         Node* newNode = new Node(val);
         if (head->data == x) {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* prev=head;
    Node* curr=head->next;
    while(curr!=head){
        if(curr->data==x){
            prev->next=newNode;
            newNode->next=curr;
            return;
        }
        prev=curr;
        curr=curr->next;
    }}
    void deleteNode(int key) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        // If only one node
        if (head->next == head && head->data == key) {
            delete head;
            head = nullptr;
            cout << "Node " << key << " deleted.\n";
            return;
        }
         if (head->data == key) {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = head->next;
            Node* delNode = head;
            head = head->next;
            delete delNode;
            cout << "Node " << key << " deleted.\n";
            return;
        }
        // If node in between or end
        do {
            prev = current;
            current = current->next;
            if (current->data == key) {
                prev->next = current->next;
                delete current;
                cout << "Node " << key << " deleted.\n";
                return;
            }
        } while (current != head);

        cout << "Node " << key << " not found.\n";
    }

    // Search for a node
    void search(int key) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }
};

// ---------------------- MAIN MENU ----------------------
int main() {
    CircularLinkedList cll;
    int choice, value, key;

    while (true) {
        cout << "\n--- Circular Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search for a Node\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            cll.insertatbeg(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            cll.insertatend(value);
            break;
        case 3:
            cout << "Enter existing node value (after which to insert): ";
            cin >> key;
            cout << "Enter new node value: ";
            cin >> value;
            cll.insertAfter(key, value);
            break;
        case 4:
            cout << "Enter existing node value (before which to insert): ";
            cin >> key;
            cout << "Enter new node value: ";
            cin >> value;
            cll.insertBefore(key, value);
            break;
        case 5:
            cout << "Enter value of node to delete: ";
            cin >> key;
            cll.deleteNode(key);
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> key;
            cll.search(key);
            break;
        case 7:
            cll.display();
            break;
        case 8:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}

