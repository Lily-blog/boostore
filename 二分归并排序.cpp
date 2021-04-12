#include <iostream>
using namespace std;

void Merge(int a[],int L,int M,int R){
   
   int left_size=M-L+1;
   int right_size=R-M; 
   
   int left[left_size];
   int right[right_size]; 
   
   for(int i=L;i<=M;i++){
     left[i-L]=a[i];
   }
   for(int i=M+1;i<=R;i++){
     right[i-(M+1)]=a[i];
   }
   
   int i=0,j=0,k=L;
   
   while(i<left_size && j<right_size){
     if(left[i]<right[j]){
       a[k]=left[i];
       i++;
       k++;
     }else{
       a[k]=right[j];
       j++;
       k++;
     }
   }
   
   while(j<right_size){
     a[k]=right[j];
     j++;
     k++;
   }
   
   while(i<left_size){
     a[k] = left[i] ;
     i++;
     k++;
 }}
 
void MergeSort(int a[],int L,int R){
    
    if(R==L){
       return ;
    }
   
    int M=(L+R)/2;
    MergeSort(a,L,M);
    MergeSort(a,M+1,R);
    
    Merge(a,L,M,R);
}
int main(){
    int a[]={11,8,3,9,7,1,2,5};
    MergeSort(a,0,7);
    for(int i=0;i<8;i++){
      cout<<a[i]<<" ";
    }
}
