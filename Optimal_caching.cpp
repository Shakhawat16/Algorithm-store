#include<bits/stdc++.h>
using namespace std;

string Frames;
string Requests;

int main()
{
//    freopen("input_OptimalCaching.txt","r",stdin);
    int FrameSize;
    scanf("%d",&FrameSize);
    cout<<"Frame: ";
    cin>>Frames;
    cout<<"Request: ";
    cin>>Requests;
    int cnt=0;
    int fr_size=Frames.size();
    int rq_size=Requests.size();
    cout<<"\nRequest \thit/miss \t replaced by \tpresent cache\n";
    for(int i=0;i<rq_size;i++){
        cout<<Requests[i]<<" \t";
        bool hit=false;
        for(int j=0;j<fr_size;j++){
            if(Requests[i]==Frames[j]){
                hit=true;
                break;
            }
        }
        if(hit){
          cout<<"\thit \t\t none \t\t";

        }
        else{
            cout<<"\tmiss \t\t ";


        }
        int repl_ind,mx_dist=0;
        for(int j=0;j<fr_size;j++){
            int dis=INT_MAX;
            for(int k=i+1;k<rq_size;k++){
                if(Frames[j]==Requests[k]){
                    dis=k-i;
                    break;
                }
            }
            if(mx_dist<dis){
                mx_dist=dis;
                repl_ind=j;
            }

        }

        if(!hit){
            cnt++;
            cout<<Frames[repl_ind]<<"\t\t";
        }
        Frames[repl_ind]=Requests[i];
        for(int j=0;j<fr_size;j++)cout<<Frames[j];
        cout<<"\n";

    }
    cout<<"Minimum miss: "<<cnt<<"\n";

    return 0;
}
