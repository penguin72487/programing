#include<iostream>
#include <initializer_list>
using namespace std;
char t;
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
	matrix(int i_r,int i_c,int**& tmp)
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
	matrix(int I)
	{
        r=I;
		c=I;
		data = new int*[r];
		for(int i = 0; i < r; i++)
		{
			data[i] = new int[c];
		}
		for(int i=0;i<I;i++)
        {
            for(int j=0;j<I;j++)
            {
                if(i!=j)
                {
                    data[i][j]=0;
                }
                else
                {
                    data[i][j]=1;
                }
            }
        }
	}
	matrix()
	{

	}
	~matrix()
	{
		for (int i=0; i<c; i++)
		{
			delete [] data[i];
		}
        delete[] data;
    }
	int det()
	{

		int ans=data[0][0]*data[1][1]-data[1][0]*data[0][1];
		return ans;
	}
	void clear()
	{
		for (int i=0; i<r; i++)
		{
			delete [] data[i];
		}
        delete[] data;
    }
	int* operator[](int i)
	{
		return data[i];
	}
	void operator=(initializer_list<int> tmp)
	{
		auto it=tmp.begin();
        int n = r;
        int m = c;
        for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				data[i][j]=*it++;
			}
		}
		//	cout<<"{}"<<endl;
	}
    /*
	void operator=(int tmp[][sizeof(data[0])/sizeof(data[0][0])])
	{
		for(int i=0;i<sizeof(data)/sizeof(int);i++)
		{
			for(int j=0;j<sizeof(data[0])/sizeof(int);j++)
			{
				data[i][j]=tmp[i][j];
			}
		}
		cout<<"[][]"<<endl;
	}
    */
	void operator=(int** tmp)
	{
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				data[i][j]=tmp[i][j];
			}
		}
		//cout<<"**"<<endl;
	}

	void operator=(matrix tmp)
	{
		r=tmp.r;
		c=tmp.c;

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				data[i][j]=tmp[i][j];
			}
		}
		cout<<"re"<<endl;
	}

	void operator=(matrix& tmp)
	{
		r=tmp.r;
		c=tmp.c;

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				data[i][j]=tmp[i][j];
			}
		}
		cout<<"&"<<endl;
	}
	matrix re()
	{
		matrix ans(2,2);
		int d=det();
		if(d==0)
        {
            cout<<*this<<"¡LS|3?I¡Âx¢X}3a!\n";
        }
		ans[0][0]=data[1][1];
		ans[1][1]=data[0][0];
		ans[0][1]= (-1)*data[0][1];
		ans[1][0]= (-1)*data[1][0];
		ans = ans/d;

		return ans;
	}
	matrix operator*(matrix tmp)
	{
		//cout<<*this<<"\n*\n";
		//cout<<tmp<<"\n=\n";

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
	void operator*=(matrix tmp)
	{
		//cout<<*this<<"\n*\n";
		//cout<<tmp<<"\n=\n";

		matrix ans(r,tmp.c);

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<tmp.c;j++)
			{
				ans[i][j]=0;
				for(int k=0;k<c;k++)
				{
					ans[i][j]+=(data[i][k]*tmp[k][j]);
                    //cout << ans[i][j] << " ";
                }

			}
		}
		r=ans.r;
		c=ans.c;

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				data[i][j]=ans[i][j];
			}
		}
		
	}
	void operator*=(int tmp)
	{
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				data[i][j]*=tmp;
			}
		}

	}
	void operator+=(matrix& tmp)
	{
	    for(int i=0;i<r;i++)
		{
			for(int j=0;j<tmp.c;j++)
			{
				data[i][j]+=tmp[i][j];
			}
		}

	}
	void operator-=(matrix& tmp)
	{
	    for(int i=0;i<r;i++)
		{
			for(int j=0;j<tmp.c;j++)
			{
				data[i][j]-=tmp[i][j];
			}
		}

	}
    bool operator==(matrix tmp)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(data[i][j]!=tmp[i][j])
                {
                    cout<<data[i][j]<<" "<<tmp[i][j]<<"3a";
                    return 0;
                }
            }
        }
        return 1;
    }
	matrix pow(int n)
	{

		matrix ans(r);
		if(n>=0)
		{
			matrix A(r,c,data);
			
			

			while(n){
				if(n&1){

					ans*=A;

				}
				A*=A;

				n >>= 1;

			}
		}
		else
		{

			ans=re();

		}

		return ans;

	}
	matrix pow(char )
	{
		matrix ans(r,c);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				ans[i][j]=data[j][i];
			}
		}
		return ans;

	}

	friend ostream &operator<<(ostream &s, matrix ob);

};
ostream& operator<<(ostream &s, matrix ob)
{
	for(int i=0;i<ob.r;i++)
	{
		for(int j=0;j<ob.c;j++)
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
matrix operator*(int tmp,matrix b)
{
	matrix ans=b;
	for(int i=0;i<ans.r;i++)
	{
		for(int j=0;j<ans.c;j++)
		{
			ans[i][j]*=tmp;
		}
	}
	return ans;
}
int main()
{

	matrix A(4,4,{1,1,1,-1,1,1,-1,1,1,-1,1,1,-1,1,1,1});
	matrix B(2,2,{1,-1,1,1});
	matrix P(2,2,{1,2,-1,-1});
	matrix C{2,2,{-3,-6,2,2}};

	//cout<<C*P<<"\n";

	cout<<B.pow(3)<<"\n";
	cout<<4*A<<endl;


	return 0;
}

