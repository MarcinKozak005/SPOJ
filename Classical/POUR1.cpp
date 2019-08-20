// Example program
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int fillL_LtoH(int high, int low)
{
    return 2*(high-(high%low))/low +2;
}

int HtoX_emptyX(int high, int low)
{
    return 2*(high-(high%low))/low;
}

int min_steps(int a,int b, int c)
{
    // int low = min(a,b);
    // int high = max(a,b);
    
    // int r= high-low;
    // int z= -(high%low)+low;
    
    // vector<int> steps;
    
    // //if( c ==(high-z)) steps.push_back(fillL_LtoH(high,low)+3);
    // if(c%low == high%low) steps.push_back(2*(high-c)/low);
    // if(c%low==0) steps.push_back(2*c/low);
    // if(c==)
    
    // //if( c ==(low+z)) steps.push_back(fillL_LtoH(high,low)+4);
    // //if( c == (low-z)) steps.push_back(HtoX_emptyX(high,low)+1);
    // //if(c == (low-r)) steps.push_back(fillL_LtoH(high,low));
    
    // //if(c == r) steps.push_back(2);
    // //if(c == z) steps.push_back(fillL_LtoH(high,low));
    
    // if(steps.empty()) return -1;
    // return *min_element(steps.begin(),steps.end());
    
    bool found=false;
    int begin=0;
    
    
    
    
    
    
}


void parse_input(int n)
{
    int a,b,c;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        cin>>b;
        cin>>c;
        cout<<min_steps(a,b,c)<<endl;
    }
}




int main()
{
    int n;
    cin>>n;
    parse_input(n);
        
    return 0;
}
