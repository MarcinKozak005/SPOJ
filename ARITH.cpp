#include <iostream>
#include <string.h>
#include <vector>
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
      str_reverse(res);
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
       str_reverse(res);
}

void mnoz(string &fst, string &snd, string &res, vector<string> & str_vec)
{
        res.erase(0);
        int z1,z2;
        int overflow=0;
        int product;
        int r_mod;
        int pos1=fst.length()-1;
        int pos2= snd.length()-1;
        //vector<string> str_vec;
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
           if(overflow!=0) res.push_back(overflow+48);
           pos1=fst.length()-1;
           str_reverse(res);
           str_vec.push_back(res);
           //cout<<"asdasda->"<<res<<endl;
       }
       
       //dodanie zer
       for(int i=0;i<str_vec.size();i++)
       {
           string a = str_vec[i];
           //if(a=="0") continue;
           for(int j=0;j<i;j++)
           {
               a+="0";
           }
           str_vec[i]=a;
       }
       
       string helper2;
       res=str_vec[0];
       for(int i=1;i<str_vec.size();i++)
       {
           //cout<<"Res: "<<res<<" + "<< str_vec[i]<<" = ";
           dodaj(res,str_vec[i],helper2);
           //cout<<helper2<<endl;
           res=helper2;
           helper2.erase(0);
           //cout<<"Res po h2.rease: "<<res<<endl;
       }
       
       for(int i=1;i<str_vec.size();i++)
       {
           str_vec[i].erase(str_vec[i].length()-i);
       }
       
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

void print_mul(string & fst, string &snd, string &res, vector<string> str_vec)
{
    int max_all = max( max(fst.length(),snd.length()+1),res.length());
    int max_two = max(fst.length(),snd.length()+1);
    
    print_spaces(max_all-fst.length());
    cout<<fst<<endl;
    print_spaces(max_all - snd.length() -1);
    cout<<'*';
    cout<<snd<<endl;
    print_spaces(max_all-max_two);
    
    if(str_vec.size()!=1)
    {
        print_dash(max_two);
    for(int i=0;i<str_vec.size();i++)
    {
        print_spaces(max_all-i-str_vec[i].length());
        cout<<str_vec[i]<<endl;
    }
    }
    print_dash(max_all);
    cout<<res<<endl;
}

int main()
{
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
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

  
   int mov = 0;
   string wynik;
   string helper;

   if(znak=='+')
   {
       dodaj(first,second,helper);
   }
   else if (znak == '-')
   {
       odejmij(first,second,helper);
       delete_leading_0s(helper);
   }
   else //znak == '*'
   {
        vector<string> vec;
        mnoz(first,second,helper,vec);
        print_mul(first,second,helper,vec);
   }
   
      wynik=helper;

      if(znak!='*') print_add_sub(znak,first,second,wynik);
      cout<<"\n\n";
    }//od inputów
   
   return 0;
}
