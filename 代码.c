#include<stdio.h>

int color[100];
//int c[100][100];
int ok(int k ,int c[][100])
{
    int i,j;
    for(i=1;i<k;i++)
        if(c[k][i]==1&&color[i]==color[k])
            return 0;
        return 1;
}

void graphcolor(int n,int m,int c[][100])
{
    int i,k;
    for(i=1;i<=n;i++)
        color[i]=0;
    k=1;
    while(k>=1)
    {
        color[k]=color[k]+1;
        while(color[k]<=m)
            if (ok(k,c)) break;
            else color[k]=color[k]+1;

        if(color[k]<=m&&k==n)
            {
                for(i=1;i<=n;i++)
                    printf("%d ",color[i]);
                printf("\n");
                
            }
            else if(color[k]<=m&&k<n)
                k=k+1;    
            else
            {
                color[k]=0;
                k=k-1;
            }
    }
}


void main()
{
    int i,j,n,m;
    int c[100][100];
    printf("���붥����n����ɫ��m:\n");
    scanf("%d %d",&n,&m);
    printf("��������ͼ���ڽӾ���:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    printf("��ɫ���п��ܵĽ�:\n");
    graphcolor(n,m,c);
}
