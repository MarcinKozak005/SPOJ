#include <iostream>

using namespace std;






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
   cout<< first <<endl;
   cout<< znak <<endl;
   cout<< second <<endl;
   //SPLIT
   
   int pos1=first.length();
   int pos2= second.length();
   int mov = 0;
   string wynik;
   for(;pos1>=0 && pos2>=0;pos1--,pos2--)
   {
       cout<<"a";
   }
   
   
   return 0;
}
