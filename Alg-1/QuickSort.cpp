#include<bits/stdc++.h>
using namespace std;
int ar[]={5,2,6,1,3,4};
int Partition(int L, int R){
int pivotIndex=L;
while(L!=R){
  if(pivotIndex==L){
    if(ar[pivotIndex]<ar[R]){
      R--;
    }
    else{
      swap(ar[pivotIndex],ar[R]);
      pivotIndex=R;
    }
  }
  else {
    if(ar[L]<ar[pivotIndex]) {
     L++;
    }
    else{
      swap(ar[pivotIndex],ar[L]);
      pivotIndex=L;
    }
  }
}
return L;
}
void QuickSort(int L,int R){
  if(L>=R) return;
int mid=Partition(L,R);
QuickSort(L,mid-1);
QuickSort(mid+1,R);
}
int main(){
cout<<"Before sorting: ";
for(int i=0;i<6;i++) cout<<ar[i]<<" ";
cout<<endl;
QuickSort(0,5);
cout<<"After sorting: ";
for(int i=0;i<6;i++) cout<<ar[i]<<" ";
}
