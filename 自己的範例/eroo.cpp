#include<iostream>
#include <initializer_list>
using namespace std;
class matrix{
public: 
	int **data;
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
		delete [] data; 
	}
	public: matrix pow(int n)
	{
		matrix ans(r,c);
		while (n) 
		{
			
	        if (n & 1)
	        {
	        	ans*(*this);
			}
			
	        (*this)=(*this)*(*this);
	        
	        n >>= 1;
	    }
	    
	    return ans;
	}
	void clear()
	{
		for (int i=0; i<r; i++)
		{   
			delete [] data[i];	
		}
		delete [] data; 	
	} 
	int* operator[](int i)
	{
		return data[i];
	}
	matrix& operator=(initializer_list<int> tmp)
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
	matrix& operator=(int tmp[][sizeof(data[0])/sizeof(int)])
	{
		for(int i=0;i<sizeof(data)/sizeof(int);i++)
		{
			for(int j=0;j<sizeof(data[0])/sizeof(int);j++)
			{
				data[i][j]=tmp[i][j];
			}
		}
	}
	matrix operator*(matrix tmp)
	{
		
		matrix ans(this->r,tmp.c);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<tmp.c;j++)
			{
				ans[i][j]=0;
				for(int k=0;k<c;k++)
				{
					ans[i][j]+=(*this[i][k]*tmp[k][j]);
				}
			
			}
		}
		return ans;
	}
	matrix operator*=(matrix tmp)
	{
		
		return (*this)*tmp;
	}
	
};
int main()
{
	matrix A(2,2,{1,1,1,0});
	matrix B(2,1,{1,0});
	cout<<"1\n";
	A=A*A;
	
	
	
	
	
	
	
	
	
	
	
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<1;j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<"\n";
	}

}

