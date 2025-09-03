#include<iostream>
using namespace std;
#define Max 100
char stack[Max];
int top=-1;
bool isEmpty(){
    return (top==-1);
}

bool isFull(){
    return (top==Max-1);
}

void push(char c){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    stack[top]=c;
    cout<<"Element pushed: "<<c<<endl;
}
void pop(){
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    cout<<"Element popped: "<<stack[top]<<endl;
    top--;
}
