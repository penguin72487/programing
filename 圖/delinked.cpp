#include<iostream>
using namespace std;
template<class T>
class node{
    public: T val;
    public: node* next=nullptr;
    public: node* pre=nullptr;
    ~node()
    {
    	delete this;
	}
};
template<class T>
class iter{
	public :node<T>* now;
	public :iter(node<T>* tmp)
	{
		now=tmp;
	}
	public :iter<T>operator=(node<T>* tmp)
	{
		return tmp;
	}
	public :T& operator*()
	{
		return now->val;
	}
	public :iter<T>operator++()
	{
		return now=now->next;
	}
	public :iter<T>operator++(int)
	{
		return now=now->next;
	}
	public :bool operator!=(iter<T> tmp)
	{
		return bool(!tmp.now);
	}
};
template<class T>
class vector{
public:
	node<T>* red=new node<T> ;
	node<T>* op=new node<T>;
	node<T>* ed=op;
	int num=0;
	vector()
	{
		red->next=ed;
	}
	~vector()
	{
		for(auto it=red;it!=nullptr;++it)
		{
			auto tmp=it;
			
			delete tmp;
		}
	}
	void clear()
	{
		for(auto it=op;it!=ed;++it)
		{
			auto tmp=it;
			
			delete tmp;
		}
	}
	void push_back(T tmp)
	{
		num++;
		ed->val=tmp;
		ed->next=new node<T>;
		ed=ed->next;
		
	}
	public: iter<T> begin()
	{
		return iter<T> (op);
	 } 
	public: iter<T> end()
	{
		//iter<CL1> tmp(cp_Start);
		return  iter<T> (ed);
	 }
};
int main()
{
	vector<int> a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
	}
	for(auto it=a.begin();it!=a.end();++it)
	{
		cout<<*it<<" ";
	}
}

