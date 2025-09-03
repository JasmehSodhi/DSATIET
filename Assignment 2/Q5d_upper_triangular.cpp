#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;
    
    // Store only upper triangle
    int elements[55];  // Maximum size for n=10
    int k = 0;
    
    // Input elements (only upper triangle)
    cout << "Enter elements row by row (only upper triangle):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cin >> elements[k++];
        }
    }
    
    // Display the complete matrix
    cout << "\nThe complete matrix is:" << endl;
    k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j >= i)
                cout << elements[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    
    cout << "\nSpace saved: Instead of storing " << n*n << " elements, ";
    cout << "we only store " << (n*(n+1)/2) << " elements!" << endl;
    
    return 0;
}
