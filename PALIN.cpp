#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool half=false;

bool onlyNines(string& str, int len)
{
    int midd=ceil((double)len/2);
    for(int i=0;i<len;++i)
    {
        if(str.at(i)!='9') return false;
        if(i==midd-1) half=true; 
    }
    return true;
}

string caseNines(int len)
{
    string res="1";
    for(int i=0;i<len-1;++i) res+="0";
    res+="1";
    return res;
}


void addOne(string& str, int pos,int len)
{
    char x;
    for(int i=pos;i>-1;--i)
    {
        x=str.at(i);
        if(x=='0') {str[i]='1'; break;}
        else if(x=='1') {str[i]='2'; break;}
        else if(x=='2') {str[i]='3';break;}
        else if(x=='3') {str[i]='4';break;}
        else if(x=='4') {str[i]='5';break;}
        else if(x=='5') {str[i]='6';break;}
        else if(x=='6') {str[i]='7';break;}
        else if(x=='7') {str[i]='8';break;}
        else if(x=='8') {str[i]='9';break;}
        else if(x=='9') str[i]='0';
    }
}


void copy(string &str,int pos,int len)
{
    for(int i=pos;i>-1;--i)
    {
        str[len-1-i]=str[i];
    }
}

void nearestPalindrome(string &str)
{
    int len=str.length();
    int midd=ceil((double)len/2);
    bool action=false;
    
    if(onlyNines(str,len))  cout<<caseNines(len);
    else if(half==true)
    {
        copy(str,midd-1,len);
        cout<<str;
    }
    else
    {
        
        int x=midd-1;
        for(int i=midd-1;i>-1;--i)
        {
            if(str[i]>str[len-1-i])
            {
                copy(str,i,len);
                cout<<str;
                action=true;
                break;
            }
            else if(str[i]<str[len-1-i])
            {
                addOne(str,x,len);
                copy(str,x,len);//!
                cout<<str;
                action=true;
                break;
            }
        }
        if(action==false)
        {
            addOne(str,x,len);
            copy(str,x,len);
            cout<<str;
        }
    }
}


int main()
{
    int t;
    string a;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>a;
        nearestPalindrome(a);
        half=false;
        cout<<"\n";
    }
    
    
    
    
    return 0;
}
