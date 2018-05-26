%{
	#include<stdio.h>
%}
%%
[0-9]*[1/3/5/7]+ printf("\nIt is odd");
.* printf("\nIt is even");
%%
int main()
{
	yylex();
	return 0;
}
int yywrap()
{
	return 0;
}
