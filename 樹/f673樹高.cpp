#include<iostream>
#include<queue>
using namespace std;
struct tree{
	int val;
	tree *l;
	tree *r;
	tree()
	{
		l=NULL;
		r=NULL;
	}
};
tree* bfs(int val);
void insert(int val,int l,int r);

int main()
{

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		tree* temp; 
		int val,r,l;
		cin>>val>>r>>l;
		
	}
	
}
tree* bfs(int val)
{
	
}
