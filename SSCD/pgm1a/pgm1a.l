%{
#include<stdio.h>
int opr=0,ids=0,br=0;
%}
%X OPR
%%
[a-zA-Z0-9]+ {BEGIN(OPR);printf("%s is an identifier\n",yytext);ids++;} 
[ \t\n]+
[(] {br++;} 
[^a-zA-Z0-9] {printf("Invalid Expression\n");exit(0);}
<OPR>[+\-*/]+ {BEGIN(0); printf("%s is an operator\n",yytext);opr++;}
<OPR>[ \t\n]+
<OPR>[)] {br--;}
<OPR><<EOF>> {return 0;}
<OPR>. {printf("invalid expression\n");exit(0);}
%%
int main()
{
printf("Enter the expression:\n");
yylex();
printf("Number of Operators=%d\n",opr);
printf("Number of Identifiers=%d\n",ids);
if(br!=0)
printf("Invalid expression\n");
else
printf("Valid expression\n");
}
int yywrap()
{
	return 1;
}
