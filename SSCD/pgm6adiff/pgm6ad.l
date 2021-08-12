%{
#include<stdio.h>
int c=0;
%}
%x MCOMMENT SCOMMENT
%%
. {fprintf(yyout,"%s",yytext);}
"/*" {BEGIN(MCOMMENT);}
.|\n {fprintf(yyout,"%s",yytext);}
<MCOMMENT>"*/" {BEGIN(0);c++;} 
<MCOMMENT>."|\n" ;   //self loop
<MCOMMENT><<EOF>> {printf("Error\n");return 1;} 
"*/" {printf("Error\n");return 1;}
"//" {BEGIN(SCOMMENT);}
<SCOMMENT>. ;//self loop
<SCOMMENT>"\n" {BEGIN(0);c++;}
%%
int main()
{
yyin=fopen("input2a.txt","r");
yyout=fopen("output2a.txt","w");
yylex();
printf("No of comments:%d\n",c);
return 0;
}
int yywrap()
{
return 1;
}
