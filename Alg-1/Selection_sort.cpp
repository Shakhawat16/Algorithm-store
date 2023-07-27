#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
int main()
{
    cout<<"Enter number of data: ";
    int n;
    cin>>n;
    int ar[n];
    cout<<"Enter Raw data: "<<N;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    int key;
    for(int i=0;i<n-1;i++){
        key=i;
        for(int j=i+1;j<n;j++){
            if(ar[j]<ar[key]){
                key=j;
            }
        }
        swap(ar[i],ar[key]);
    }
    cout<<"Sorted Array: "<<N;
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<N;
}






