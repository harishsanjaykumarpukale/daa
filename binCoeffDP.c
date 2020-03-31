#include<stdio.h>
int binCoeff(int n,int r){
    int arr[n+1][r+1],i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++){
            if(i==j)
                arr[i][j]=1;            
            else if(j==1)
                arr[i][j]=i;
            else
                arr[i][j]=arr[i-1][j] + arr[i-1][j-1];
        }
    printf("\nThe matrix generated is:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++)
            printf("\t%d",arr[i][j]);
        printf("\n");
    }

    return arr[n][r];               
    
}

int main(){
    printf(" 5C3 is = %d",binCoeff(5,3));
}

// Time complexity
// As this algo calculates almost half  
// of matrix nxr it takes time O(n^2)
