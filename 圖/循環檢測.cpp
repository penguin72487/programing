#include<iostream>
#include<unordered_map>
using namespace std;
class node{
public:
	int data;
	unordered_map<int,node*> in_List;
};
class graph{
public:
	node* op=nullptr;
	unordered_map<int,node*> in_Map;
	void insert(int u,int v)
	{
		
	}
	bool b_Circle()
	{
		
	}
	bool b_Circle()
	{
		
	}
	 
};
int main()
{
	graph tmp;
	tmp.insert(1,2);
	tmp.insert(2,3);
	tmp.insert(3,4);
	tmp.insert(3,1);
	

}

