#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
int pid[n],at[n],bt[n],ct[n],tat[n],wt[n];
for(int i=0;i<n;i++){
    pid[i]=i+1;
    cout<<"p"<<pid[n]<<"arrival time burst time : ";
    cin>>at[i]>>bt[n];
}
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
        if(at[j]>at[j+1]){
            int t;
            t=at[j]; at[j]=at[j+1];at[j+1]=t;
            t=bt[j]; bt[j]=bt[j+1];bt[j+1]=t;
            t=pid[j]; pid[j]=pid[j+1];pid[j+1]=t;
        }
    }
}
int time = 0;
float total_tat=0,total_wt=0;
for(int i=0;i<n-1;i++){
    if(time<at[i]) time = at[i];
    time = time + bt[i];
    ct[i]=time;
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    total_tat += tat[i];
    total_wt += wt[i];
}
cout<<"\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
for(int i=0;i<n;i++){
    cout<<"P"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
}
cout<<"avg tat = "<<total_tat/n<<endl;
cout<<"avg wt = "<<total_wt/n<<endl;
return 0;
}
