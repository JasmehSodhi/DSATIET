#include<iostream>
using namespace std;
#define MAX 5

int stack[MAX];
int top = -1;
bool isEmpty(){
    return (top==-1);
}

bool isFull(){
    return (top==MAX-1);
}

void push(int x){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    stack[top]=x;
    cout<<"Element pushed: "<<x<<endl;
 }

void pop(){
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    cout<<"Element popped: "<<stack[top]<<endl;
    top--;
}
void peek(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"Top element is: "<<stack[top]<<endl;
}
void display(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"Stack elements: ";
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int choice,element;
    do{
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to push: ";
                cin>>element;
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice, please try again."<<endl;
        }
    }while(choice!=5);
    return 0;
}