#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void waiting_time(int n,int bt[],int wt[])
{
 wt[0]=0;
 for(int i=1;i<n;i++)
 {
  wt[i]=bt[i-1]+wt[i-1];
 }
}
void turn_around(int n,int bt[],int wt[],int tat[])
{
 for(int i=0;i<n;i++)
 {
  tat[i]=bt[i]+wt[i];
 }
}
void avg_time(int processes[],int n,int bt[])
{
 int wt[n],tat[n],total_wt=0,total_tat=0;
 waiting_time(n,bt,wt);
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
 int n,processes[20],bt[20];
 srand(time(0));
 printf("enter the number of process\n");
 scanf("%d",&n);
 //printf("enter burst time\n");
 for(int i=0;i<n;i++)
 {
  //scanf("%d",&bt[i]);
  //processes[i]=i+1;
  bt[i]=(rand()%20);
 }
 for(int i=0;i<n;i++)
 {
  //scanf("%d",bt[i]);
  processes[i]=i+1;
 }
 avg_time(processes,n,bt);
 return 0;
}
