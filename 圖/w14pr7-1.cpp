#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
class adj_Matrix{
public:
	vector<vector<int>> list;
	deque<int> stack;
	adj_Matrix()
	{
		
	}
	adj_Matrix(int n)
	{
		list.resize(n+1);
	}
	vector<int> operator[] (int n)
	{
		return list[n+1]; 
	}
	void insert(int tmp,int tmp2)
	{
		list[tmp].push_back(tmp2);
	}
	int find_Judge(int n)
	{
		
	}
	
};
int main()
{
	int n,m;
	cin>>n>>m;
	adj_Matrix list;
	for(int i=0;i<m;i++)
	{
		int tmp,tmp2;
		cin>>tmp>>tmp2;
		list.insert(tmp,tmp2);
	}
	
	

}

