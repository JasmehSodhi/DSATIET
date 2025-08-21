#include<iostream>
using namespace std;
int bs(int arr[],int n,int tofind){
    int low=0,high=n-1;
    int mid=(high+low)/2;
    while(mid<=high){
        if(arr[mid]==tofind)
        return mid;
        else if(arr[mid]<tofind)
        mid=mid+1;
        else
        mid=mid-1;
    }
    return -1;
}
int main(){
    int n,tofind,result;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout << "Enter elements in sorted order: ";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter element to search: ";
    cin>>tofind;
     result = bs(arr, n, tofind);
    if (result != -1)
        cout << "Element found at position " << result + 1 << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
