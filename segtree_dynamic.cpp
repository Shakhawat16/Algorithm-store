#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll mn,beg,ed,lazy;
    bool lazyfl;
    node *lft,*rgt;
    node(){}
    node(ll l,ll r){
    beg=l;
    ed=r;
    lazyfl=0;
    lazy=0;
    lft=NULL;
    rgt=NULL;
    mn=INT_MAX;
    }
};
void build(ll pos,ll beg,ll en){
if(beg==en){
    seg[pos]=ar[beg];
    return;
}
ll mid=(beg+en)/2;
//left
build(2*pos,beg,mid);
//right
build(2*pos+1,mid+1,en);
//mnset
seg[pos]=min(seg[2*pos],seg[2*pos+1]);
}

ll query(ll pos,ll beg,ll en,ll ql,ll qr){
    if(lazyfl[pos]){
        seg[pos]=lazy[pos];
        lazy[2*pos]=lazy[pos];
        lazy[2*pos+1]=lazy[pos];
        lazyfl[pos]=0;
    }
    if(beg==ql&&en==qr){
        return seg[pos];
    }
    ll mid=(beg+en)/2;
    if(qr<=mid){
        return query(2*pos,beg,mid,ql,qr);
    }
    else if(ql>mid){
        return query(2*pos+1,mid+1,en,ql,qr);
    }
    else{
        ll l=query(2*pos,beg,mid,ql,mid);
        ll r=query(2*pos+1,mid+1,en,mid+1,qr);
        return min(l,r);
    }

}
void update(ll pos,ll beg,ll en,ll ul,ll ur,ll val){
    if(lazyfl[pos]){
        seg[pos]=lazy[pos];
        lazy[2*pos]=lazy[pos];
        lazy[2*pos+1]=lazy[pos];
        lazyfl[pos]=0;
    }
    if(ul>en||ur<beg)return;
    if(beg==ul&&en==ur){
        lazyfl[pos]=1;
        lazy[pos]=val;
        seg[pos]=val;
        return;
    }
    ll mid=(beg+en)/2;
    if(ur<=mid){
        update(2*pos,beg,mid,ul,mid,val);
    }
    else if(ul>mid){
        update(2*pos+1,mid+1,en,mid+1,ur,val);
    }
    else{
        update(2*pos,beg,mid,ul,mid,val);
        update(2*pos+1,mid+1,en,mid+1,ur,val);
    }
    seg[pos]=min(seg[2*pos],seg[2*pos+1]);
}
int main(){
ll n;
cin>>n;

for(ll i=1;i<=n;i++)cin>>ar[i];
build(1,1,n);
for(ll i=1;i<=4*10;i++)cout<<seg[i]<<" ";
cout<<'\n';
cout<<"enter no. of query:";
ll q;
cin>>q;
while(q--){
    cout<<"1.query\n2.update\n";
    ll a;
    cin>>a;
    if(a==1){
        ll u,v;
        cin>>u>>v;
       cout<<query(1,1,n,u,v)<<'\n';
    }
    else if(a==2){
        ll u,v,val;
        cin>>u>>v>>val;
        update(1,1,n,u,v,val);
    }
}

}
