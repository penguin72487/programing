#include<iostream>
#include<vector>
using namespace std;
#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

template <class T>
class matrix
{
    

public:
    vector<vector<T>> val;
    long long row;
    long long column;
    matrix(long long t_R,long long t_C)
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
    matrix(long long t_R,long long t_C,initializer_list<T> tmp)
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
    matrix(matrix<T>& tmp,initializer_list<T> tmp)
    {
        
    }
    vector<T>& operator[](long long i)
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
    void operator=(matrix<T> tmp)
    {
        val=tmp.val;
    }
    void operator*=(matrix<T> B)
    {
        //matrix<long long> t_B(B.row, B.column);t_B = B;
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

    friend ostream &operator<<(ostream &s, matrix &ob)
    {
        for(auto it=ob.val.begin();it!=ob.val.end();++it)
        {
            for(auto jt=it->begin();jt!=it->end();++jt)
            {
                s << *jt<<" ";
            }
            cout<< "\n";
        }
        return s;
    }
};
#endif // _MATRIX_HPP_
