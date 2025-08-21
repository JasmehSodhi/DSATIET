#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    
    cout << "Enter a string: ";
    getline(cin, str);
    
    int len = str.length();
    for(int i = 0; i < len/2; i++) {
        swap(str[i], str[len-1-i]);
    }
    
    cout << "Reversed string: " << str << endl;
    
    return 0;
}
