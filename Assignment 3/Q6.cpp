#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int A[100], ans[100]; // assuming max size 100

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    stack<int> st;
    for(int i=0;i<n;i++) {
    while(!st.empty() && st.top() >= A[i]) {
        st.pop();
    }
    if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
         st.push(A[i]);}
    cout << "Nearest smaller elements to left: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}