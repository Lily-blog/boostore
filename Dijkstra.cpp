#include<iostream>
#include<cstring>
#include<vector>
#define N 1001
using namespace std;
int dis[N],n,m,s,h,visited[N];
int u,v,w;
struct Node{
  int to;
  int v;
};
vector<Node> VT[N];
Node at;
void addEdge(int a,int b,int c){
    at.to=b;
    at.v=c;
    VT[a].push_back(at);
}
void dijkstra(int s){
     
     memset(dis,0x3f,sizeof(dis));
     dis[s]=0;
     
     
     for(int i=0;i<n;i++){
           int k=-1;
           int MIN=0x3f;
           
           
           for(int j=0;j<n;j++){
               if(visited[j]==0&&dis[j]<MIN){
                   k=j;
                   MIN=dis[j];
               }
           }
           if(k==-1){
               return ;
           }
           
           visited[k]=true;
           
           
for(int index=0;index<VT[k].size();index++){
               
               int j=VT[k][index].to;
               
               if(visited[j]==0&&dis[j]>dis[k]+VT[k][index].v){
                    dis[j]=dis[k]+VT[k][index].v;
               }
           }  
     } 
}
int main(){
     cin>>n>>m>>s>>h; 
     for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        addEdge(u,v,w);
     }
     dijkstra(s);
     
         cout<<dis[h]<<" ";
     
     return 0;
 }
