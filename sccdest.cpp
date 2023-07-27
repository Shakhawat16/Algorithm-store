#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int>G[N];
vector<int>TG[N];
vector<bool>visited(N);
vector<int>fin_seq;
vector<int>scc;
vector<pair<int,int>>edge;

int parent[N];
void make(int k){
	for(int i=0;i<scc.size();i++){
		parent[scc[i]]=k;
	}
}
int find_root(int a){
	if(parent[a]==a){
		return a;
	}
	return parent[a]=find_root(parent[a]);
}
//void Union(int a,int b){
//	a=find_root(a);
//	b=find_root(b);
//	if(a!=b){
//		parent[b]=a;
//	}
//}
void dfs1(int u)
{
    visited[u]=true;
    for(auto v:G[u])
    {
        if(!visited[v])
        {
            dfs1(v);
        }
    }
    fin_seq.push_back(u);
}


void dfs2(int u)
{
    visited[u]=true;
    scc.push_back(u);
    for(auto v:TG[u])
    {
        if(!visited[v])
        {
            dfs2(v);
        }
    }


}


int main()
{
    cout<<"Enter number of nodes and edges: ";
    int n,e;
    cin>>n>>e;
    cout<<"Enter directed edges:\n";
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        TG[v].push_back(u);
        edge.push_back(make_pair(u,v));
    }

    for(int i=1; i<=n; i++)
    {
        visited[i]=false;
    }

    for(int i=1; i<=n; i++)
    {
        if(visited[i]==false)
        {
//        	cout<<"here"<<endl;
            dfs1(i);
        }
    }
    reverse(fin_seq.begin(),fin_seq.end());
    for(int i=0; i<=n; i++)
    {
        visited[i]=false;
    }
    int nscc=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            nscc++;
            dfs2(i);
//            cout<<"\nscc-"<<nscc<<": ";
//            for(int j=0; j<scc.size(); j++)
//            {
//                cout<<scc[j]<<" ";
//            }
            if(scc.size()>0)make(scc[0]);
            scc.clear();

        }
    }
    long long int need=0;
    need+=2*nscc-2;
    need++;
    for(int i=0;i<edge.size();i++){
        int u,v,x,y;
        u=edge[i].first;
        v=edge[i].second;
        x=find_root(u);
        y=find_root(v);
        if(x==y)continue;
        else{
            need--;
        }
    }
    cout<<need<<"\n";
//    cout<<"\ntotal scc: "<<nscc<<"\n";

}

