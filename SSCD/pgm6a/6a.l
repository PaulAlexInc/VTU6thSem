%{
#include<stdio.h>
int c=0;
%}
%%
"//".* {c++;fprintf(yyout," ");}
"/*"[a-zA-z0-9" "\t\n]+"*/" {c++;fprintf(yyout," ");}
. {fprintf(yyout,"%s",yytext);}
%%
int main()
{
yyin=fopen("input2.txt","r");
yyout=fopen("output2.txt","w");
yylex();
printf("No of comments:%d \n",c);
return 0;
}
int yywrap()
{
return 1;
}

