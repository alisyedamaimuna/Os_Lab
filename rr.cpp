#include <bits/stdc++.h>
using namespace std;

int main(){
int n,tq;
cout<<"Number of Processes: ";
cin>>n;
int at[n], bt[n],rt[n], ct[n], tat[n], wt[n],added[n];
for(int i=0;i<n;i++){
    cout<<"P"<<i+1<<"Arrival time Burst time: ";
    cin>>at[i]>>bt[i];
    rt[i]=bt[i];
    added[i]=0;
}
cout << "Time quantum: ";
    cin >> tq;
    int queue[1000],front = 0,rear = 0;
    int time=0,count=0;
while (count < n) {
        for (int i = 0; i < n; i++) {
            if (added[i] == 0 && at[i] <= time) {
                queue[rear++] = i;
                added[i] = 1;
            }
        }
        if (front == rear) {
            time++;
            continue;
        }
        int p = queue[front++];
int run;

if (rt[p]<tq) {
    run=rt[p];
}
else {
    run=tq;
}
        time=time+run;
        rt[p]=rt[p]-run;
        for (int i=0;i<n;i++) {
            if (added[i]==0&&at[i]<=time) {
                queue[rear++]=i;
                added[i]=1;
            }
        }

        if (rt[p]>0) {
            queue[rear++] = p;
        }
        else {
            ct[p]=time;
            tat[p]=ct[p]-at[p];
            wt[p]=tat[p]-bt[p];
            count++;
        }
    }
float total_tat=0;
float total_wt=0;
cout<<"\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
for(int i=0;i<n;i++){
    cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
    total_tat+=tat[i];
    total_wt+=wt[i];
}
cout<<"Avg tat : "<<total_tat/n<<"Avg wt : "<<total_wt/n;
}

