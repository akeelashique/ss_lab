#include<stdio.h>
#include<string.h>
struct files
{
 char dir[10];
 char fname[100][20];
}str; 
void main()
{
 int n,c,d,i=0;
 char sname[10];
 printf("enter the name of the dir\n");
 scanf("%s",str.dir);
 while(d==0)
 {
 printf("\nChoose the process\n");
 printf("1.Create\n");
 printf("2.Delete\n");
 printf("3.Search\n");
 printf("4.Print\n");
 printf("5.Exit\n");
 scanf("%d",&c);
 switch(c)
 {
  case 1:printf("enter the name of the file");
         scanf("%s",str.fname[i]);
         i++;
         break;
  case 2:printf("enter the name of the file to be deleted");
         scanf("%s",sname);
         for(int j=0;j<i;j++)
         {
          if(strcmp(str.fname[j],sname)==0)
          {
           strcpy(str.fname[j],str.fname[i-1]);
           i--;
          }
         } 
         break; 
  case 3:printf("enter the name of the file to be found");
         scanf("%s",sname);
         for(int j=0;j<i;j++)
         {
          if(strcmp(str.fname[j],sname)==0)
          {
           printf("Found");
           break;
          }
          else
          {
           printf("Not found\n");
           break;
          }
         } 
  case 4:printf("%d\n",str.dir);
         for(int j=0;j<i;j++)
         {
          printf("%s\t",str.fname[j]);
         }
         break;
  case 5:d=1;
         break;
 }
}
}
       
   


