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

int delete_parentheses(int start, string& str)
{
    int i;
    for(i=start+1; i<str.length(); ++i)
    {
        if(str[i] == '(') i = delete_parentheses(i,str)-1;
        else if(str[i] == ')') break;
    }
    int end = i;
    
    int lowest_priority = 4;            // 4 is not accessible while calling priority()
    int counter=0;                      // counts the nestings of parentheses
    for(int i=start+1;i<end;++i)
    {
        if(str[i]=='(') counter++;
        else if(str[i]==')') counter--;
        else if( priority(str[i]) < lowest_priority && counter==0) lowest_priority = priority(str[i]);
    }
    
    int op_prior = lowest_priority;
    char op_p;
    char op_n;
    int op_p_prior=-1;                  //priority of the previous operator (befor the current parentheses)
    int op_n_prior=-1;                  //priority of the next operator (after the current parentheses)
    
    bool next=false;
    bool prev=false;
    
    if(start-1 >= 0)
    {
        op_p = str[start-1];
        op_p_prior = priority(op_p);
        
        if(op_p =='/') prev = false;
        else
        {
            if(op_prior > op_p_prior) prev=true;
            if(op_prior == op_p_prior)
            {
                //cout<<"In that if"<<endl;
                if(op_p != '-') prev=true;
                else prev=false;
            }
        }
    }
    if(end+1 < str.length())
    {
        op_n = str[end+1];
        op_n_prior = priority(op_n);
        if(op_prior >= op_n_prior) next = true;
    }
    
    if(end+1 >= str.length()) next=true;
    if(start-1 < 0) prev=true;
    
    if(start+2==end)
    {   
        str.erase(end,1);
        str.erase(start,1);
        return end-1;
    }
    
    if(next==true && prev==true)
    {
        str.erase(end,1);
        str.erase(start,1);
        return end-1;
    }
    
    return end+1;
}


int main()
{
    int n;
    string str;
    cin>>n;
    
    for(int i=0; i<n; ++i)
    {
        cin>>str;
        for(int j=0; j<str.length(); ++j)
        {
            if(str[j]=='(') j=delete_parentheses(j,str);   
        }
        cout<<str<<endl;
    }
        
    return 0;
}
