#include <iostream>
using namespace std;

int main() {
    char str[100];
    char result[100];
    int j = 0;
    
    cout << "Enter a string: ";
    cin.getline(str, 100);
    
    // Loop through each character in the input string
    for(int i = 0; str[i] != '\0'; i++) {
        // Convert to lowercase for checking
        char c = tolower(str[i]);
        
        // If character is not a vowel, add it to result
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';  // Add null terminator
    
    cout << "String after removing vowels: " << result << endl;
    
    return 0;
}
