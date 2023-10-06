#include <iostream>
#include<algorithm>
using namespace std;
struct student{
    double tall;
    int num;
};
struct _sort{
    bool operator() (student& val,student& val2)
    {
        if(val.tall>val2.tall)
        {
            return true;
        }
        else if(val.tall==val2.tall)
        {
            if(val.num<=val2.num)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
        else
        {
            return false;
        }
    }
};
int main()
{

    student stu[5]={{172,3},{172,2},{183,4},{181,1},{181,3}};
    sort(stu,stu+5,stu);

}
