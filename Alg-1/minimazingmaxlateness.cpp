#include<bits/stdc++.h> 
using namespace std;

struct event
{
	int duration;
	int deadline;
	int late = 0;
	int End = 0;
	void print()
	{
		printf("duration =  %d\tdeadline =  %d\tlate = %d\n",duration,deadline,late);
	}
};
bool comparator(event a, event b)
{
	return
	a.deadline < b.deadline;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	printf("Enter number of  events.\n");
	int n;
	scanf("%d", &n);
	event events[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &events[i].duration,&events[i].deadline);
	}
	sort(events,events + n,comparator);
	events[0].End = events[0].duration;
	events[0].late = max(events[0].duration-events[0].deadline, 0);
	events[0].print();
	for (int i = 1; i < n; i++)
	{
		events[i].late = max(events[i-1].End + events[i].duration-events[i].deadline, 0);
		events[i].End = events[i].duration + events[i - 1].End;
		events[i].print();
	}
	return 0;
}
