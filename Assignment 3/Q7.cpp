#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long currMin;

public:
void push(long long x){
    if(st.empty()){
        st.push(x);
        currMin = x;
    }
    else if(x>=currMin){
        st.push(x);

    }
    else{
        st.push(2*x - currMin);
        currMin = x;
    }
}
void pop(){
    if(st.top()<currMin){
        currMin= 2*currMin - st.top();
        st.pop();
    }
}
long long top(){
    if(st.top()>=currMin){
        return st.top();
    }
    else{
        return currMin;
    }
}
 long long getMin() {
        return currMin;
    }

    bool empty() { return st.empty(); }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(7);
    ms.push(3);
    cout << ms.getMin() << "\n"; // 3
    ms.pop();
    cout << ms.getMin() << "\n"; // 5
}
