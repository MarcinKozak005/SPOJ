#include <iostream>
#include <cstdio>

using namespace std;

void give_charity(int* tab, int l, int r)
{
    //mapping form <1,N> to <0,N-1>
    l--;
    r--;
    for(int i=0; i<=r-l; ++i) ( *(tab+l+i) )++;   
}

int find_biggest(int* tab, int size)
{
    int max = -1;
    for(int i=0; i<size; ++i)
    {
        if( *(tab+i) > max ) max = *(tab+i);
    }
    
    return max;
}

void show_the_richest(int *tab, int max, int size)
{
    for(int i=0; i<size; ++i)
    {
        if( *(tab+i) == max )
        {
            //reverse mapping
            cout<<i+1;
            if(i != size-1) cout<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int beggars;
    int pedestrians;
    int a,b;
    
    cin>>beggars;
    cin>>pedestrians;
    int* tab= new int[beggars];
    
    for(int i=0; i<pedestrians; ++i)
    {
        cin>>a>>b;
        give_charity(tab,a,b);
    }

    int big = find_biggest(tab,beggars);
    cout<<big<<endl;
    show_the_richest(tab,big,beggars);

    free(tab);
    return 0;
}
