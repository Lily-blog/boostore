#include<stdio.h>
#include<stdlib.h>
int Search(int T[],int n,int x){
	int i; 
    for( i=0;i<n;i++){
if(x==T[i])
return i;
    }
    return 0;
}
int main(){
    int T[105],n,x,i;
    scanf("%d",&n);
    for( i = 0;i<n;i++)
    scanf("%d",&T[i]);
    scanf("%d",&x);
    printf("%d\n",Search(T,n,x));
    return 0;

    
}
