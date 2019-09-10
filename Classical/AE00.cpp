#include <iostream>
#include <math.h>

using namespace std;

void howManyRectangles(int n)
{
    int result=0;
    for(int i=1;i<=sqrt(n);++i)
    {
        for(int j=i;j<=n;++j)
        {
            if(i*j<=n) result++;
        }
    }
    cout<<result;
}

int main()
{
    int n;
    cin>>n;
    howManyRectangles(n);
    
    return 0;
}
