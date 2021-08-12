%{
#include<stdio.h>
int id=0,op=0,top=-1;
char stack[10];
%}
%%
[+]	{printf("%s is an op\n",yytext);op++;}
[-]	{printf("%s is an op\n",yytext);op++;}
[*]	{printf("%s is an op\n",yytext);op++;}
[/]	{printf("%s is an op\n",yytext);op++;}
[0-9]+	{printf("%s is an id\n",yytext);id++;}
[(]	{stack[++top]='(';}
[)]	{if(stack[top]=='(') 
		top--;
	else{printf("Invalid expression\n");
		exit(0);}}
%%
int main()
{
	
	printf("Enter the expression\n");
	yylex();
	
	if(top!=-1||op>=id||id==1)
	{
		printf("It is not a valid expression");
	}
	else
	{
		printf("It is a valid expression\n");
		printf("Number of operators=%d\n",op);
		printf("Number of identifiers=%d\n",id);
	}
	return 0;
}
int yywrap()
{
	return 1;
}

