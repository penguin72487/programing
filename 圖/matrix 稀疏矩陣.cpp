#include<iostream>
using namespace std;
class node{
public:
	node* u;
	node* d;
	node* l;
	node* r;
	node()
	{
		u=this;
		d=this;
		l=this;
		r=this;
	}
};
class matrix : public node{
	int r;
	int c;
	matrix(int t_r,int t_c) :node()
	{
		r=t_r;
		c=t_c;
	}
	
};
int main()
{
	
}

