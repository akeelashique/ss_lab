#include<stdio.h>
#include<stdlib.h>
void main()
{
int n,cur_track,distance,seek_count,ar[100];
srand(time(0));
 printf("enter the number of elements\n");
 scanf("%d",&n);
 int head=50;
 for(int i=0;i<n;i++)
 {
  ar[i]=rand()%200+1;
  printf("::%d ",ar[i]);
 }
 for(int j=0;j<n;j++)
 {
  cur_track=ar[j];
  distance=abs(cur_track-head);
  seek_count+=distance;
  head=cur_track;
 }
 printf("seek count :%d",seek_count);
 printf("\nseek sequence is :");
 
 for(int p=0;p<n;p++)
 {
  printf("%d ",ar[p]);
 }
}
