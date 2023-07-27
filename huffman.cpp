#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int,string>,vector<pair<int,string>>, greater<pair<int,string>>>pq;
map<pair<int,string>,int>mp;
pair<int,string>Node[100];
vector<int>Adj[100];

void Dfs(int node, string codeword)
{
    if(Adj[node].size()>0)
    {
        //lft
        Dfs(Adj[node][0],codeword+"0");
        //right
        Dfs(Adj[node][1],codeword+"1");

    }
    else
    {
        cout<<Node[node].second<<"--> \t codeword= "<<codeword<<"\t length= "<<codeword.size()<<"\n";
    }

}

int main()
{
    cout<<"number of character:";
    int n;
    cin>>n;
    cout<<"enter character and frequency:\n";
    for(int i=1; i<=n; i++)
    {
        int x;
        string ch;
        cin>>ch>>x;
        pair<int, string>pr=make_pair(x,ch);
        mp[pr]=i;
        Node[i]=pr;
        pq.push(pr);
    }
    int cnt=pq.size();
    while(pq.size()>1)
    {
        pair<int, string>a,b,c;
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        c.first=a.first+b.first;
        c.second=a.second+b.second;
        pq.push(c);
        cnt++;
        mp[c]=cnt;
        Node[cnt]=c;
        Adj[cnt].push_back(mp[a]);
        Adj[cnt].push_back(mp[b]);

    }
    int call=mp[pq.top()];
    pq.pop();
    Dfs(call, "");
}
