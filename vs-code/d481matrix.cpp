#include<iostream>
#include<vector>
//#include"../penguinLibrary/matrix/matrix.hpp"
using namespace std;
template <class T>
class matrix
{
    

public:
    vector<vector<T>> val;
    unsigned long long row;
    unsigned long long column;
    matrix(unsigned long long t_R,unsigned long long t_C)
    {
        row = t_R;
        column = t_C;
        val.resize(row);
        for(auto it=val.begin();it!=val.end();++it)
        {
            it->resize(column);
            it->assign(column,0);
        }


    }
    matrix(unsigned long long t_R,unsigned long long t_C,initializer_list<T> tmp)
    {
        row = t_R;
        column = t_C;
        val.resize(row);
        for(auto it=val.begin();it!=val.end();++it)
        {
            it->resize(column);
            it->assign(column,0);
        }
        auto t_Tmp = tmp.begin();
        for(auto it=val.begin();it!=val.end();++it)
        {
            for(auto jt = it->begin(); jt != it->end();++jt)
            {
                *jt = *t_Tmp;
                ++t_Tmp;
            }
            
        }


    }
    matrix(unsigned long long t_R,unsigned long long t_C,initializer_list<initializer_list<T>> tmp)
    {
        row = t_R;
        column = t_C;
        *this = tmp;
    }
    matrix(const matrix<T>&B)
    {
        val=B.val;
        row=B.row;
        column = B.column;
    }
    vector<T>& operator[](unsigned long long i)
    {
        return val[i];
    }
    void operator= (initializer_list<T> tmp)
    {
        auto t_Tmp = tmp.begin();
        for(auto it=val.begin();it!=val.end();++it)
        {
            for(auto jt = it->begin(); jt != it->end();++jt)
            {
                *jt = *t_Tmp;
                ++t_Tmp;
            }
            
        }
    }
    void operator= (initializer_list<initializer_list<T>>&& tmp)
    {
        val.clear();
        row=tmp.size();
        column = tmp.begin()->size();
        val.resize(row);
        auto p_Tmp=tmp.begin();
        for(auto it=val.begin();it!=val.end();++it)
        {
            *it=*p_Tmp;
            ++p_Tmp;
        }

    }
    void operator=(matrix<T> tmp)
    {
        val=tmp.val;
        row=tmp.row;
        column = tmp.column;
    }
    matrix<T> operator*(matrix<T> B)
    {
        // if(column!=B.row)
        // {
        //     return matrix<T>(0, 0);
        // }
        matrix<T> ANS(row,B.column);
        for (int i = 0; i < row;++i)
        {
            for (int j = 0; j < B.column;++j)
            {
                for(int k = 0; k < column;++k)
                {
                    ANS[i][j] += val[i][k] * B[k][j];
                }
            }
        }
        return ANS;
    }
    void operator*=(matrix<T> B)
    {
        //matrix<unsigned long long> t_B(B.row, B.column);t_B = B;
        if(column!=B.row)
        {
            cout << "Error\n";
        }
        matrix<T> ANS(row,B.column);
        for (int i = 0; i < row;++i)
        {
            for (int j = 0; j < B.column;++j)
            {
                for(int k = 0; k < column;++k)
                {
                    ANS[i][j] += val[i][k] * B[k][j];
                }
            }
        }
        val=ANS.val;
    }

    friend ostream &operator<<(ostream &s, matrix<T> ob)
    {
        for(auto it=ob.val.begin();it!=ob.val.end();++it)
        {
            for(auto jt=it->begin();jt!=it->end();++jt)
            {
                s << *jt<<" ";
            }
            s<< "\n";
        }
        return s;
    }
    friend istream& operator>>(istream&s, matrix<T> &ob)
    {
        for(auto it=ob.val.begin();it!=ob.val.end();++it)
        {
            for(auto jt=it->begin();jt!=it->end();++jt)
            {
                s >> *jt;
            }
        }
        return s;
    }
};
int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        if(b!=c)
        {
            cout<<"Error\n";
        }
        matrix<long long> A(a, b);
        matrix<long long> B(c, d);
        cin >> A>>B;
        cout << A * B;
    }
    

    return 0;
}