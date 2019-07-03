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
   
   
   int pos1=first.length()-1;
   int pos2= second.length()-1;
   int mov = 0;
   string wynik;
   string helper;
   char cyfra;
   int overflow=0;
   //cout<<pos1<<" "<<pos2<<endl;
   
   for(;pos1>=0 || pos2>=0;pos1--,pos2--)
   {
       if(pos1>=0 && pos2>=0) {cyfra = first[pos1] + second[pos2];}
       else if (pos1< 0) {cyfra = '0'+ second[pos2];}
       else {cyfra = first[pos1] + '0';}
       
       cyfra+=overflow;
       cyfra-=48;
       if(cyfra>57) {cyfra-=10; overflow=1;}
       else overflow=0;
       //cout<<cyfra;
       
       helper.push_back(cyfra);
   }
   
  for(int i=helper.length()-1;i>=0;i--) wynik.push_back(helper[i]);
  int max_length = max( max(first.length(),second.length()+1), wynik.length() );
  
  print_spaces(max_length - first.length());
  cout<<first<<endl;
  print_spaces(max_length - second.length() -1);
  cout<<znak;
  cout<<second<<endl;
  print_dash(max_length);
  print_spaces(max_length - wynik.length());
  cout<<wynik;
  
   
   return 0;
}
