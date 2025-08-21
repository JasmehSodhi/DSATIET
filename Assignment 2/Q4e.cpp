#include <iostream>
#include <string>
using namespace std;

int main() {
    char c;
    
    cout << "Enter an uppercase character: ";
    cin >> c;
    
    if(isupper(c)) {
        char lower = tolower(c);
        cout << "Lowercase character: " << lower << endl;
    } else {
        cout << "Please enter an uppercase character!" << endl;
    }
    
    return 0;
}
