#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
int main()
{    cout<<"Enter number of data: ";
    int n;
    cin>>n;
    int ar[n];
    cout<<"Enter Raw data: "<<N;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int j;
        int key;
    for(int i=1;i<n;i++){
        j=i-1;
        key=ar[i];
        while(j>=0){
            if(ar[j]>key){
                ar[j+1]=ar[j];
                j--;
            }
            else{
                break;
            }
        }
        ar[j+1]=key;
    }
    cout<<"Sorted Array: "<<N;
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<N;
}





