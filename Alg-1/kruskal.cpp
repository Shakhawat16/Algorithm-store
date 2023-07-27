#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
	node(){}
	node(int _u,int _v,int _w){
		u=_u;
		v=_v;
		w=_w;
	}
};
const int N=1e3;
int parent[N];
void make(){
	for(int i=0;i<N;i++){
		parent[i]=i;
	}
}
int find(int a){
	if(parent[a]==a){
		return a;
	}
	return parent[a]=find(parent[a]);
}
void Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		parent[b]=a;
	}
}
int main()
{
	make();
	cout<<"Enter vertex: ";
	int n;cin>>n;
	cout<<"Enter edge: ";
	int e;cin>>e;
	vector<node>v;
	for(int i=0;i<e;i++){
		int a,b,c;cin>>a>>b>>c;
		v.push_back(node(a,b,c));
	}
	sort(v.begin(),v.end(),[&](node aa,node bb){
		return aa.w<bb.w;
	});
	int ans=0;
	for(node aa: v){
		if(find(aa.v)!=find(aa.u)){
			ans+=aa.w;
			Union(aa.v,aa.u);
		}
	}
	cout<<"The weight of the minimum ";
	cout<<"tree is: ";
	cout<<ans<<endl;
}
