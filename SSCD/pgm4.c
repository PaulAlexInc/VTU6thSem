/*Program 4:
Design, develop and implement YACC/C program to demonstrate Shift Reduce Parsing
technique for the grammar rules: E-> E+T | T, T -> T*F | F, F-> (E) | id and parse the sentence: id
+ id * id.
Code*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ip_sym[15],stack[15];
int ip_p=0,st_p=0,len,i;
char temp[2];
char act[15];// stores shift and reduce
void check(); //does the reduce operation
void main()
{
printf("\n\t\tShift Reduce Parser\n\n");
printf("The Grammar is:\n");
printf("\nE -> E+T | T\nT -> T*F | F\nF -> (E) | id\n\n");
printf("Enter the input string:");
scanf("%s",ip_sym);
printf("\n\t STACK IMPLEMENTATION TABLE\n");
printf("\nStack\t\tInput Symbol\t\tAction\n");
printf("------------------------------------------------------------\n");
printf("$\t\t%s$\t\t------",ip_sym);
strcpy(act,"shift");
len=strlen(ip_sym);
for(i=0;i<=len-1;i++)
{
if(ip_sym[ip_p]=='i' && ip_sym[ip_p+1]=='d')
{
stack[st_p]=ip_sym[ip_p];
st_p++;
ip_sym[ip_p]=' ';
ip_p++;
stack[st_p]=ip_sym[ip_p];
stack[st_p+1]='\0';
ip_sym[ip_p]=' ';
ip_p++;
}
else
{
stack[st_p]=ip_sym[ip_p];
stack[st_p+1]='\0';
ip_sym[ip_p] = ' ';
ip_p++;
}
printf("\n$%s\t\t%s$\t\t%s",stack,ip_sym,act);
strcpy(act,"Shift ");
if(ip_sym[ip_p]=='(' || ip_sym[ip_p]=='*' || ip_sym[ip_p]=='+' ||
ip_sym[ip_p]==')')
{
temp[0]=ip_sym[ip_p];
temp[1]='\0';
}
else
{
temp[0]=ip_sym[ip_p];
temp[1]=ip_sym[ip_p+1];
temp[2]='\0';
}
strcat(act,temp);
check();
st_p++;
}
st_p++;
check();
}
void check()
{
int flag=0;
while(1)
{
if(stack[st_p]=='d' && stack[st_p-1]=='i')
{
stack[st_p-1]='F';
stack[st_p]='\0';
st_p--;
flag=1;
printf("\n$%s\t\t%s$\t\tReduce F -> id",stack,ip_sym);
}
if(stack[st_p]== ')' && stack[st_p-1]=='E' && stack[st_p-2]=='(')
{
stack[st_p-2]='F';
stack[st_p-1]='\0';
flag=1;
st_p=st_p-2;
printf("\n$%s\t\t%s$\t\tReduce F -> (E)",stack,ip_sym);
}
if(stack[st_p]=='F' && stack[st_p-1]=='*' && stack[st_p-2]=='T')
{
stack[st_p-1]='\0';
flag=1;
st_p=st_p-2;
printf("\n$%s\t\t%s$\t\tReduce T -> T*F",stack,ip_sym);
}
else
{
if(stack[st_p]=='F')
{
stack[st_p]='T';
flag=1;
printf("\n$%s\t\t%s$\t\tReduce T -> F",stack,ip_sym);
}
}
if(stack[st_p]=='T' && stack[st_p-1]=='+' && stack[st_p-2]=='E' &&
ip_sym[ip_p]!='*')
{
stack[st_p-1]='\0';
flag=1;
st_p=st_p-2;
printf("\n$%s\t\t%s$\t\tReduce E -> E+T",stack,ip_sym);
}
else
{
if((stack[st_p]=='T' && ip_sym[ip_p]=='+')||
(stack[0]=='T' && ip_sym[ip_p]=='\0')||
(stack[st_p]=='T' && ip_sym[ip_p]==')'))
{
stack[st_p]='E';
flag=1;
printf("\n$%s\t\t%s$\t\tReduce E -> T",stack,ip_sym);
}
}
if((stack[st_p]=='T' && ip_sym[ip_p]=='*')||
(stack[st_p]=='E'&&ip_sym[ip_p]==')')||
(stack[st_p]=='E'&&ip_sym[ip_p]=='+')||
(stack[st_p]=='+'&&ip_sym[ip_p]=='i'&&ip_sym[ip_p+1]=='d')||
(stack[st_p]=='('&&ip_sym[ip_p]=='i'&&ip_sym[ip_p+1]=='d')||
(stack[st_p]=='('&&ip_sym[ip_p]=='(')||
(stack[st_p]=='*'&&ip_sym[ip_p]=='i'&&ip_sym[ip_p+1]=='d')||
(stack[st_p]=='*'&&ip_sym[ip_p]=='(')||
(stack[st_p]=='+'&&ip_sym[ip_p]=='('))
{
flag=2;
}
if(!strcmp(stack,"E")&&ip_sym[ip_p]=='\0')
{
printf("\n$%s\t\t%s$\t\tAccept\n",stack,ip_sym);
printf("------------------------------------------------------------\n");
exit(0);
}
if(flag==0)
{
printf("\n%s\t\t%s\t\tReject\n",stack,ip_sym);
printf("------------------------------------------------------------\n");
exit(0);
}
if(flag==2)
return;
flag=0;
}
}

