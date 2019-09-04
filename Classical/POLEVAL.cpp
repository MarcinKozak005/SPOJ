#include <iostream>
#include <cmath>

using namespace std;

void readCoefficients(int* coeff, int degree)
{
    int input;
    for(int i=0; i<degree+1; ++i)
    {
        cin>>input;
        *(coeff+i)=input;
    }
}

//calculates the value of polynomial for a single point
int calculate(int numP, int* coeff, int degree, int x)
{
    int result=0;
    for(int i=degree; i!=-1; --i)
    {
        result+= *(coeff+(degree-i)) * pow(x,i);
    }
    return result;
}

//reads points form input and calculates the value of polynomial for a single point using calculate()
void readAndCalculate(int numP, int* coeff, int degree)
{
    int input;
    for(int i=0; i<numP; ++i)
    {
        cin>>input;
        cout<<calculate(numP,coeff,degree,input)<<endl;
    }
}

void parseInput()
{
    int degree;
    int* coefficients;
    int numPoints;
    int counter=1;
    
    cin>>degree;
    while(degree!=-1)
    {
        cout<<"Case "<<counter<<":"<<endl;
        
        coefficients= new int[degree+1];
        readCoefficients(coefficients,degree);
        cin>>numPoints;
        readAndCalculate(numPoints,coefficients,degree);
        delete(coefficients);
        
        counter++;
        cin>>degree;
    }
}

int main()
{
    parseInput();
    
    return 0;
}
