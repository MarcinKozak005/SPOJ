#include <iostream>
#include <string.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;



//below
void add(string &fst, string &snd, string & res);
void add1(string &fst, string &snd)
{
    string tmp;
    add(fst,snd,tmp);
    fst=tmp;
}
void mul(string &fst, string &snd, string &res, vector<string> & str_vec);
void mul1(string &fst, string &snd)
{
    string tmp;
    vector<string> str_vec;
    mul(fst,snd,tmp,str_vec);
    fst=tmp;
}

void str_reverse(string& str)
{
    reverse(str.begin(),str.end());
}

string factorial(string & n)
{
    string result="1";
    string one="1";
    add1(n,one);
    for(string i="1";i!=n;add1(i,one))
    {
        mul1(result,i);
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

void mul(string &fst, string &snd, string &res, vector<string> & str_vec)
{
        res.erase(0);
        int z1,z2; // places for numbers being multiplied
        int overflow = 0;
        int product;
        int r_mod;
        int pos1=fst.length()-1;
        int pos2= snd.length()-1;
        
        
        for(;pos2>=0;pos2--)
        {
           overflow=0;
           if(snd[pos2]=='0')
           {str_vec.push_back("0");continue;}
           
           res.erase(0);
           for(;pos1>=0;pos1--)
           {
               z1 = fst[pos1] -48;
               z2 = snd[pos2] -48;
               product = (z1*z2) + overflow;
               r_mod = product%10;
               overflow = (product-r_mod)/10;
               res.push_back(r_mod+48);
           }
           //checks if the last multiplication has left an overflow
           if(overflow!=0) res.push_back(overflow+48);
           pos1 = fst.length()-1;
           str_reverse(res);
           str_vec.push_back(res);
        }
       
        //Adding zeros to numbers -> we need it for adding sub results
        for(int i=0;i<str_vec.size();i++)
        {
           string num = str_vec[i];
           for(int j=0;j<i;j++)
           {
                num +="0";
           }
           str_vec[i] = num;
        }
       
        //Summing sub results
        string helper;
        res=str_vec[0];
        for(int i=1;i<str_vec.size();i++)
        {
           add(res,str_vec[i],helper);
           res=helper;
           helper.erase(0);
        }
       
        //Deleting zeros to acquire true partial results
        for(int i=1;i<str_vec.size();i++)
        {
           str_vec[i].erase(str_vec[i].length()-i);
        }
       
}
