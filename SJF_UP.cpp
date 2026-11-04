#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],done[n];
for(int i=0;i<n;i++){
    pid[i]=i+1;
    cout<<"P"<<pid[i]<<" arrival time and Burst time : ";
    cin>>at[i]>>bt[i];
    done[i]=0;
}

int time =0,count = 0;
float total_tat = 0,total_wt=0;
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
    time+=bt[pick];
    ct[pick]=time;
    tat[pick]=ct[pick]-at[pick];
    wt[pick]=tat[pick]-bt[pick];
    cout<<"P"<<pick+1<<"\t"<<at[pick]<<"\t"<<bt[pick]<<"\t"<<ct[pick]<<"\t"<<tat[pick]<<"\t"<<wt[pick]<<"\n";
    total_tat+=tat[pick];
    total_wt+=wt[pick];
    done[pick]=1;
    count++;
}


cout<<"avg tat :"<<total_tat/n<<endl;
cout<<"avg wt :"<<total_wt/n<<endl;
return 0;
}

