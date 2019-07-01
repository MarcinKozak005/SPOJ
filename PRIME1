#include <iostream>
#include <math.h>

using namespace std;


bool isPrime(int x)
{
    if(x==1) return false;
    for(int i=2;i<=sqrt(x);++i)
    {
        if(x%i==0) return false;
    }
    return true;
}


void getPrime(int start, int end)
{
    if(start<=end)
    {
        for(int i=start;i<end+1;++i)
        {
            if(isPrime(i)) cout<<i<<endl;
        }
    }
}




int main()
{
    int t;
    int start,end;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>start;
        cin>>end;
        getPrime(start,end);
        cout<<"\n";
    }
   return 0;
}
