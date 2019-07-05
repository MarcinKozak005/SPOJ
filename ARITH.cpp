#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

void print_spaces(int num)
{
    for(int i=0;i<num;i++) cout<<" ";    
}
void print_dash(int num)
{
    for(int i=0;i<num;i++) cout<<"-";
    cout<<"\n";
}


void str_reverse(string& str)
{
    string tmp;
    for(int i=str.length()-1;i>=0;i--) tmp.push_back(str[i]);
    str=tmp;
}

void delete_leading_0s(string & str)
{
    while(str[0]=='0')
    {
        str.erase(0,1);
    }
}

void dodaj(string &fst, string &snd, string & res)
{
    res.erase(0);
    char cyfra;
    int overflow=0;
    int pos1=fst.length()-1;
    int pos2= snd.length()-1;
    for(; pos1>=0 || pos2>=0 ; pos1--, pos2-- )
    {
        if(pos1>=0 && pos2>=0) {cyfra = fst[pos1] + snd[pos2];}
        else if (pos1< 0) {cyfra = '0'+ snd[pos2];}
        else {cyfra = fst[pos1] + '0';}
           
        cyfra+=overflow;
        cyfra-=48;
        if(cyfra>57) {cyfra-=10; overflow=1;}
        else overflow=0;
        //cout<<cyfra;
        res.push_back(cyfra);
      }
}

void odejmij(string &fst, string &snd, string & res)
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
}

void mnoz(string & fst, string &snd, string &res)
{
        res.erase(0);
        int z1,z2;
        int overflow=0;
        int product;
        int r_mod;
        int pos1=fst.length()-1;
        int pos2= snd.length()-1;
        string str_tab[(snd.length())];
       for(;pos2>=0;pos2--)
       {
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
        //   str_reverse(res);
        //   str_tab[snd.length()-pos2] = res;
       }
    //   for(int i=0; i<snd.length();i++)
    //   {
    //       cout<<str_tab[i];
    //   }
}

void print_add_sub(char znak, string & fst, string &snd, string &res)
{
    int max_length = max( max(fst.length(),snd.length()+1), res.length() );
  
    print_spaces(max_length - fst.length());
    cout<<fst<<endl;
    print_spaces(max_length - snd.length() -1);
    cout<<znak;
    cout<<snd<<endl;
    print_dash(max_length);
    print_spaces(max_length - res.length());
    cout<<res;
  
}

int main()
{
    //SPLIT
   string input;
   cin>>input;
   int counter1 = 0;
   char znak;
   while(znak = input[counter1])
   {
       if(znak > 47) counter1++;
       else break;
   }
   string first = input.substr(0,counter1);
   string second = input.substr(counter1+1);
   /*
   cout<< first <<endl;
   cout<< znak <<endl;
   cout<< second <<endl;
   */
   //SPLIT
   
   
  
   int mov = 0;
   string wynik;
   string helper;

   //cout<<pos1<<" "<<pos2<<endl;
   //do mnożenia

   string helper2;
   //do mnożenia
   if(znak=='+')
   {
       dodaj(first,second,helper);
   }
   
   else if (znak == '-')
   {
       odejmij(first,second,helper);
   }
   
   else //znak == '*'
   {
        mnoz(first,second,helper);
   }
   
  str_reverse(helper);
  wynik=helper;
  //do sub
  delete_leading_0s(wynik);
  //do sub
  print_add_sub(znak,first,second,wynik);
   
   return 0;
}
