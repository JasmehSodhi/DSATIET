#include<iostream>
#include<stack>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixtopostfix(string infix){

    string postfix;
    stack<char> s;
    for(int i=0;i<infix.length();i++){
        char ch=infix[i];
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9'){
            postfix+=ch;
        }
        else if(ch=='('){
            s.push(ch);
        }
        else if(ch==')'){
            while(!s.empty() && s.top() != '(') {
        postfix += s.top();
        s.pop();
    }
    s.pop();

    }
    else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
     
    }
    return postfix;
}
int main(){
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    string postfix = infixtopostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}