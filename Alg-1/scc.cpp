#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5;
vector<int>v[N];
map<int,bool>vis;
struct node{
	int start;
	int finish;
	int nde;
};
node st[N];
int cnt=1;
void dfs(int s){
	vis[s]=true;
	st[s].start=cnt;
	cnt++;
	for(int k:v[s]){
		if(not vis[k]){
			dfs(k);
		}
	}
	st[s].finish=cnt;
	cnt++;
}
void dfss(int s){
	cout<<s<<" ";
	vis[s]=true;
	for(int K:v[s]){
		if(not vis[K]){
			dfss(K);
		}
	}
}
int main()
{
	int a,b,e;cin>>e;
	pair<int,int>in[N];
	for(int i=0;i<N;i++){
		in[i].second=0;
		st[i].start=0;
		st[i].finish=0;
		st[i].nde=i;
	}
set<int>used;
	for(int i=0;i<e;i++){
		cin>>a>>b;
		used.insert(a);
		used.insert(b);
		v[a].pb(b);
		in[b].second++;
		in[b].first=b;
	}
	sort(in,in+N,[&](pair<int,int>aa,pair<int,int>bb){
		return aa.second<bb.second;
	});
	for(pair<int,int> i:in){
		if(not vis[i.first] and used.find(i.first)!=used.end()){
			dfs(i.first);
		}
	}
	vector<node>k;
	for(int i:used){
		cout<<st[i].nde<<": "<<st[i].start<<" "<<st[i].finish<<endl;
		k.pb(st[i]);
	}
	vis.clear();
	sort(k.begin(),k.end(),[&](node aa,node bb){
		return aa.finish>bb.finish;
	});
	for(node K:k){
		if(!vis[K.nde]){
			cout<<K.nde<<" ";
		}
	}
}

