#include<iostream>
#include<cmath>
using namespace std;
class c_Num{
public : 
    const  int theta_MOD = 360;
    c_Num(long double t_Len,long double t_Theta)
    {
        len = t_Len;
        theta = t_Theta;
        if(abs(t_Theta)>=360)
        {
            if(t_Theta<=-360)
            {
                theta -= int(theta / theta_MOD -1) * theta_MOD;
            }
            else
            {
                theta -= int(theta / theta_MOD) * theta_MOD;
            }
        }
    }
    long double len;
    long double theta;
};
int main()
{
    c_Num a(10,540), b(10,-470);

    return 0;
}