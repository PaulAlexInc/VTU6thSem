%{
	#include<stdio.h>
	#include<stdlib.h>
	int id=0, key=0, op=0;
%}

%token ID KEY OP

%%
input:ID input {++id;}
	|KEY input {++key;}
	|OP input {++op;}
	|ID {++id;}
	|KEY {++key;}
	|OP {++op;}
	;
%%
extern FILE *yyin;
void main()
{
	yyin =fopen("xyz.c","r");
	yyparse();
	printf("Keywords=%d\n",key);
	printf("Identifiers=%d\n",key);
	printf("Operators=%d\n",op);
}
yyerror()
{
	printf("Error");
	exit(0);
}
int yywrap()
{
	return 1;
}
