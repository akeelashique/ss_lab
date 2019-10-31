#include<stdio.h>

#include<stdlib.h>

#include<string.h>

void main() {
  FILE * f1, * f2, * f3, * f4;
  int lc, sa, l, op1, o, len, i = 0, j = 0, x = 0;
  char m1[20], la[20], op[20], otp[20], str[200];
  f1 = fopen("input.txt", "r");
  f2 = fopen("temp.txt", "w");
  f3 = fopen("symtab.txt", "w");
  //fscanf(,"%s %s %d",la,m1,&op1);
  //----------------------------------split-----------------------
  fgets(str, 100, f1);
  while (str[i] != ' ') {
    la[i] = str[i];
    i++;
  }
  la[i] = '\0';
  i++;
  j = 0;
  while (str[i] != ' ') {
    m1[j] = str[i];
    i++;
    j++;
  }
  m1[j] = '\0';
  i++;
  x = 0;
  while (str[i] != '\0') {
    op[x] = str[i];
    i++;
    x++;
  }
  op[x] = '\0';
  //----------------------------------split-----------------------
  if (strcmp(m1, "START") == 0) {
    lc = atoi(op);
    printf("\t%s\t%s\t%s\n", la, m1, op);
    fprintf(f2, "\n%05x\t%s\t%s\t%s\n", lc, la, m1, op);
  } else {
    lc = 0;
  }
  //fscanf(f1,"%s %s %s",la,m1,op);
  //printf("%s  %s",la,m1);
  //----------------------------------split-----------------------
  i = 0;
  fgets(str, 100, f1);
  while (str[i] != ' ') {
    la[i] = str[i];
    i++;
  }
  la[i] = '\0';
  i++;
  j = 0;
  while (str[i] != ' ') {
    m1[j] = str[i];
    i++;
    j++;
  }
  m1[j] = '\0';
  i++;
  x = 0;
  while (str[i] != '\0') {
    op[x] = str[i];
    i++;
    x++;
  }
  op[x] = '\0';
  //----------------------------------split----------------------- 
  while (!feof(f1)) {
    //fscanf(f1,"%s",op);
    //printf("%s",op);
    printf("\n%05x\t%s\t%s\t%s\n", lc, la, m1, op);
    fprintf(f2, "\n%05x\t%s\t%s\t%s\n", lc, la, m1, op);
    if (strcmp(la, " ") != 0 && strcmp(la, "\0") != 0) {
      fprintf(f3, "\n%05x\t%s\n", lc, la);
    }
    if (strcmp(m1, "WORD") == 0) {
      lc = lc + 3;
    } else if (strcmp(m1, "RESW") == 0) {
      op1 = atoi(op);
      lc = lc + (3 * op1);
    } else if (strcmp(m1, "BYTE") == 0) {
      if (op[0] == 'x') {
        len = strlen(op) - 3;
        lc = lc + (len / 2);
      }
      //lc=lc+1;
      //printf("loop==========1");
      else {
        len = strlen(op) - 3;
        lc = lc + len;
      }
    } else if (strcmp(m1, "RESB") == 0) {
      op1 = atoi(op);
      lc = lc + op1;
    } else {
      lc = lc + 3;
      //break;
    }
    //fscanf(f1,"%s%s%s",la,m1,op);
    //----------------------------------split-----------------------
    i = 0;
    fgets(str, 100, f1);
    while (str[i] != ' ') {
      la[i] = str[i];
      i++;
    }
    la[i] = '\0';

    i++;
    j = 0;
    while (str[i] != ' ') {
      m1[j] = str[i];
      i++;
      j++;
    }
    m1[j] = '\0';
    i++;
    x = 0;
    while (str[i] != '\0') {
      op[x] = str[i];
      i++;
      x++;
    }
    op[x] = '\0';
    //----------------------------------split-----------------------
    //printf("\t%s\t%s\t%s\n",la,m1,op);
  }
  if (strcmp(m1, "END") == 0) {
    printf("Done");
    //break;
  }
  fclose(f1);
  fclose(f3);
}
