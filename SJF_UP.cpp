#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
cout<<"Number of Processes: ";
cin>>n;
int at[n],bt[n],done[n];
for (int i = 0; i < n; i++) {
        cout << "P" <<i + 1<< " arrival time burst time: ";
        cin >> at[i] >> bt[i];
        done[i]=0;
    }
    int time =0;
    int count=0;
    float total_tat=0,total_wt=0;
    cout<<"\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    while(count<n){
        int pick = -1;
        for(int i=0;i<n;i++){
            if(done[i]==1) continue;
            if(at[i]>time) continue;
            if(pick == -1) pick = i;
            else if(bt[i]<bt[pick]) pick =i;
            else if(bt[i]==bt[pick]&&at[i]<at[pick]) pick =i;
        }
        if(pick == -1){
            time++;
            continue;
        }
        time = time + bt[pick];
        int ct =time;
        int tat =ct - at[pick];
        int wt = tat - bt[pick];
        cout<<"P"<<pick+1<<"\t"<<at[pick]<<"\t"<<bt[pick]<<"\t"<<ct<<"\t"<<tat<<"\t"<<wt<<"\n";
        total_tat+=tat;
        total_wt += wt;
        done[pick]=1;
        count++;
    }
    cout<<"Avg tat"<<total_tat/n<<endl;
    cout<<"Avg WT"<<total_wt/n<<endl;
    return 0;
}
