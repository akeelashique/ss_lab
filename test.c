#include <stdio.h>
#include <stdlib.h>


int main () {
   char la[10], m1[10];
   int op1;
   FILE * f1;

   f1 = fopen ("input.txt", "r");
   //fputs("We are in 2012", fp);
   
   rewind(f1);
   while(!feof(f1))
   {
   fscanf(f1,"%s %s %d",la,m1,&op1);
   printf("\t%s\t%s\t%d\n",la,m1,op1);
   
   }
   fclose(f1);
   
   return(0);
}
