#include <iostream>
#include <vector>

using namespace std;

void show(vector<vector<int>> & holder)
{
    int size = holder.size();
    int min = holder[size-1].size();
    
    //show the rectangular block
    for(int i=0; i<min; ++i)
    {
        for(int j=0;j<size;++j)
        {
            cout<<holder[j][i]<<" ";
        }
        cout<<endl;
    }
    
    //show the triangular rest
    for(int i=min; i<holder[0].size(); ++i)
    {
        for(int j=0; j<size-i+min-1; ++j)
        {
            cout<<holder[j][i]<<" ";   
        }
        cout<<endl;
    }
}


void count_table(vector<vector<int>> & holder)
{
    vector<int> helper;
    bool identical=true;
    int difference;
    
    for(int i=0; i<holder[0].size(); ++i)
    {
        for(int j=0; j<holder[i].size()-1; ++j)
        {
            difference=holder[i][j+1]-holder[i][j];
            helper.push_back(difference);
            if(difference!=helper[0]) identical=false;
        }
        holder.push_back(helper);
        
        //we reached the "end" earlier
        if(identical) break;
        identical=true;
        
        helper.clear();
    }
}

void add_diagonal(vector<vector<int>> & holder)
{
    int size = holder.size();
    
    //adds the constant element to last vector
    holder[size-1].push_back( holder[size-1][0] );
    
    int size_of_i;
    for(int i=size-2;i>=0;--i)
    {
        size_of_i = holder[i].size();
        holder[i].push_back( holder[i][size_of_i-1] + holder[i+1][size_of_i-1] );
    }
}

void parse_input(int n)
{
    int in,out;
    int tmp;
    
    
    for(int i=0; i<n; ++i)
    {
        cin>>in>>out;
        
        if(in==1)
        {
            cin>>tmp;
            for(int j=0;j<out;++j)  cout<<tmp<<" ";   
            cout<<endl;
        }
        else
        {
            vector<vector<int>> holder;
            vector<int> input_sequence;
            
            for(int j=0;j<in;++j)
            {
                cin>>tmp;
                input_sequence.push_back(tmp);
            }
            
            holder.push_back(input_sequence);
            count_table(holder);
            
            for(int k=0;k<out;++k)
            {
                add_diagonal(holder);
            }
            
            //printing result in desired form
            for(int l=in;l<in+out;++l)
            {
                cout<<holder[0][l]<<" ";
            }
            cout<<endl;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    parse_input(n);
    
    return 0;
}
