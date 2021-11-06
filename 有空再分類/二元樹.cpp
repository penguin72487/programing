#include<iostream>
#include<vector>
using namespace std;

struct tree{
	fuck(){
		cout<<"fuck"<<endl;
	};
	int val;
	tree *l,*r;	
	
};

int main()
{

	int n;
	cin>>n;
vector <tree*> root;
	tree* a,l,r;
	cin>>a->val;
	root.push_back(a);
	cin>>l.val;
	root.push_back(&l);
	cin>>r.val;
	root.push_back(&r);
	a->l=&l;
	a->r=&r;
	l.l= NULL;
	l.r=NULL;
	r.l=NULL;
	r.r=NULL;
	cout<<a->val<<" "<<l.val<<" "<<r.val<<" \n";
	for(auto it=root.begin();it!=root.end();it++)
	{
		cout<<(*it)->val<<" ";
	}
}
	


