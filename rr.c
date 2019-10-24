#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void waiting_time(int n,int bt[],int wt[],int quant)
{
 int rem_bt[n];
 for(int i=0;i<n;i++)
 {
  rem_bt[i]=bt[i];
 }
 int t=0;
 while(1)
 {
  int flag=1;
  for(int i=0;i<n;i++)
  {
   if(rem_bt[i]>0)
   {
    flag=0;
    if(rem_bt[i]>quant)
    {
     t+=quant;
     rem_bt[i]-=quant;
    }
    else
    {
     t=t+rem_bt[i];
     wt[i]=t-bt[i];
     rem_bt[i]=0;
    }
   }
  }
  if(flag==1)
  {
   break;
  }
 }
}
 void turn_around(int n,int bt[],int wt[],int tat[])
{
 for(int i=0;i<n;i++)
 {
  tat[i]=bt[i]+wt[i];
 }
}
void avg_time(int processes[],int n,int bt[],int quant)
{
 int wt[n],tat[n],total_wt=0,total_tat=0;
 waiting_time(n,bt,wt,quant);
 turn_around(n,bt,wt,tat);
 printf("P   BT   WT   TA");
 for(int i=0;i<n;i++)
 {
  total_wt=total_wt+wt[i];
  total_tat=total_tat+tat[i];
  printf("\n");
  printf("%d",(i+1));
  printf("  %d",bt[i]);
  printf("    %d",wt[i]);
  printf("     %d",tat[i]);
 }
 int s=(float) total_wt / (float) n;
 int t=(float) total_tat / (float) n;
 printf("average wt=%d",s);
 printf("average ta=%d",t);
}
int main()
{
 int n,processes[20],bt[20],t;
 srand(time(0));
 printf("enter the number of process\n");
 scanf("%d",&n);

 t=((rand()%5)+1);
 printf("time quantum is %d\n",t);
 //printf("enter burst time\n");
 for(int i=0;i<n;i++)
 {
   bt[i]=(rand()%10);
  //scanf("%d",&bt[i]);
  //processes[i]=i+1;
 }
 for(int i=0;i<n;i++)
 {
  //scanf("%d",bt[i]);
  processes[i]=i+1;
 }

 avg_time(processes,n,bt,t);
 return 0;
}
