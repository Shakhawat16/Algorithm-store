#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of element: ";
    cin>>n;
    int ar[n];
    int mx=INT_MIN;
    cout<<"Enter array element: ";
    for(int i=0;i<n;i++){
        cin>>ar[i];
        mx=max(ar[i],mx);
    }
    int cnt[mx+1]={0};
    for(int i=0;i<n;i++){
        cnt[ar[i]]++;
    }
    int j=0;
    for(int i=0;i<=mx;i++){
        while(cnt[i]){
            ar[j]=i;
            cnt[i]--;
            cout<<i<<" ";
            j++;
        }
    }
}
