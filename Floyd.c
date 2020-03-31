#include<stdio.h>
int min(int a,int b){
    if(a>b)
        return b;
    return a;
}

void main(){
    int i,j,k,n,a[10][10][2],flag=1;
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    
    printf("\nEnter the weight matrix assuming infinity = 1 + sum of all weights :\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j][0]);
    
    for(k=0;k<n;k++){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j][flag] = min(a[i][j][!flag] , (a[i][k][!flag] + a[k][j][!flag])) ;
        flag=!flag;
    }
        
    printf("The shortest path matrix is :\n");
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("\t%d",a[i][j][!flag]);
        printf("\n");
    }
}

//Output for graph with four vertices and edges as follows
// (a,c) -- 3
// (b,a) -- 2
// (c,b) -- 7
// (c,d) -- 1
// (d,a) -- 6


//Enter the number of vertices:>>>4

//Enter the weight matrix assuming infinity = 1 + sum of all weights :
//>>>0 20 3 20
//>>>2 0 20 20
//>>>20 7 0 1
//>>>6 20 20 0
//The shortest path matrix is :
//	0	10	3	4
//	2	0	5	6
//	7	7	0	1
//	6	16	9	0
//
//
//Process Finished.


//Time Complexity is O(n^3) as it uses the startegy from waeshall's algo.
