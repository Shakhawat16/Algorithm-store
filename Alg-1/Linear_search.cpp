#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N '\n'
#define ull unsigned ll
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define file freopen("in.txt","r",stdin);
#define L size()
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define B begin()
#define E end()
#define sp " "
int Ns=1e5+5;

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
    int idx=-1;
    cout<<"Enter number which you are searching for: ";
    int x;
    cin>>x;
    for(int i=0;i<n;i++){
        if(ar[i]==x){
            idx=i+1;
            break;
        }
    }
    if(idx==-1){
        cout<<"\nNumber not found!!\n";
    }
    else{
        cout<<"Number found at "<<idx<<"th position!\n";
    }
}



