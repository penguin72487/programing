#include<iostream>
using namespace std;

struct tree{
	int val;
	tree *l,*r;	
	
}a;
tree *find(int val);
bool dfs(tree *p,int val);
int main()
{

	int n;
	cin>>n;
	int val,l,r;
	cin>>a.val>>a.l->val>>a.r->val;
	for(int i=1;i<n;i++)
	{
		cin>>val>>l>>r;
		tree *temp=find(val)->l;
		temp->val=val;
		temp->l->val=l;
		temp->r->val=r;
		
	}
}
tree *find(int val)
{
	
	

}
bool dfs(tree *p,int val)
{
	if(!p) 
	return 0;
	dfs(p->l,val);
	dfs(p->r,val);
	if(p->val==val)
	{
		return 1;
	}
}
