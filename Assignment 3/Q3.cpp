#include<iostream>
using namespace std;
#define MAX 100

char stack[MAX];
int top=-1;
void push(char c){
    if(top==MAX-1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    stack[++top]=c;
}

char pop(){
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
        return '\0';
    }
    return stack[top--];
}
bool balancedPar(string exp){
    for(int i=0;i<exp.length();i++){
        char ch=exp[i];

        if(ch=='(' || ch=='{' || ch=='['){
            push(ch);
        }
        else if(ch==')' || ch=='}' || ch==']'){
            if(top==-1){
                return false;
                char popped= pop();
                if ((ch == ')' && popped != '(') ||
                (ch == '}' && popped != '{') ||
                (ch == ']' && popped != '[')) {
                return false;
            }
            
            }
            
        }
    }
    return (top==-1);
}
int main(){
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (balancedPar(expr))
        cout << "Expression has Balanced Parentheses" << endl;
    else
        cout << "Expression does NOT have Balanced Parentheses" << endl;

    return 0;
}
