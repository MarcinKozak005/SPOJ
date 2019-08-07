#include <iostream>
#include <string.h>     //for string
#include <vector>       //for vector class
#include <algorithm>    //for max function

using namespace std;

//Defined below the main()
void parseInput(int input_number);
void add(string &fst, string &snd, string & res);
void sub(string &fst, string &snd, string & res);
void mul(string &fst, string &snd, string &res, vector<string> & str_vec);
void print_add_sub(char sign, string & fst, string &snd, string &res);
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
    reverse(str.begin(),str.end());
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
    
        if (sign == '+')
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

void sub(string &fst, string &snd, string & res)
{
    res.erase(0);
    // sub function modify the fst string so wee need a copy
    string fst_copy(fst); 
    int pos1 = fst.length()-1;
    int pos2 = snd.length()-1;
    
    for(;pos1>=0 || pos2>=0;pos1--,pos2--)
       {
           if(pos2>=0)
           {
               if (fst_copy[pos1]>=snd[pos2]) res.push_back(fst_copy[pos1] - snd[pos2] + 48);
               else if (fst_copy[pos1]<snd[pos2])
               {
                   for(int i=(pos1-1); i>=0; i--)
                   {
                       if(fst_copy[i]!='0')
                       {
                           fst_copy[i]--;
                           break;
                       }
                       else
                       {
                           fst_copy[i]='9';
                       }
                   }
                   fst_copy[pos1] +=10;
                   res.push_back(fst_copy[pos1] - snd[pos2] + 48);
               }
           }
           else //fst.len() > snd.length()
           {
               res.push_back(fst_copy[pos1]);
           }
       }
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

void print_add_sub(char sign, string & fst, string &snd, string &res)
{
    int max_length = max( max(fst.length(),snd.length()+1), res.length() );
    int max_top_bar = max(snd.length()+1,res.length());
  
    print_spaces(max_length - fst.length());
    cout<<fst<<endl;
    print_spaces(max_length - snd.length() -1);
    cout<<sign;
    cout<<snd<<endl;
    print_spaces(max_length-max_top_bar);
    print_dash(max_top_bar);
    print_spaces(max_length - res.length());
    cout<<res;
  
}

void print_mul(string & fst, string &snd, string &res, vector<string> str_vec)
{
    int max_length = max( max(fst.length(),snd.length()+1), res.length() );
    int max_top_bar = max( snd.length() +1, str_vec[0].length() );
    int max_bottom_bar;
    
    print_spaces(max_length-fst.length());
    cout<<fst<<endl;
    print_spaces(max_length - snd.length() -1);
    cout<<'*';
    cout<<snd<<endl;
    
    if(snd.length()!=1)
    {
        max_bottom_bar = max( res.length(), str_vec[str_vec.size()-1].length() );
        print_spaces(max_length-max_top_bar);
        print_dash(max_top_bar);
        for(int i=0;i<str_vec.size();i++)
        {
            print_spaces(max_length-i-str_vec[i].length());
            cout<<str_vec[i]<<endl;
        }
        print_spaces(max_length-max_bottom_bar);
        print_dash(max_bottom_bar);
    }
    else //there is only 1 partial result -> different result printing
    {
        max_bottom_bar = max(snd.length()+1,res.length());
        print_spaces(max_length-max_bottom_bar);
        print_dash(max_bottom_bar);
    }
    
    print_spaces(max_length-res.length());
    cout<<res<<endl;
}
