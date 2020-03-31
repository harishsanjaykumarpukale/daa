#include<stdio.h>

void main(){
    int i,j,k,n,a[10][10][2],flag=1;
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j][0]);
    
    for(k=0;k<n;k++){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j][flag] = a[i][j][!flag] || ( a[i][k][!flag] & a[k][j][!flag] );
        flag=!flag;
    }
        
    printf("The transitive closure is :");
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("\t%d",a[i][j][!flag]);
        printf("\n");
    }
}

//Time Complexity is O(n^3) as it involves updating each element matrix n times. 
