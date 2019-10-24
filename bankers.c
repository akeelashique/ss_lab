#include<stdio.h>
int abort=0;
void safety(int max[20][20],int allocation[20][20],int n,int m)
{
  int count=0,counti=0,need[20][20],order[20],g=0,available[20];
  printf("enter available");
  for(int j=0;j<m;j++)
  {
   scanf("%d",&available[j]);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      need[i][j]=max[i][j]-allocation[i][j];
      //printf("%d",need[i][j]);
    }
    
  }
  
  printf("MAX      ALLOCATION       NEED       AVAILABLE");
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<m;j++)
   {
    printf("%d",max[n][m]);
    printf("      %d",allocation[n][m]);
    printf("                %d",need[n][m]);
    printf("                             %d",available[m]);
   }
  }       
  
  for(int t=0;t<n;t++)
  {
    int flag=0;
    for(int i=0;i<n;i++)
    {
      count=0;
      for(int j=0;j<m;j++)
      {
        //printf("%d",j);
        if(need[i][j]<=available[j] && need[i][j]!=-1)
        {
          count+=1;
          //printf("count==%d",count);
        }
        //printf("it is of process===%d\n",i);
        //printf("count==%d\n",count);
      }
      //printf("\n");
      if(count==m)
      {
        counti+=1;
        //printf("counti==%d\n",counti );
        for(int k=0;k<n;k++)
        {
          available[k]=available[k]+allocation[i][k];
          need[i][k]=-1;
        }
        order[g]=i;
        g+=1;
      }
    }
    if(counti==n)
    {
      printf("\nit is in safe state");
      flag=1;
      abort=1;
      printf("The order is \n");
      for(int e=0;e<n;e++)
      {
        printf("%d",order[e]);
      }
      
      break;
    }
    if(flag==0 && t==n-1)
    {
      printf("it is not in safe state\n" );
      abort=0;
    }
  }
}
int request(int max[20][20],int allocation[20][20],int n,int m)
{
  int count=0,counti=0,need[20][20],order[20],g=0,p,r[20],countn=0,available[20];
  printf("\nenter available\n");
  for(int j=0;j<m;j++)
  {
   scanf("%d",&available[j]);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      need[i][j]=max[i][j]-allocation[i][j];
    }
  }
  printf("\nEnter the process\n");
  scanf("%d",&p);
  printf("enter the resourse\n");
  for(int i=0;i<m;i++)
  {
    scanf("%d",&r[i]);
  }
  for(int i=0;i<m;i++)
  {
    if(r[i]<=need[p][i])
    {
      countn+=1;
    }
  }
  if(countn!=m)
  {
    printf("request is not accepted");
    return(0);
  }
  countn=0;
  for(int i=0;i<3;i++)
  {
    if(r[i]<=available[i])
    {
      countn+=1;
    }
  }
  if(countn!=m)
  {
    printf("request is not accepted");
    return(0);
  }
  for(int i=0;i<m;i++)
  {
    available[i]=available[i]-r[i];
    allocation[p][i]=allocation[p][i]+r[i];
    need[p][i]=need[p][i]-r[i];
  }
  for(int t=0;t<n;t++)
  {
    int flag=0;
    for(int i=0;i<n;i++)
    {
      count=0;
      for(int j=0;j<m;j++)
      {
        //printf("%d",j);
        if(need[i][j]<=available[j] && need[i][j]!=-1)
        {
          count+=1;
          //printf("count==%d",count);
        }
        //printf("it is of process===%d\n",i);
        //printf("count==%d\n",count);
      }
      //printf("\n");
      if(count==m)
      {
        counti+=1;
        //printf("counti==%d\n",counti );
        for(int k=0;k<n;k++)
        {
          available[k]=available[k]+allocation[i][k];
          need[i][k]=-1;
        }
        order[g]=i;
        g+=1;
      }
    }
    if(counti==n)
    {
      printf("\nit is in safe state\n");
      flag=1;
      abort=1;
      printf("\nThe order is \n");
      for(int e=0;e<n;e++)
      {
        printf("%d",order[e]);
      }
      
      break;
    }
    if(flag==0 && t==n-1)
    {
      printf("it is not in safe state\n" );
      abort=0;
    }
  }
  
}
void main()
{
 int max[20][20],allocation[20][20],available[20][20],need[20][20],n,m;
 printf("enter the number of instance");
 scanf("%d",&n);
 printf("enter the number of resources");
 scanf("%d",&m);
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<m;j++)
  {
   max[i][j]=rand()%10+1;
  }
 }
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<m;j++)
  {
   allocation[i][j]=rand()%10+1;
  }
 }
 
safety(max,allocation,n,m);
if(abort==1)
{
 request(max,allocation,n,m);
}
}
