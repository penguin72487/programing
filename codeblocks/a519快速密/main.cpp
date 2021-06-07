#include<iostream>
#include <initializer_list>
using namespace std;
class matrix{
public:
	int **data=nullptr;
	int r;
	int c;
	matrix(int i_r,int i_c,initializer_list<int> tmp)
	{
		r=i_r;
		c=i_c;
		data = new int*[r];
		for(int i = 0; i < r; i++)
		{
			data[i] = new int[c];
		}
		*this=tmp;
	}
	matrix(int i_r,int i_c)
	{
		r=i_r;
		c=i_c;
		data = new int*[r];
		for(int i = 0; i < r; i++)
		{
			data[i] = new int[c];
		}
	}
	~matrix()
	{
		for (int i=0; i<r; i++)
		{
			delete [] data[i];
		}
		for (int i=1; i<r; i++)
		{
			delete  data[i];
		}
	}

	int* operator[](int i)
	{
		return data[i];
	}
	void operator=(initializer_list<int> tmp)
	{
		auto it=tmp.begin();
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				data[i][j]=*it++;
			}
		}
	}
	matrix operator*(matrix tmp)
	{

		matrix ans(r,tmp.c);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<tmp.c;j++)
			{
				ans[i][j]=0;
				for(int k=0;k<c;k++)
				{
					ans[i][j]=ans[i][j]+(data[i][k]*tmp[k][j]);
				}

			}
		}

		return ans;
	}

	matrix& operator*=(matrix& tmp)
	{

		return *this=((*this)*tmp);
	}
	matrix pow(int n)
	{
		matrix A=*this;
		matrix ans(2,2,{1,0,0,1});

		while(n){
			if(n&1){

				ans = ans*A;

			}
			A *=A;

			n >>= 1;

		}

		return ans;

	}


};

int main()
{
	matrix A(2,2,{1,1,1,0});
	//matrix B(2,1,{1,0});
	matrix ans(2,2);
	int n;
    while(cin>>n&&n!=0)
    {
        cout<<A.pow(n)[0][0]<<"\n";

    }


return 0;
}
