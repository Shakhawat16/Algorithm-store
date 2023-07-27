#include<bits/stdc++.h>
using namespace std;

struct Event{
    int weight;
    int profit;
    Event(){}
    Event(int _dur, int _dead){
        weight = _dur;
        profit =_dead;
    }
    void print()
    {
        printf("weight = %d, profit=%d\n",weight,profit);
    }

};
Event E[100];
bool com(Event a, Event b)
{
   if(a.profit>b.profit)
        return true;
   return false;
}

int main()
{
//    freopen("input.txt","r",stdin);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&E[i].weight,&E[i].profit);
    }
    int W,picked=0;
    long long total_profit=0;
    printf("Ability: ");
    scanf("%d", &W);
     sort(E,E+N,com);
    for(int i=0;i<N;i++)
    {
        cout<<"\n";
        E[i].print();
        if(W>0){
            if(W-picked>E[i].weight){
                picked+=E[i].weight;
               total_profit+=(E[i].weight)*(E[i].profit);
               cout<<E[i].weight<<"picked\t profit gathered: "<<total_profit;
            }
            else {
                total_profit+=(W-picked)*(E[i].profit);
                picked+=W-picked;
                cout<<W-picked<<"picked\t profit: "<<total_profit;
            }
        }
    }
    cout<<"\nMaximum profit: "<<total_profit<<"\n";
    return 0;
}
