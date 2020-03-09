#include<stdio.h>
#include<stdlib.h>

int weight(int a[],int s1,int e1,int s2,int e2,int *light){
  int j,w1=0,w2=0;
  
  for(j=s1;j<=e1;j++)
    w1+=a[j];
  for(j=s2;j<=e2;j++)
    w2+=a[j];
  
  if(w1==w2)
    return 0 ;
  else{
    if(w1<w2)
      *light = s1;
    else
      *light = s2;
    
    return 1;
  }
}
int light;
void fakecoin(int a[],int n,int i,int j){
  
  if(n==1)
    printf("\nWoohoo Fake coin found\n It is at %d positon and its weight is %d\n",i+1,a[i]);
  
  else if(n%3==0){
    if(weight(a,i,i+n/3-1,i+n/3,i+2*n/3-1,&light))
      fakecoin(a,n/3,light,light+n/3-1);
    else
      fakecoin(a,n/3,i+2*n/3,j);
  }
  
  else{
    if(weight(a,i,i+n/3,i+n/3+1,i+2*n/3,&light))
      fakecoin(a,n/3+1,light,light+n/3);
      
    else
      fakecoin(a,n-2*(n/3+1),i+2*n/3+2,j);
  }
}
void main(){
  int n,a[100],i,choice,random;
  
  printf("\nEnter the number of coins:");
  scanf("%d",&n);
  
  printf("\n Press \n 1 for entering weights of coins manually \n 2 for genarting a random fake coin and proceed \n :");
  scanf("%d",&choice);
  
  switch(choice){
    case 1:
      printf("\nEnter the values :\n");
      for(i=0;i<n;i++)
        scanf("%d",&a[i]);
      break;
    case 2:
      random = rand()%n;
      printf("\nGenerated random number :%d",random+1);
      for(i=0;i<n;i++)
        a[i] = 10;
      a[random] = 5;
      break;
    default:printf("\nEnter a valid choice\n");
  }
  
  fakecoin(a,n,0,n-1);
  
}
