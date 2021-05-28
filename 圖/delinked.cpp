#include<iostream>
using namespace std;
template<class T>
class node{
    public: T val;
    public: node* next=nullptr;
    public: node* pre=nullptr;
public:
	typedef T& reference;
    node()
    {
    	cout<<"節點出現拉\n"; 
	}
	node(node<T>* tmp)
	{
		this->pre=tmp;
		cout<<"節點出現拉\n";
	}
    ~node()
    {
    	
	}
	T& operator*()
	{
		return val;
	}
	node<T>* operator++(int k)
	{
		return next;
	}
	node<T>& operator++()
	{
		return next;
	}
	node<T>* operator--(int k)
	{
		return pre;
	}

	
};
template<class T>
class iter{
	T* ptr;
public:
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
public: 
};
template<class T>
class vector{
public:
	node<T>* red=new node<T> ;
	node<T>* op=new node<T>;
	node<T>* ed;
	int num=0;
	vector()
	{
		op->pre=red;
		red->next=op;
		ed=op;
	}
	~vector()
	{
		auto it=red;
		for(;it!=ed;++it)
		{
			auto tmp=it;
			cout<<tmp->val<<"刪除\n";
			delete tmp;
		}
		delete it;
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
		ed->next=new node<T>(ed);
		ed=ed->next;
	}
	public: node<T>* begin()
	{
		return op;
	 }
	public: node<T>* end()
	{
		//iter<CL1> tmp(cp_Start);
		return  ed;
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
		cout<<it<<" ";
	}
}

