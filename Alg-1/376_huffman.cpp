#include<bits/stdc++.h>
using namespace std;
map<pair<int,string>,int>mp;
priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
pair<int,string>Node[100];
vector<int>Tree[100];
int total=0;
void GO(int root, string codeword){
    if(Tree[root].size()>1){
        //left
        GO(Tree[root][0],codeword+"0");
        //right
        GO(Tree[root][1],codeword+"1");
    }
    else{
        cout<<Node[root].second<<"-->\tcodeword= "<<codeword<<"\tlength= "<<codeword.size()<<"\n";
        total+=codeword.size()*Node[root].first;
    }
}

int main(){
cout<<"Character number: ";
int n;
cin>>n;
cout<<"character and frequency:\n";
for(int i=1;i<=n;i++){
    int x;
    string y;
    cin>>y>>x;
    pair<int,string>A=make_pair(x,y);
    mp[A]=i;
    pq.push(A);
    Node[i]=A;
}
int nn=pq.size();
while(pq.size()>1){
    pair<int,string> a,b,ab;
    a=pq.top();
    pq.pop();
    b=pq.top();
    pq.pop();
    ab.first=a.first+b.first;
    ab.second=a.second+b.second;
    pq.push(ab);
    nn++;
    mp[ab]=nn;
    Node[nn]=ab;
    int u,v,w;
    u=mp[a];
    v=mp[b];
    w=mp[ab];
    Tree[w].push_back(u);
    Tree[w].push_back(v);
}
int root=mp[pq.top()];
GO(root,"");
cout<<"\n Total codeword need: "<<total<<"\n";
}
