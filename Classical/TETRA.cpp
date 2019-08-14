#include <iostream>
#include <iomanip>  //for setprecision
#include <math.h>   //for sqrt

using namespace std;

double calculate_the_determinant(double a1,double b1,double c1,double d1,double e1,double f1)
{
    double a=a1*a1;
    double b=b1*b1;
    double c=c1*c1;
    double d=d1*d1;
    double e=e1*e1;
    double f=f1*f1;
    
    //That two sums come from transforming the determinant shown at the wikipedia site (https://wikimedia.org/api/rest_v1/media/math/render/svg/54b6240b89a1f296099a6aca3fed341265e41207)
    // Yes, I could have used the formula shown below (https://wikimedia.org/api/rest_v1/media/math/render/svg/463da03fbc47d54e5e5f9cd60438a74281421e44) but I didn't :D
    double sum1 = (a-e+c)*(d-f-a+c)*(f-b+c)+(b-f+c)*(e-a+c)*(d-e-b+c)+2*c*(c-e-a)*(c-b-f);
    double sum2 = (e-a+c)*(c-b-f)*(a-e+c)+(f-b+c)*(b-f+c)*(c-e-a)+2*c*(d-f-a+c)*(d-e-b+c);
    
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

void parse_input(int n)
{
    double a,b,c,d,e,f;
    double radius;
    for(int i=0;i<n;++i)
    {
        cin>>a>>b>>c>>d>>e>>f;
    
        radius = 3*calculate_the_volume(calculate_the_determinant(a,b,c,d,e,f)) / ( area_heron(a,b,d)+area_heron(a,c,e)+area_heron(b,c,f)+area_heron(d,e,f) );
        cout<<fixed<<setprecision(4)<<radius<<endl;
    }
}

int main()
{

    int n;
    cin>>n;
    parse_input(n);
    
    return 0;
}
