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
	matrix()
	{

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
	int det()
	{
		matrix tmp=*this;
		int ans=tmp[0][0]*tmp[1][1]-tmp[1][0]*tmp[0][1];
		return ans;
	}
	void clear()
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
		for(int i=0;i<sizeof(data)/sizeof(int);i++)
		{
			for(int j=0;j<sizeof(data[0])/sizeof(int);j++)
			{
				data[i][j]=*it++;
			}
		}
	}
	void operator=(int tmp[][sizeof(data[0])/sizeof(data[0][0])])
	{
		for(int i=0;i<sizeof(data)/sizeof(int);i++)
		{
			for(int j=0;j<sizeof(data[0])/sizeof(int);j++)
			{
				data[i][j]=tmp[i][j];
			}
		}

	}
	matrix operator=(matrix& tmp)
	{
		this->r=tmp.r;
		this->c=tmp.c;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				data[i][j]=tmp[i][j];
			}
		}
		
	}
	matrix operator=(matrix tmp)
	{
		this->r=tmp.r;
		this->c=tmp.c;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				data[i][j]=tmp[i][j];
			}
		}

	}
	matrix re()
	{
		matrix ans=*this;
		int d=det();
		ans[0][0]^=ans[1][1]^=ans[0][0]^=ans[1][1];
		ans[0][1]= (-1)*ans[0][1];
		ans[1][0]= (-1)*ans[1][0];
		ans = ans/d;
		return ans;
	}
	matrix operator*(matrix& tmp)
	{
	//	cout<<*this<<"\n*\n";
	//	cout<<tmp<<"\n=\n";
		
		matrix ans(r,tmp.c);

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<tmp.c;j++)
			{
				ans[i][j]=0;
				for(int k=0;k<c;k++)
				{
					ans[i][j]+=(data[i][k]*tmp[k][j]);
				}

			}
		}
	//cout<<ans<<"\n";
		return ans;
	}
	matrix operator*(int tmp)
	{
		matrix ans=*this;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				ans[i][j]*=tmp; 
			}
		}
		return ans;
	}
	matrix operator/(int tmp)
	{
		matrix ans=*this;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				ans[i][j]/=tmp; 
			}
		}
		return ans;
	}
		matrix operator+(matrix& tmp)
	{
		
		matrix ans(r,tmp.c);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<tmp.c;j++)
			{
				ans[i][j]=0;
				ans[i][j]=data[i][j]+tmp[i][j];
			}
		}
		return ans;
	}
	matrix operator-(matrix& tmp)
	{
		
		matrix ans(r,tmp.c);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<tmp.c;j++)
			{
				ans[i][j]=0;
				ans[i][j]=data[i][j]-tmp[i][j];
			}
		}
		return ans;
	}

	matrix pow(int n)
	{
		matrix ans(2,2,{1,0,0,1});
		if(n>=0)
		{
			matrix A=*this;	
			while(n){
				if(n&1){
	
					ans = ans*A;
	
				}
				A =A*A;
	
				n >>= 1;
	
			}	
		}
		else
		{
			ans=re();	
		}
		
		
		return ans;

	}


	friend ostream &operator<<(ostream &s, matrix ob);

};
ostream& operator<<(ostream &s, matrix ob)
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			s<<ob[i][j]<<" ";
		}
		s<<"\n";
	}
	return s;
}
int det(matrix& tmp)
{
	int ans=tmp[0][0]*tmp[1][1]-tmp[1][0]*tmp[0][1];
	return ans;
}
int main()
{
	matrix A(2,2,{1,-2,1,4});
	matrix B(2,2,{-1,-1,5,4});
	matrix P(2,2,{1,2,-1,-1});
	matrix c{2,2,{-3,-6,2,2}};
	cout<<c*P<<"\n";
	matrix ans=P.pow(-1)*A*P;

	cout<<ans<<"\n";


	return 0;
}

