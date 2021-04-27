#include<iostream>
#include<algorithm>
#include<deque>
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

}high,*tree_end;
tree* dfserch(int find,tree* tmp);
int dfshigh(tree* tmp);
void insert(int val,int l,int r);
int main()
{

	int n;
	cin>>n;
	int val,l,r;
	cin>>val>>l>>r;
	high.val=val;
	tree* temp = new tree[2];
	(*temp).val=l;
	(*(temp+1)).val=r;
	high.l=temp;
	high.r=temp+1; 
	for(int i=0;i<n-1;i++)
	{
		tree* temp = new tree; 
		int val,r,l;
		cin>>val>>r>>l;
		insert(val,l,r);
	}
	 dfserch(3,&high);
	cout<<"h="<<dfshigh(&high)<<endl;
	
}
void insert(int val,int l,int r)
{
	//cout<<val<<" "<<l<<" "<<r<<endl; 
	tree* it=dfserch(val,&high);
	if(it!=tree_end)
	{
		tree* temp = new tree[2];
		temp->val=l;
		(temp+1)->val=r;
		it->l=temp;
		it->r=temp+1; 
	}
	
}
tree* dfserch(int find,tree* tmp)
{
	cout<<tmp->val<<endl;
	if((*tmp).val=find)
	{
		return tmp;
	}
	if(!tmp)
	{
		return tree_end;
	}
	tree* it=dfserch(find,tmp->l);
	tree* jt=dfserch(find,tmp->r);
	if(it!=tree_end)
	{
		return it;
	}
	else if(jt!=tree_end)
	{
		return jt;
	}
	else
	{
		return tree_end;
	}

}
int dfshigh(tree* tmp)
{
	//cout<<tmp->val<<endl;
	if(tmp->val==-1)
	return 1;
	return max(dfshigh(tmp->l), dfshigh(tmp->r))+1;
}
