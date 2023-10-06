#include<iostream>
#include<vector>
using namespace std;
template <class T>
class data_node{
public:
	node<T>* u;
	node<T>* d;
	node<T>* l;
	node<T>* r;
	node()
	{
		u=this;
		d=this;
		l=this;
		r=this;
	}
};
template <class T>
class rc_node : public node<T>
{
public:
	int index;
	rc_node() : node<T>()
	{
		
	}
	rc_node(node<T> tmp)
	{
			this->
	}
	rc_node(int tmp) : node<T>()
	{
		index=tmp;
	}
};
template <class T>
class data_node : public node<T>
{
		int val;
		
		data_node(int tmp) : node<T>()
		{
			val=tmp;
		}
};

template <class T>
class matrix : public node<T>{
public: 
	int m_r=0;
	int m_c=0;
	matrix(int t_r,int t_c) :node<T>()
	{
		m_r=t_r;
		m_c=t_c;
		rc_node<T>* r_node=new rc_node<T> [m_r];
		this->r=r_node;
		for(int i=0;i<m_r;i++)
		{
			r_node[i].index=i;
			r_node[i-1].r;
		}
		
		rc_node<T>* c_node=new rc_node<T> [m_c];
		for(int i=0;i<m_c;i++)
		{
			r_node[i].index=i;
		}
		
	}
	void insert(int a,int b,int val)
	{
		
	}
	
};

int main()
{
	matrix <int> a(4,4);
	
}

