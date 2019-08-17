#include <iostream>
#include <string.h>

using namespace std;

void pattern(int lines, int columns)
{
	for(int i=0; i<3*lines+1; ++i)
	{
		for(int j=0; j<3*columns+1; ++j)
		{
			if( (i%3==0)||(j%3==0) ) cout<<"*";
			else cout<<".";
		}
		cout<<endl;
	}
}

void parse_input(int n)
{
	int lines, columns;
	for(int i=0;i<n;++i)
	{
	    	cin>>lines;
	    	cin>>columns;
		pattern(lines,columns);
		cout<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	parse_input(n);
	
	return 0;
}
