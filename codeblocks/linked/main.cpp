#include<iostream>
using namespace std;
template<class T>
class node{
    public: T val;
    public: node* next=nullptr;
    public: node* pre=nullptr;
    node()
    {

	}
    ~node()
    {

	}
};
template<class T>
class p_vector{
public:
	node<T>* red=new node<T> ;
	node<T>* op=new node<T>;
	node<T>* ed;
	int num=0;
	p_vector()
	{
		op->pre=red;
		red->next=op;
		ed=op;

	}
	~p_vector()
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

};

template<class T>
    class iter: public p_vector{


	public: node<T>* now;
	public: iter(node<T>* tmp)
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
	public :iter<T>operator++(int k)
	{
		cout<<"又要妄下'\n";
		return now->next;
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
int main()
{
	p_vector<int> a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
	}
return 0;
}
