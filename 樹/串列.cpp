#include<iostream>
using namespace std;
template <class T> 
	class node
	{
		public :T val;
		public :node* next;
		public :node* pre;
		node()
		{
			next=nullptr;
			pre=nullptr;
		}
	};
	
template <class T> 
	class vector
	{
		public :node<T>* op;  
		public :node<T>* ed;
		int num=0;
		vector()
		{
			op=new node<T>;
			ed=new node<T>;
			
		}
		node<T>* begin()
		{
			return op;
		}
		node<T>* end()
		{
			return ed;
		}
		void push_back(T a)
		{
			ed->val=a;
			ed=new node<T>;
			num++;
		}
		void size()
		{
			return num;
		}
		void clear()
		{
			for(auto it=op;it!=ed;it=it->next)
			{
				delete it;
			}
		}
		~vector()
		{
			for(auto it=op;it!=ed;it=it->next)
			{
				delete it;
			}
		}
	};
int main()
{
	vector<int> a;
	a.push_back(1);
	for(auto it=a.begin();it!=a.end();it=it->next)
	{
		cout<<it->val<<endl;
	}
}

