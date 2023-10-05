#include<iostream>
using namespace std;
class node{
public:
	int val;
	node* l;
	node* r;
	node()
	{
		//cout<<"¾ð¸­¥X²{©Ô\n";
		l=nullptr;
		r=nullptr;
	}
	~node()
	{
		delete this;
	}
};
class tree{
public :
	node* op=new node;
	int num=0;
	tree()
	{

	}
	~tree()
	{

	}
	void insert(int p,int r,int l)
	{

		node* nl=new node;
		nl->val=l;
		node* nr=new node;
		nr->val=r;
		node* np;
		if(num)
		{
			np=dfserch(p,op);
		}
		else
		{
			np=op;
		}

		np->l=nl;
		np->r=nr;
		num++;
	}
	node* dfserch(int a,node* ptr)
	{

		node* tmp;
		while(ptr)
		{
			cout<<"·j´M¨ì"<<ptr->val<<endl;
			if(ptr->val==a)
			{
				return ptr;
			}
			else
			{
				tmp=dfserch(a,ptr->l);
				if(tmp)
				return tmp;
				tmp=dfserch(a,ptr->r);
				if(tmp)
				return tmp;
			}
		}
		return nullptr;
	}
};
int main()
{
	tree h;
	int  n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		h.insert(a,b,c);
	}

}
