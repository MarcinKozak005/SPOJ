#include <iostream>
#include <math.h>   //for floor()

using namespace std;

// I'm using the concept of trailing zeros

int how_many_zeros(int number)
{
    int power=5;
    int result=0;
    
    while(power<=number)
    {
        result+=floor(number/power);
        power*=5;
    }
    return result;
}

void parse_input(int n)
{
    int number;

    for(int i=0;i<n;++i)
    {
        cin>>number;
        cout<<how_many_zeros(number)<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    parse_input(n);

    return 0;
}
