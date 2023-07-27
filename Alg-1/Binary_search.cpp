#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
int Ns=1e5+5;
int BinSearch(int ar[],int l, int r,int x){
    if(r>=l){
        int mid=l+(r-l)/2;
        if(ar[mid]==x){
            return mid+1;
        }
        else if(x>ar[mid]){
           return BinSearch(ar,mid+1,r,x);
        }
        else{
           return BinSearch(ar,l,r-1,x);
        }
    }
    else return -1;
}
int main()
{
    cout<<"Enter number of data: ";
    int n;
    cin>>n;
    int ar[n];
    cout<<"Enter sorted data: "<<N;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int idx=-1;
    cout<<"Enter number which you are searching for: ";
    int x;
    cin>>x;
    idx=BinSearch(ar,0,n-1,x);
    if(idx==-1){
        cout<<"\nNumber not found!!\n";
    }
    else{
        cout<<"Number found at "<<idx<<"th position!\n";
    }
}



