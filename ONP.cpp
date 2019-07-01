#include <iostream>
#include <string>
#include <stack>

using namespace std;

//get Operator's Priority
int getPriority(char c)
{
    int x;
    switch(c)
    {
        case '(': x=0;break;
        case '+':
        case '-':
        case ')': x=1;break;
        case '*':
        case '/':
        case '%': x=2;break;
        case '^': x=3;break;
    }
    return x;
}

void ONP(string input)
{
    stack<char> stos;
    string ops="(+-)*/%^";
    char curr;
    for(int i=0;i<input.length();++i)
    {
        curr=input.at(i);
        
        //If it's an operator
        if(ops.find(curr,0)!=-1)
        {
            //What to do depends on the curr;
            if(curr=='(') stos.push(curr);
            else if(curr==')')
            {
                while(stos.top()!='(')
                {
                    cout<<stos.top();
                    stos.pop();
                }
                stos.pop();
            }
            else if(stos.empty()) stos.push(curr);
            else if(getPriority(curr)>getPriority(stos.top())) stos.push(curr);
            else
            {
                cout<<stos.top();
                stos.pop();
                stos.push(curr);
            }
        }
        //Not an operator
        else cout<<curr;
    }
    
    //Empty stack
    while(!stos.empty())
    {
        cout<<stos.top();
        stos.pop();
    }
}

int main()
{
    int t;
    cin>>t;
    string input;
    for(int i=0;i<t;++i)
    {
        cin>>input;
        ONP(input);
        cout<<"\n";
    }
    

    return 0;
}
