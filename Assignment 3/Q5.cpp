#include <iostream>
#include <stack>
#include <string>
#include <cctype> // for isdigit

using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expression) {
    stack<int> st;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        // Skip spaces
        if (ch == ' ')
            continue;

        // If operand, push to stack
        if (isdigit(ch)) {
            st.push(ch - '0');  // convert char digit to int
        }
        // If operator, pop two operands and apply operator
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch(ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top(); // final result
}

int main() {
    string expression;
    cout << "Enter a postfix expression : ";
    cin >> expression;

    cout << "Result = " << evaluatePostfix(expression) << endl;

    return 0;
}
