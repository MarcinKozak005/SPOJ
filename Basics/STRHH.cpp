#include <iostream>
#include <string.h>

using namespace std;


void half_of_half(string & x)
{
	for(int i=0;i<x.length()/2;++i)
	{
		if(i%2 == 0) cout<<x[i];
	}
	cout<<endl;
}

void parse_input(int n)
{
	string sequence;
	for(int i=0;i<n;++i)
	{
	  cin>>sequence;
		half_of_half(sequence);
	}
}

int main()
{
	int n;
	cin>>n;
	parse_input(n);
	
	return 0;
}
