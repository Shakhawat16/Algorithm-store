#include<bits/stdc++.h>
using namespace std;
struct Event{
    int st_time;
    int finish_time;
    Event(){}
    Event(int _st, int _finish){
        st_time = _st;
        finish_time=_finish;
    }
    void print()
    {
        printf("starting time= %d, finish time=%d",st_time,finish_time);
    }
};
///a<b?
Event E[100];
bool com(Event a, Event b)
{
   if(a.finish_time<b.finish_time)
        return true;
   return false;
}
int main()
{
    freopen("input.txt","r",stdin);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&E[i].st_time,&E[i].finish_time);
    }
    for(int i=0;i<N;i++)
    {
        E[i].print();
        printf("\n");
    }
    sort(E,E+N,com);
    printf("\nAfter Sorting and calculating\n\n");
    int time=0,performed=0;
    for(int i=0;i<N;i++){

        E[i].print();
        if(time<=E[i].st_time){
            printf(" \t Selected\n");
            time=E[i].finish_time;
            performed++;
        }
        else {
            printf(" \t Not Selected\n");
        }
    }
    printf("\nMaximum activity performed: %d\n", performed);

    return 0;
}
