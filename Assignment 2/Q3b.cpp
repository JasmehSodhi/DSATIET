#include<iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n-1;
    while(low<=high){
    int mid=(low+high)/2;
     if(mid > 0 && arr[mid] != mid+1 && arr[mid-1] == mid) {
            return mid+1;
        }
        
        if(arr[mid] == mid+1) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
   
    return n;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6}; 
    int n = 6;
    cout << "Missing number (Binary Search) = " << findMissingBinary(arr, n) << endl;
    return 0;
}
