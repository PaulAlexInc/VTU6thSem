%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'

%%
S:E {printf("result: %d\n",$1);return 0;}
E: E '+' E {$$=$1+$3;}
|E '-' E {$$=$1-$3;}
|E '*' E {$$=$1*$3;}
|E '/' E {if($3==0)
		{printf("error:division by zero\n");
		return 0;
		}
	else
		$$=$1/$3;}
|'('E')' {$$=$2;}
|NUM {$$=$1;}
%%

int main()
{
	printf("Enter the expression: ");
	yyparse();
	printf("valid expression\n");
	return 0;
}

yyerror()
{
	printf("invalid expression\n");
	exit(0);
}
