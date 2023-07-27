#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5;
vector<int>v[N];
void bfs(int s,int n){
	map<int,bool>vis;
	stack<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.top();
		if(not vis[u]){
			cout<<u<<" ";
			vis[u]=true;
		}
		q.pop();
		for(int i:v[u]){
			if(not vis[i]){
				q.push(i);
			}
		}
	}
	cout<<endl;
}
int main()
{
	cout<<"Enter number of vertex: ";
	int a,b,n,e;cin>>n;
	cout<<"Enter number of edges: ";
	cin>>e;
	cout<<"add edges:\n";
	for(int i=0;i<e;i++){
		cin>>a>>b;
		v[a].pb(b);
	}
	cout<<"Enter source vertex: ";
	int s;cin>>s;
	cout<<"BFS traversal is: ";
	bfs(s,n);
}
