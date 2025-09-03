#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;
    
    // Only storing diagonal elements
    int diagonal[50];  // Using fixed size for simplicity
    
    // Input diagonal elements
    cout << "Enter " << n << " diagonal elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> diagonal[i];
    }
    
    // Display the complete matrix
    cout << "\nThe complete matrix is:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                cout << diagonal[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    
    
    return 0;
}
