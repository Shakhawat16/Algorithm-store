#include<bits/stdc++.h>
const int inf=1e6;
using namespace std;
struct node{
	int x,y,wt;
	node(){}
	node(int _x,int _y,int _wt){
		x=_x;
		y=_y;
		wt=_wt;
	}
};
int main()
{
	freopen("in.txt","r",stdin);
	int n,e;cin>>n>>e;
	vector<node>edges;
	for(int i=0;i<e;i++){
		int a,b,c;cin>>a>>b>>c;
		edges.push_back(node(a,b,c));
		edges.push_back(node(b,a,c));
	}
	vector<int>dist(n,inf);
	int source;cin>>source;
	dist[source]=0;
	for(int i=1;i<n;i++){
		for(node x:edges){
			int v=x.x,y=x.y,wt=x.wt;
			if(dist[v]!=inf and dist[v]+wt<dist[y]){
				dist[y]=dist[v]+wt;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<i<<": "<<dist[i]<<endl;
	}
}
