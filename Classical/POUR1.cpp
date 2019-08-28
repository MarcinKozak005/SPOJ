#include <iostream>
#include <algorithm>    //for min() and max()

using namespace std;

int min_steps(int a,int b, int wanted)
{
    int low = min(a,b);
    int high = max(a,b);
    
    bool found1 = false;
    bool found2 = false;
    
    int current=0;
    int steps1=0;
    int steps2=0;
    
    if(wanted==high || wanted==low) return 1;
    
    //r -> rest in the big bucket.
    //First method: filling big bucket with small one until current==wanted or until we make a circle (r will be again 0 and steps1!=0)
    for(int r=0; r!=0||steps1==0;)
    {
        while(current<high)
        {
           if(wanted==current)
           {
               found1=true;
               break;
           }
           current+=low;
           steps1+=2;
        }
        if(found1) break;
        
        r=current-high;
        current=current-high;
        steps1+=2;
    }
    if(wanted>0 && wanted<low) steps1-=2;
    
    
    //Second method: pouring form the big bucket int the small one. Until we find or make a circle
    current=high;
    steps2=1;
    for(int r=high; r!=high||steps2==1;)
    {
        while(current>0)
        {
            if(wanted==current)
            {
                found2=true;
                break;
            }
            current-=low;
            steps2+=2;
        }
        if(found2) break;
        
        r=current+high;
        current+=high;
        steps2+=2;
    }
    if(steps2!=1) steps2--;

    //Final results
    if(found1&&found2) return min(steps1,steps2);
    else return -1;
}


void parse_input(int n)
{
    int a,b,wanted;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        cin>>b;
        cin>>wanted;
        cout<<min_steps(a,b,wanted)<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    parse_input(n);
        
    return 0;
}
