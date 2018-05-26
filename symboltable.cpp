#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<ctype.h>
using namespace std;
int check(char a)
{
	int flag=0;
	char operators[]="#<>/*-+=%^;(){}";
	if(a==' ')
		return 0;
	else
	{
		for(int i=0;operators[i]!='\0';i++)
		{
			if(a==operators[i])
				flag=1;
		}
		if(flag==1)
			return 0;
	}
	return 1;
}
int checktoken(string str)
{
	char keywords[33][10] ={"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while","main"};
	for(int i=0;i<33;i++)
	{
		if(strcmp(str.c_str(),keywords[i])==0)
			return 0;
	}
	return 1;
}
void checkSymbol(char str[10], char var[20],char scope[10])
{
	char datatypes[5][15]={"int","float","long","short","char"};
	int size[5]={2,4,8,2,1};
	int i;
	for(i=0;i<5;i++)
	{
		if(strcmp(str,datatypes[i])==0)
			cout<<"\n"<<var<<"\t"<<str<<"\t"<<scope<<"\t"<<size[i];
	}
}
int main()
{

	int op=0,token=0,var=0,con=0,pun=0,len=0;
	int i=0,j=0,k=0;
	string str;
	char lex[20][30];
	char scope[10];
	strcpy(scope,"global");
	ifstream fin ("sample.txt");
	cout<<"Symbol"<<"\t"<<"Type"<<"\t"<<"Scope"<<"\t"<<"Width";
	while(getline(fin,str))
	{
		while(str[i]!='\0')
		{
			if(check(str[i])==1)
			{
			lex[j][k]=str[i];
			i++;
			k++;
			}
			else
			{
				lex[j][k]='\0';
				j++;
				if(str[i]!=' ')
				{
				lex[j][0]=str[i];
				lex[j][1]='\0';
				j++;
				}
				k=0;
				i++;
			}
		}
		for(i=0;i<j;i++)
		{
		//cout<<"\n"<<lex[i];
			if(strcmp(lex[i],"main")==0)
			strcpy(scope,"local");
			checkSymbol(lex[i],lex[i+1],scope);
			if(checktoken(lex[i])==0)
				token++;
			else if(isalpha(lex[i][0]))
				var++;
			else if(isdigit(lex[i][0]))
				con++;
			else if(lex[i][0]==';')
				pun++;
			else if(lex[i][0]!=' '&&lex[i][0]!='\0')
				op++;
		}
		i=j=k=0;
	}	
	cout<<"\n\nOperators="<<op;
	cout<<"\nPunctuators="<<pun;
	cout<<"\nTokens="<<token;
	cout<<"\nVariables="<<var;
	cout<<"\nConstants="<<con;
	cout<<"\n";
	return 0;
}
