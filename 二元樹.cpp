#include<iostream>
using namespace std;

struct tree{
	int val;
	tree *l,*r;	
	
}a,e;
tree dfs(tree *p,int val);
int main()
{

	int n;
	cin>>n;
	int val,l,r;
	cin>>a.val>>a.l->val>>a.r->val;
	cout<<"+++++++++++++"<<endl;
	for(int i=1;i<n;i++)
	{
		cin>>val>>l>>r;
		tree temp=dfs(&a,val);
		temp.val=val;
		temp.l->val=l;
		temp.r->val=r;
		
	}
}
tree dfs(tree *p,int val)
{
	cout<<p->val<<endl;
//	if(!p) 
//	return e;
	if(p->val==val)
	{
		return *p;
	}
	dfs(p->l,val);
	dfs(p->r,val);

}
