#include <iostream>
#include <string.h>

using namespace std;

int priority(char x)
{
    int result;
    switch (x)
    {
        case '(':
        case ')': result = 0; break;
        case '+':
        case '-': result = 1; break;
        case '*':
        case '\':
        case '/': result = 2; break;
        default: result = 3;
    }
    return result;
}

int delete_parenthesis(int begin, string& str)
{
    //cout<<"-1:"<<str<<endl;
    int lowest_priority = 4;
    int i;
    for(i=begin+1; i<str.length(); ++i)
    {
        if(str[i] == '(') i = delete_parenthesis(i,str)-1;
        else if(str[i] == ')') break;
    }
    
    int end = i;
    
    for(int i=begin+1;i<end;++i)
    {
        if( priority(str[i]) < lowest_priority) lowest_priority = priority(str[i]);
    }
    
    
    int op_prior = lowest_priority;
    int op_p_prior=-1;
    int op_n_prior=-1;
    char op_p;
    char op_n;

    bool next=false;
    bool prev=false;
    
    if(begin-1 >= 0)
    {
        op_p = str[begin-1];
        op_p_prior = priority(op_p);
    }
    if(end+1 < str.length())
    {
        op_n = str[end+1];
        op_n_prior = priority(op_n);
    }
        
    if(end+1 < str.length() && op_prior >= op_n_prior) next = true;
    if(end+1 >= str.length()) next=true;
    if(begin-1 >= 0)
    {
        if(op_p =='/') prev = false;
        else
        {
            if(op_prior>op_p_prior) prev = true;
            if(op_prior==op_p_prior)
            {
                //cout<<"In that if"<<endl;
                if(op_p!='-') prev=true;
                else prev=false;
            }
        }
    }
    if(begin-1<0) prev=true;
    
    
    
    // cout<<" 0:"<<str<<endl;
    // cout<<"-----"<<endl;
    // cout<<"op_prior: "<<op_prior<<endl;
    // cout<<"op_p: "<<op_p<< " op_p_prior: "<<op_p_prior<<endl;
    // cout<<"op_n: "<<op_n<<" op_n_prior: "<<op_n_prior<<endl;
    // cout<<"-----"<<endl;
    
    
    if(begin+2==end)
    {   
        str.erase(end,1);
        str.erase(begin,1);
        return end-1;
    }
    
    //cout<<prev<<" "<<next<<endl;
    if(next==true && prev==true)
    {
        str.erase(end,1);
        str.erase(begin,1);
        //cout<<" 1:"<<str<<endl;
        return end-1;
    }
    
    //cout<<" 2:"<<str<<endl;
    return end+1;
}


int main()
{
    int n;
    string str;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>str;
        for(int j=0;j<str.length();++j)
        {
            if(str[j]=='(') j=delete_parenthesis(j,str);   
        }
        cout<<str<<endl;
    }
    
    /*string a="a-(e/f)";
    
    for(int i=0;i<a.length();++i)
    {
        if(a[i]=='(') i=delete_parenthesis(i,a);
    }
    cout<<a<<endl;*/
    
    
        
    return 0;
}
