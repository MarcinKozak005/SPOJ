#include <iostream>

using namespace std;

int reverseInt(int input)
{
    int result=0;
    int rest;
    
    while(input!=0)
    {
        rest=input%10;
        input=(input-rest)/10;
        result=(10*result)+rest;
    }
    
    return result;
}

int addReversed(int a, int b)
{
    int normalA = reverseInt(a);
    int normalB = reverseInt(b);
    
    return reverseInt(normalA+normalB);
}

void parseInput(int n)
{
    int a,b;
    
    for(int i=0; i<n; ++i)
    {
        cin>>a>>b;
        cout<<addReversed(a,b)<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    parseInput(n);
    
    return 0;
}
