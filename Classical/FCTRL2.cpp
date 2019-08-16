#include <iostream>
#include <string.h>
#include <algorithm>    // for reverse

using namespace std;


void add(string &fst, string &snd, string & res);

void add_to_first(string &fst, string &snd)
{
    string tmp;
    add(fst,snd,tmp);
    fst=tmp;
}

// function multiplying "normally" is to big for the SPOJ's Source limit
void mul_with_addition(string & fst, string & snd)
{
    string one="1";
    string tmp=fst;
    for(string i="1";i!=snd;add_to_first(i,one))
    {
        add_to_first(fst,tmp);
    }
}

void str_reverse(string& str)
{
    reverse(str.begin(),str.end());
}

string factorial(string & n)
{
    string result="1";
    string one="1";
    
    add_to_first(n,one);
    for(string i="1";i!=n;add_to_first(i,one))
    {
        mul_with_addition(result,i);
    }
    
    return result;
}

void parse_input(int n)
{
    string x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        cout<<factorial(x)<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    parse_input(n);

    return 0;
}

//taken from my solution to SPOJ ARITH problem
void add(string &fst, string &snd, string & res)
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
