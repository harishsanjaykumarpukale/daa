// question at https://www.codechef.com/problems/FFL

#include<bits/stdc++.h>

int main(){
    int t,n,s,p[100],f,mindp,minfp;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&s);
        s=100-s;
//         printf("\nn-%d and s-%d",n,s);
        for(int i=0;i<n;i++)
            scanf("%d",&p[i]);
        
//         for(int i=0;i<n;i++)
//             printf("\n%d",p[i]);
        
        minfp = INT_MAX;
        mindp = INT_MAX;
        
        for(int j=0;j<n;j++){
            scanf("%d",&f);
//             printf("\n%d",f);
            if(f==0)
                if(p[j]<mindp)
                    mindp = p[j];
            if(f==1)
                if(p[j]<minfp)
                    minfp = p[j];
            
        }
//         printf("mindp  - %d  minfp  - %d  ",mindp,minfp);
        
        if(mindp == INT_MAX || minfp == INT_MAX){
            printf("no\n");
            continue;
        }
        if(minfp+mindp<=s)
            printf("yes\n");
        else
            printf("no\n");
        
        
    }
    return 0;
}
