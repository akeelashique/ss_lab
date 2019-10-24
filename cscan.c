#include<stdio.h>
#include<stdlib.h>
void main()
{
int n,cur_track=0,distance=0,seek_count=0,ar[100],ar1[100],ar2[100];
srand(time(0));
 printf("enter the number of elements\n");
 scanf("%d",&n);
 int head=100,s=1,l=1;
 ar1[0]=0;
 ar2[0]=200;
 for(int i=1;i<n;i++)
 {
  int temp=(rand()%200+1);
  printf("::%d ",temp);
  if(temp<head)
  {
   ar1[s]=temp;
   s++;
  }
  else
  {
   ar2[l]=temp;
   l++;
  }
 }
 if(s!=0){
 for (int i=0;i<s;i++) 
 {
  for (int j=i+1;j<s;j++)
  {
   if (ar1[i] > ar1[j]) 
   {
    int temp =  ar1[i];
    ar1[i] = ar1[j];
    ar1[j] = temp;
   }
  }
 }
 }
 if(l!=0){
 
 for (int i=0;i<l;i++) 
 {
  for (int j=i+1;j<l;j++)
  {
   if (ar2[i] > ar2[j]) 
   {
    int temp =  ar2[i];
    ar2[i] = ar2[j];
    ar2[j] = temp;
   }
  }
 }
 }
 printf("\nseek sequence is :");
 if(l!=0){
 for(int j=0;j<l;j++)
 {
  cur_track=ar2[j];
  distance=abs(cur_track-head);
  seek_count+=distance;
  head=cur_track;
  printf("%d ",ar2[j]);
 }
 }
 if(s!=0){
 for(int j=0;j<s;j++)
 {
  cur_track=ar1[j];
  distance=abs(cur_track-head);
  seek_count+=distance;
  head=cur_track;
  printf("%d ",ar1[j]);
 }
 }
 printf("\nseek count :%d",seek_count);
}
