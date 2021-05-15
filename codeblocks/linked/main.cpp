#include<iostream>
using namespace std;
template<class T>
class node{
    public: T val;
    public: node* next=nullptr;
    public: node* pre=nullptr;
    node()
    {
    	cout<<"葉子出現拉\n";
	}
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
	public :iter<T>operator=(iter<T>* tmp)
	{
		return tmp;
	}
	public :T& operator*()
	{
		return now->val;
	}
	public :iter<T>operator++()
	{
		cout<<"又要往下'\n";
		return now->next;
	}
	public :iter<T>operator++(int )
	{
		cout<<"又要妄下'\n";
		return iter(now->next);
	}
	public :bool operator!=(iter<T> tmp)
	{
		cout<<this<<" "<<&tmp<<"\n";
		if(this==&tmp)
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
		cout<<"又要加一\n";
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
	for(iter<int> it=a.begin();it!=a.end();it++)
	{
		cout<<"hi\n";
		cout<<*it<<" ";
	}
}
