#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;
    
    // Store only lower triangle (since upper triangle is mirror image)
    int elements[55];  // Maximum size for n=10
    int k = 0;
    
    // Input elements (only lower triangle)
    cout << "Enter elements row by row (only lower triangle):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> elements[k++];
        }
    }
    
    // Display the complete matrix
    cout << "\nThe complete matrix is:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j)
                cout << elements[i*(i+1)/2 + j] << " ";
            else
                cout << elements[j*(j+1)/2 + i] << " ";  // Mirror element
        }
        cout << endl;
    }
    
    cout << "\nSpace saved: Instead of storing " << n*n << " elements, ";
    cout << "we only store " << (n*(n+1)/2) << " elements!" << endl;
    
    return 0;
}
