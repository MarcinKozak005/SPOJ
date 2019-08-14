// Example program
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

double calculate_the_determinant(double a1,double b1,double c1,double d1,double e1,double f1)
{
    double a=a1*a1;
    double b=b1*b1;
    double c=c1*c1;
    double d=d1*d1;
    double e=e1*e1;
    double f=f1*f1;
    
    double sum1 = (a-d+e)*(c-f-a+e)*(f-b+e)+(b-f+e)*(d-a+e)*(c-d-b+e)+2*e*(e-d-a)*(e-b-f);
    double sum2 = (d-a+e)*(e-b-f)*(a-d+e)+(f-b+e)*(b-f+e)*(e-d-a)+2*e*(c-f-a+e)*(c-d-b+e);
    
    return sum1-sum2;
}

double calculate_the_volume(double determinant)
{
    return sqrt(determinant/288); 
}

double area_heron(double x, double y, double z)
{
    double perimiter = (x+y+z)/2;
    
    return sqrt(perimiter*(perimiter-x)*(perimiter-y)*(perimiter-z));
}

// void parse_input(int n)
// {
//     double a,b,c,d,e,f;
//     for(int i=0;i<n;++i)
//     {
//         cin>>a>>b>>c>>d>>e>>f;
    
//     double radius = calculate_the_determinant(a,b,c,d,e,f);
//     //double radius = 3*calculate_the_volume(calculate_the_determinant(a,b,c,d,e,f)) / ( area_heron(a,b,c)+area_heron(a,b,d)+area_heron(a,d,c)+area_heron(d,b,c) );
//     cout/*<<setprecision(4)*/<<radius<<endl;
//     }
// }

int main()
{
    double a,b,c,d,e,f;
    
    cin>>a>>b>>c>>d>>e>>f;
    double radius = calculate_the_determinant(a,b,c,d,e,f);
    //double radius = 3*calculate_the_volume(calculate_the_determinant(a,b,c,d,e,f)) / ( area_heron(a,b,c)+area_heron(a,b,d)+area_heron(a,d,c)+area_heron(d,b,c) );
    cout/*<<setprecision(4)*/<<radius<<endl;
    
    // int n;
    // cin>>n;
    // parse_input(n);
    
    
    return 0;
}
