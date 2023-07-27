#include<bits/stdc++.h>
using namespace std;
string lcs(string s,string ss){
    int n=s.size();
    int m=ss.size();
    string ans[n+1][m+1];
    int l[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
        	 if(!i or !j){
               l[i][j]=0;
               ans[i][j]="";
        	  }
        	  else if(s[i-1]==ss[j-1]){
                l[i][j]=l[i-1][j-1]+1;
                        ans[i][j]=ans[i-1][j-1]+s[i-1];
        	}
        	else{
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            	  if(ans[i-1][j].size()>ans[i][j-1].size()){
             ans[i][j]=ans[i-1][j];

	}else{
                	ans[i][j]=ans[i][j-1];
               }
            }
         }
      }
    return ans[n][m];
}
int main(){
       cout<<"Enter string 1: ";
       string s1,s2;
       cin>>s1;
       cout<<"Enter string 2: ";
       cin>>s2;
       string s=lcs(s1,s2);
       cout<<"The length of lcs is: ";
       cout<<s.size()<<endl;
       cout<<"lcs is: "<<s<<endl;
       return 0;
}
