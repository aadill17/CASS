#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
FILE *f;
FILE *fo;
int length=0,key,seq,i,j,ch;
char input[50], array[50][50],trans[50][50];
float x;
int round;
char c;
clrscr();
printf("\nChoose an option:\n1. Encipher\n2. Decipher ");
scanf("%d",&ch);
switch(ch)
{
case 1:
//printf("%s",input);
printf("\nEnter the key: ");
scanf("%d", &key);
f=fopen("A.txt","r");
if(f==NULL)
  printf("File not found");
//  fgets(input,50,f);
//  puts(input);
while(fgets(input,50,f)!=NULL)
  printf("%s",input);


length=strlen(input);
//printf("%d\n",length);

x=(float)length/key;
round=ceil(x);
//printf("\n%f\n",x);
//printf("\n%d\n",round);
seq=0;
for(i=0;i<round;i++)
{
  for(j=0;j<key;j++)
  {
    array[i][j]=input[seq];
    seq++;
  }
}
printf("\nNormal matrix \n");
for(i=0;i<round;i++)
{
  for(j=0;j<key;j++)
    printf("%c ",array[i][j]);
  printf("\n");
}

for(i=0;i<key;i++)
  for(j=0;j<round;j++)
    trans[i][j]=array[j][i];
printf("\nTransposed matrix\n");
for(i=0;i<key;i++)
{
  for(j=0;j<round;j++)
    printf("%c ",trans[i][j]);
  printf("\n");
}

fo=fopen("out.txt","w");
if(fo==NULL)
  printf("File not found");

//fprintf(fo,"\nThe enciphered text is: ");

for(i=0;i<key;i++)
  for(j=0;j<round;j++)
    fprintf(fo,"%c",trans[i][j]);

fclose(f);
fclose(fo);
break;

case 2:
printf("\nEnter the key: ");
scanf("%d", &key);
f=fopen("out.txt","r");
if(f==NULL)
  printf("File not found");

while(fgets(input,50,f)!=NULL)
  printf("%s",input);


length=strlen(input);
//printf("%d\n",length);

x=(float)length/key;
round=ceil(x);
//printf("\n%f\n",x);
//printf("\n%d\n",round);
seq=0;
for(i=0;i<key;i++)
{
  for(j=0;j<round;j++)
  {
    array[i][j]=input[seq];
    seq++;
  }
}
printf("\nNormal matrix \n");
for(i=0;i<key;i++)
{
  for(j=0;j<round;j++)
    printf("%c ",array[i][j]);
  printf("\n");
}

for(i=0;i<round;i++)
  for(j=0;j<key;j++)
    trans[i][j]=array[j][i];
printf("\nTransposed matrix\n");
for(i=0;i<round;i++)
{
  for(j=0;j<key;j++)
    printf("%c ",trans[i][j]);
  printf("\n");
}

fo=fopen("cin.txt","w");
if(fo==NULL)
  printf("File not found");

//fprintf(fo,"\nThe enciphered text is: ");

for(i=0;i<round;i++)
  for(j=0;j<key;j++)
    fprintf(fo,"%c",trans[i][j]);

fclose(f);
fclose(fo);
break;

default:break;
}
getch();
}