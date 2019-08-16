#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

//Defined below the main()
void parseInput(int input_number);
void add(string &fst, string &snd, string & res);
void sub(string &fst, string &snd, string & res);
void mul(string &fst, string &snd, string &res, vector<string> & str_vec);
void print_add_sub(char znak, string & fst, string &snd, string &res);
void print_mul(string & fst, string &snd, string &res, vector<string> str_vec);

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


int main()
{

    int input_number;
    cin>>input_number;
    
    parseInput(input_number);
   
    return 0;
}

void parseInput(int input_number)
{
    for(int i=0; i<input_number; i++)
    {
        string input;
        cin>>input;
        
        //Splitting input into: first (argument), sign (operation), second (argument)
        int field = 0;
        char sign;
        while(sign = input[field])
        {
            if(sign > 47) field++;
            else break;
        }
        string first = input.substr(0,field);
        string second = input.substr(field+1);
        //end of Splitting
      
        string result;
    
        if(sign == '+')
        {
            add(first,second,result);
            print_add_sub(sign,first,second,result);
        }
        else if (sign == '-')
        {
            sub(first,second,result);
            delete_leading_0s(result);
            print_add_sub(sign,first,second,result);
        }
        else // sign == '*'
        {
            vector<string> partial_results;
            
            mul(first,second,result,partial_results);
            print_mul(first,second,result,partial_results);
        }
        
        cout<<"\n\n";
    }
}

void add(string &fst, string &snd, string & res)
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
      if(overflow!=0) res.push_back(overflow+48);
      str_reverse(res);
}

void sub(string &fst, string &snd, string & res)
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

void mul(string &fst, string &snd, string &res, vector<string> & str_vec)
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
           add(res,str_vec[i],helper2);
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
    int max_1 = max(snd.length()+1,res.length());
  
    print_spaces(max_length - fst.length());
    cout<<fst<<endl;
    print_spaces(max_length - snd.length() -1);
    cout<<znak;
    cout<<snd<<endl;
    print_spaces(max_length-max_1);
    print_dash(max_1);
    print_spaces(max_length - res.length());
    cout<<res;
  
}

void print_mul(string & fst, string &snd, string &res, vector<string> str_vec)
{
    int max_length = max( max(fst.length(),snd.length()+1), res.length() );
    int max_1 = max( snd.length() +1, str_vec[0].length() );
    int max_2;
    
    print_spaces(max_length-fst.length());
    cout<<fst<<endl;
    print_spaces(max_length - snd.length() -1);
    cout<<'*';
    cout<<snd<<endl;
    
    if(str_vec.size()!=1)
    {
        max_2 = max( res.length(), str_vec[str_vec.size()-1].length() );
        print_spaces(max_length-max_1);
        print_dash(max_1);
        for(int i=0;i<str_vec.size();i++)
        {
            print_spaces(max_length-i-str_vec[i].length());
            cout<<str_vec[i]<<endl;
        }
        print_spaces(max_length-max_2);
        print_dash(max_2);
    }
    else
    {
        max_2 = max(snd.length()+1,res.length());
        print_spaces(max_length-max_2);
        print_dash(max_2);
    }
    
    print_spaces(max_length-res.length());
    cout<<res<<endl;
}
