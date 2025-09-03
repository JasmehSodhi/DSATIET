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
    
}
void pop(){
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    
    top--;
}
int main(){
    string str;
    string reversed="";
    cout<<"Enter a string: ";
    cin>>str;
    for(int i=0;i<str.length();i++){
        push(str[i]);
    }
    while (top != -1) {
        reversed += stack[top];
        pop();
    }

    cout << "Reversed string: " << reversed << endl;
    return 0;
}