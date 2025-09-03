#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;
    
    // Arrays for three diagonals
    int lower[49];   // lower diagonal
    int main[50];    // main diagonal
    int upper[49];   // upper diagonal
    
    // Input elements
    cout << "Enter " << n-1 << " lower diagonal elements:" << endl;
    for(int i = 0; i < n-1; i++)
        cin >> lower[i];
        
    cout << "Enter " << n << " main diagonal elements:" << endl;
    for(int i = 0; i < n; i++)
        cin >> main[i];
        
    cout << "Enter " << n-1 << " upper diagonal elements:" << endl;
    for(int i = 0; i < n-1; i++)
        cin >> upper[i];
    
    // Display the complete matrix
    cout << "\nThe complete matrix is:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                cout << main[i] << " ";
            else if(i == j + 1)
                cout << lower[j] << " ";
            else if(i == j - 1)
                cout << upper[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    
    cout << "\nSpace saved: Instead of storing " << n*n << " elements, ";
    cout << "we only store " << (3*n - 2) << " elements!" << endl;
    
    return 0;
}
