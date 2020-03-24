#include<stdio.h>
#include<stdlib.h>
int count=0,flag=1,n;

void swap(int *p,int *q){
  *p=*p+*q;
  *q=*p-*q;
  *p=*p-*q;
  
  flag=1;
}

void brickSort(int a[]){
  int i;
  
  while(flag){
    flag=0;
    for(i=1;i<=n-2;i+=2){
      count+=1;
      if(a[i]>a[i+1])
        swap(&a[i],&a[i+1]);
    }
      
    
    
    for(i=0;i<=n-2;i+=2){
      count+=1;
      if(a[i]>a[i+1])
        swap(&a[i],&a[i+1]);
    }
      
  }
}
void main(){
  int a[520],i,j;
  printf("\nEnter the no of elements:");
  scanf("%d",&n);
  printf("\nEnter the elements:");
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);
  brickSort(a);
  printf("\nSorted list is:");
  for(i=0;i<n;i++)
      printf("\t%d",a[i]);
  printf("\nCount is: %d",count);
  
  printf("\nTime Complexity\n");
  printf("\nSize\tASC\tDESC\tRAN\n");
  for(i=16;i<520;i*=2){
    n=i;
    for(j=1;j<=i;j++)
      a[j]=j;
    
    count=0;
    flag=1;
    brickSort(a);
    printf("\n%d\t%d\t",i,count);
    
    for(j=1;j<=i;j++)
      a[j]=i-j;
    
    
    flag=1;    
    count=0;
    brickSort(a);
    printf("%d\t",count);
    
    for(j=1;j<=i;j++)
      a[j]=rand()%i;
    
    flag=1;
    count=0;
    brickSort(a);
    printf("%d",count);
  }
  
}
