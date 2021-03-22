
#include <stdio.h>
#include <math.h>
int Binary_Search(int T[],int n,int x)
{
	int wei=n;
	int tou=1;
	int m;
    while(tou<=wei)
        {
        	m=floor((wei+tou)/2.0);
            if(x<T[m])
                wei=m-1;
            else if(x>T[m])
                tou=m+1;
            else
                return m;
        }
    return 0;
}
int main()
{
	int T[100],n,x,i; 
	scanf("%d",&n);
	for( i=0;i<n;i++)
        scanf("%d",&T[i]);
    scanf("%d",&x);
    printf("%d\n",Binary_Search(T,n,x));
	return 0;
}

