#include<bits/stdc++.h>
const int inf=9999999;
const int N=1e5;
#define pb push_back

using namespace std;
vector<pair<int,int>>v[N];
struct node{
	int x,cost;
	node(){}
	node(int _x,int _cost){
		x=_x;
		cost=_cost;
	}
};
bool operator<(node a,node b){
	return a.cost>b.cost;
}
priority_queue<node>pq;
int main()
{
	cout<<"Enter number of nodes: ";
	int a,b,c,n,e,ans=0;cin>>n;
	cout<<"\nEnter number of edges: ";
	cin>>e;
	cout<<"add edges\n";
	for(int i=0;i<e;i++){
		cin>>a>>b>>c;
		v[a].pb({b,c});
		v[b].pb({a,c});
	}
	int cost[N];bool taken[N];
	for(int i=0;i<N;i++){
		cost[i]=inf;
		taken[i]=false;
	}
	cout<<"Enter sources: ";
	int s;cin>>s;
	pq.push(node(s,0));
	while(!pq.empty()){
		node x=pq.top();pq.pop();
		if(taken[x.x]){
			continue;
		}
		ans+=x.cost;
		taken[x.x]=true;
		for(pair<int,int> u:v[x.x]){
			if(taken[u.first]){
				continue;
			}
			if(u.second<cost[u.first]){
				cost[u.first]=u.second;
				pq.push(node(u.first,u.second));
			}
		}
	}
	cout<<"Enter weight of the minimum ";
	cout<<"spanning tree is: "<<ans<<endl;
	return 0;
}
