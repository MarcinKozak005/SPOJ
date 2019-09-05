#include <iostream>
#include <string>
#include <algorithm>    // for reverse

// Most of the string-calculation functions are form my solution to ARITH.cpp

using namespace std;

void delete_leading_0s(string& str);
void str_reverse(string& str);
void add(string& fst, string& snd, string& res);
void sub(string& fst, string& snd, string& res);
void divideBy2(string& fst, string& result);

void addToFirst(string& fst, string& snd)
{
    string tmp;
    add(fst,snd,tmp);
    fst=tmp;
}

void subFromFirst(string& fst, string& snd)
{
    string tmp;
    sub(fst,snd,tmp);
    fst=tmp;
}

void divideFirstBy2(string& first)
{
    string tmp;
    divideBy2(first,tmp);
    first=tmp;
}

void processInput(string& total, string& diff)
{
    // total= 2x + diff
    subFromFirst(total,diff); 
    divideFirstBy2(total);
    string tmp=total;       // tmp=x
    addToFirst(total, diff);
    
    cout<<total<<endl;
    cout<<tmp<<endl;
}

void parseInput()
{
    string total, diff;
    
    for(int i=0; i<10; ++i)
    {
        cin>>total>>diff;
        processInput(total,diff);
    }
}

int main()
{
    parseInput();
    
    return 0;
}

// Functions' declarations below

void divideBy2(string& fst, string& result)
{
    result.erase(0);
    int rest;
    int next=0;
    for(int i=0; i<fst.size(); ++i)
    {
        rest= (fst[i]-48+next*10)%2;
        result.push_back( ((fst[i]-48-rest+next*10)/2)+48 );
        next=rest; //pod warunkiem ze zawsze parzyste
    }
    if(next!=0) result.push_back(next+48);
    delete_leading_0s(result);
}

void str_reverse(string& str)
{
    reverse(str.begin(),str.end());
}

void delete_leading_0s(string& str)
{
    while(str[0]=='0')
    {
        str.erase(0,1);
    }
}

void add(string& fst, string& snd, string& res)
{
    res.erase(0);
    char character;
    int overflow = 0;
    int pos1 = fst.length()-1;
    int pos2 = snd.length()-1;
    
    for(; pos1>=0 || pos2>=0 ; pos1--, pos2-- )
    {
        if (pos1>=0 && pos2>=0) {character = fst[pos1] + snd[pos2];}
        else if (pos1< 0) {character = '0'+ snd[pos2];}
        else {character = fst[pos1] + '0';}
           
        character +=overflow;
        character -=48; //convert char to int '0' -> 0
        
        if (character>57) {character-=10; overflow=1;} //manage overflow
        else overflow=0;
        
        res.push_back(character);
      }
      if (overflow!=0) res.push_back(overflow+48);
      str_reverse(res);
}

void sub(string& fst, string& snd, string& res)
{
    string fst_copy(fst);
    res.erase(0);
    int pos1=fst.length()-1;
    int pos2= snd.length()-1;
    for(;pos1>=0 || pos2>=0;pos1--,pos2--)
       {
           if(pos2>=0)
           {
               if(fst_copy[pos1]>=snd[pos2]) res.push_back(fst_copy[pos1] - snd[pos2] + 48);
               else if (fst_copy[pos1]<snd[pos2])
               {
                   for(int j=(pos1-1);j>=0;j--)
                   {
                       if(fst_copy[j]!='0')
                       {
                           fst_copy[j]--;
                           break;
                       }
                       else
                       {
                           fst_copy[j]='9';
                       }
                   }
                   fst_copy[pos1]+=10;
                   res.push_back(fst_copy[pos1] - snd[pos2] + 48);
               }
           }
           else
           {
               res.push_back(fst_copy[pos1]);
           }
       }
       str_reverse(res);
}
