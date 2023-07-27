#include<bits/stdc++.h>
using namespace std;
void lis(int arr[],int n){
vector<int>lis(n,1),in(n,-1);
for(int i=1;i<n;i++){
for(int j=0;j<i;j++){
	if(arr[i]>arr[j] and lis[i]<lis[j]+1){
	 lis[i]=lis[j]+1;
	 in[i]=j;
	}
}
}
int cnt=0,ls=-1;
for(int i=0;i<n;i++){
if(cnt<lis[i]){
cnt=lis[i];
ls=i;
}
}
cout<<"Length of lis is: "<<cnt<<endl;
list<int>lst;
while(ls!=-1){
lst.push_front(arr[ls]);
ls=in[ls];
}
cout<<"Lis is: ";
for(int data:lst){
cout<<data<<" ";
}
cout<<endl;
}
int main()
{
cout<<"Enter the size of the array:";
int n
;cin>>n;
cout<<"Enter elements:\n";
int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
lis(arr,n);
}

