#include<stdio.h>
#include<conio.h>

void main()
{
FILE *f;
FILE *fo;
char input[50];
int ch,length,i,value[50];
clrscr();
printf("Enter choice ");
scanf("%d",&ch);
switch(ch)
{
case 1:
f=fopen("cin.txt","r");
if(f==NULL)
  printf("File not present");

while(fgets(input,50,f)!=NULL)
  printf("%s",input);

length=strlen(input);

for(i=0;i<length;i++)
{
  value[i]=input[i]+5;
  if(value[i]>90 || value[i]<65)
    value[i]=65+value[i]-90;
//  printf("\n%d",value[i]);
}
fo=fopen("cout.txt","w");
//printf("\nThe enciphered text is: ");
for(i=0;i<length;i++)
  fprintf(fo,"%c",value[i]);

fclose(f);
fclose(fo);
break;

case 2:
f=fopen("cout.txt","r");
if(f==NULL)
  printf("File not present");

while(fgets(input,50,f)!=NULL)
  printf("%s",input);

length=strlen(input);

for(i=0;i<length;i++)
{
  value[i]=input[i]-5;
  if(value[i]>90 || value[i]<65)
    value[i]=90+value[i]-65;
//  printf("\n%d",value[i]);
}
fo=fopen("cin.txt","w");
//printf("\nThe enciphered text is: ");
for(i=0;i<length;i++)
  fprintf(fo,"%c",value[i]);

fclose(f);
fclose(fo);
break;

}
getch();
}