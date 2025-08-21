#include<stdio.h>
int main(){
    int m,n,p;
    int i,j,k;
    int A[m][n],B[n][p],C[m][p];

    printf("Enter the rows and columns of first matrix(m,n): ");
    scanf("%d%d",&m,&n);
    printf("Enter columns of second matrix(p): ");
    scanf("%d",&p);

    printf("Enter elements of first matrix (%d*%d): ", m, n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",A[i][j]);
        }
    }
    printf("Enter elements of second matrix (%d*%d): ", n, p);
    for(i=0;i<n;i++){
        for(j=0;j<p;j++){
            scanf("%d",&B[i][j]);
        }
    }

    for(i=0;i<m;i++){ 
        for(j=0;j<p;j++){ 
            C[i][j]=0; 
        } 
    }
    for(i=0;i<m;i++){
        for(j=0;j<p;j++){
            for(k=0;k<n;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    printf("Resultant Matrix (%d*%d): ",m,p);
    for(i=0;i<m;i++){
        for(j=0;j<p;j++){
            printf("%d",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}

   