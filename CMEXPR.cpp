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
        case '/': result = 2; break;
        default: result = 3;
    }
    return result;
}

int delete_parenthesis(int begin, string& str)
{
    int lowest_priority = 4;
    int i;
    for(i=begin; i<str.length(); ++i)
    {
        if(str[i] == '(') i = delete_parenthesis(i+1,str)-1;
        else if(str[i] == ')') break;
        else //*!*
        {
            if( priority(str[i]) < lowest_priority) lowest_priority = priority(str[i]);
        }
    }
    
    int op_prior = lowest_priority;
    int op_p_prior;
    int op_n_prior;
    char op_p;
    char op_n;
    int end = i;
    bool next,prev;
    
    if(begin-2 >= 0)
    {
        op_p = str[begin-2];
        op_p_prior = priority(op_p);
    }
    if(end+1 < str.length())
    {
        op_n = str[end+1];
        op_n_prior = priority(op_n);
    }
    
    
    /*if(op_prior >= op_p_prior && op_prior >= op_n_prior && (op_p != '/' && op_p != '-') )
    {
        str.erase(end,1);
        str.erase(begin-1,1);
        return end-1;
    }
    */
    if(end+1 < str.length() && op_prior >= op_n_prior) next = true;
    if(end+1 >= str.length()) next=true;
    if(begin-2 >= 0)
    {
        if(op_p =='/') prev = false;
        else
        {
            if(op_prior>op_p_prior) prev = true;
            if(op_prior=op_p_prior)
            {
                if(op_p!='-') prev=true;
                else prev=false;
            }
        }
    }
    if(begin-2<0) prev=true;
    
    if(next==true && prev==true)
    {
        str.erase(end,1);
        str.erase(begin-1,1);
        return end-1;
    }
    
    
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
    
    return 0;
}
