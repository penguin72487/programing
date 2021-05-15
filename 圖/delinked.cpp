#include<iostream>
using namespace std;
template<class T>
class node{
    public: T val;
    public: node* next=nullptr;
    public: node* pre=nullptr;
    node()
    {
    	cout<<"節點出現拉\n"; 
	}
	node(node<T>* tmp)
	{
		this->pre=tmp;
	}
    ~node()
    {
    	
	}
};
template<class T>
class iter{
	public :node<T>* now=nullptr;
	public :iter(node<T> tmp)
	{
		 now=&tmp;
		 //return this;
	}
	public :iter<T>operator=(iter<T> tmp)
	{
		return now=tmp->now;
	}
	public :T& operator*()
	{
		return now->val;
	}
	public :iter<T>operator++()
	{
		//cout<<"又要往下'\n";
		return iter<T>(now->next);
	}
	public :iter<T>operator++(int k)
	{
		//cout<<"又要妄下'\n";
		return iter<T> (now->next);
	}
	public :bool operator!=(iter<T> tmp)
	{
	//	cout<<this<<" "<<&tmp<<"\n"; 
		if(now==tmp.now)
		{
			cout<<"0"<<endl; 
			return 0;
		}
		else
		{
			cout<<"1"<<endl; 
			return 1;
		}
	}
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
		auto it=this->begin();
		for(;it!=this->end();++it)
		{
			auto tmp=it;
			cout<<*tmp<<"刪除\n";
			delete tmp.now;
		}
		delete it.now;
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
	for(iter<int> it=a.begin();it!=a.end();it++)
	{
		cout<<*it<<" ";
	}
}

