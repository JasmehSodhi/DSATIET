#include<stdio.h>

    int arr[100],n=0,pos,x,y;
    
    void create() {
        int i;
        printf("Enter the number of elements in the array: ");
        scanf("%d",&n);

        
        for(i=0;i<n;i++){
            printf("Enter %d element",i+1);
            scanf("%d",&arr[i]);
        }
    }
    void display(){
        int i;
        printf("The elements of the array are: ");
        for(i=0;i<n;i++){
            printf("%d\t",arr[i]);
        }
    }
    void insert(){
        int i;
        printf("Enter the element you want to insert: ");
        scanf("%d",x);
        printf("Enter the position of the element: ");
        scanf("%d",pos);
        if(pos<1 || pos>n+1){
            printf("Invalid option");
        }
        for(i=n;i>=pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos-1]=x;
        n++;
        printf("The element is inserted");

    }
    void delete(){
        int i;
        printf("Enter the position you want to delete: ");
        scanf("%d",&pos);
        if(pos<1 || pos>n){
            printf("Invalid position");
        }
        for(i=pos-1;i<n-1;i++){
             arr[i]=arr[i+1];
        }
        n--;
        printf("Element deleted successfully");
    }
    void search(){
        printf("Enter the element you want to search: ");
        scanf("%d",y);
        int found=0,i;
        for(i=0;i<n;i++){
            if (arr[i]==y){
            printf("Element found at position %d", i + 1);
            found = 1;
            }
        }
        if (!found) {
        printf("Element not found");
        }
    }
int main(){
    int choice;
    while (1) {
        
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delete(); break;
            case 5: search(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}