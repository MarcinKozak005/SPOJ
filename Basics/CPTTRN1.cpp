#include <iostream>
#include <string.h>

using namespace std;

void pattern(int lines, int columns)
{
	for(int i=0; i<lines; ++i)
	{
		for(int j=0; j<columns; ++j)
		{
		    if( (j+i)%2 == 0) cout<<"*";
		    else cout<<".";
		}
		cout<<endl;
	}
}

void parse_input(int n)
{
	int lines, columns;
	for(int i=0; i<n ;++i)
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
