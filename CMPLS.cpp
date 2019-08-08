// Example program
#include <iostream>
#include <vector>

using namespace std;

void show(vector<int> & vec)
{
    for(int i=0;i<vec.size();++i)
    {
        cout<<vec[i]<<endl;   
    }
}

void show2(vector<vector<int>> & holder)
{
    
    int min=holder[holder.size()-1].size();
    
    //cout<<min<<endl;
    for(int i=0;i<min;++i)
    {
        for(int j=0;j<holder.size();++j)
        {
            cout<<holder[j][i]<<" ";
        }
        cout<<endl;
    }
    for(int i=min;i<holder[0].size();++i)
    {
        for(int j=0;j<holder.size()-i+min-1;++j)
        {
            cout<<holder[j][i]<<" ";   
        }
        cout<<endl;
    }
    
}


void fill(vector<vector<int>> & holder)
{
    vector<int> helper;
    bool identical=true;
    int current;
    
    for(int i=0;i<holder[0].size();++i)
    {
        for(int j=0;j<holder[i].size()-1;++j)
        {
            current=holder[i][j+1]-holder[i][j];
            helper.push_back(current);
            if(current!=helper[0]) identical=false;
        }
        holder.push_back(helper);
        if(identical) break; cout<<"break"<<endl;
        identical=true;
        helper.clear();
    }
}

void add_diagonal(vector<vector<int>> & holder)
{
    // show(holder[0]);
    // show(holder[1]);
    // show(holder[2]);
    
    int x;
    for(int i=holder.size()-1;i>=0;--i)
    {
        if(i!=holder.size()-1) x=holder[i+1][holder[i].size()-1];
        else x=holder[holder.size()-1][0];
        holder[i].push_back(holder[i][holder[i].size()-1]+x);
        break;
    }
}


int main()
{
    vector<vector<int>> holder;
    
    vector<int> exp={1,4,9,16,25,36};
    holder.push_back(exp);
    fill(holder);
    show2(holder);
    add_diagonal(holder);
    show2(holder);
    //cout<<holder.size()<<endl;
    
    return 0;
}
