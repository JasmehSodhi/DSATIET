#include<stdio.h>
int main(){
    int i,j,temp;
	int arr[7]={64,34,25,12,22,11,90};
    int n=7;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            }
        }
    }
    printf("Sorted Array: ");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
	return 0;

}