#include<stdio.h>
int main(){
    int n,i;
    int arr[100],arr2[100];
    for(i=0;i<n;i++){
    printf("Enter %d element: ",i+1);
    scanf("%d",arr[i]);
    }
    for(i=0;i<n;i++){
    	arr2[i]=arr[n-1-i];
	}
	for(i=0;i<n;i++){
		printf("%d ",arr2[i]);
	}
	return 0;
}
    