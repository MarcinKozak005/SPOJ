// Example program
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double factorial(int n)
{
    double result=1;
    for(int i=1;i<=n;++i)
    {
        result*=i;
    }
    
    return result;
}

void parse_input(int n)
{
    double x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        cout<<factorial(x)<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    parse_input(n);
    for(int i=0;i<101;++i)
    {
        cout<<fixed<<setprecision(0)<<i<<"! = "<<factorial(i)<<endl;
    }
    //cout<<(1124000727777607680000*23)<<endl;
    return 0;
}
