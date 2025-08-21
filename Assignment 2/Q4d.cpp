#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> strings;
    int n;
    
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // Clear buffer
    
    cout << "Enter " << n << " strings:" << endl;
    for(int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        strings.push_back(str);
    }
    
    sort(strings.begin(), strings.end());
    
    cout << "\nStrings in alphabetical order:" << endl;
    for(const string& str : strings) {
        cout << str << endl;
    }
    
    return 0;
}
