#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	map<string,int> fb;
	
	int next;
	int be_it=0;
	while(next!=-1)
	{
		next=s.find_first_of(" ",be_it);
		if(fb[s.substr(be_it,next - be_it)]==1)
		fb[s.substr(be_it,next - be_it)]=3;
		else
		fb[s.substr(be_it,next - be_it)]=1;
		be_it=next+1;
	}
	/*
	for (auto it=fb.begin(); it!=fb.end(); ++it){
		cout << it->first << " => " << it->second << endl;
	}	*/
	getline(cin,s);
	be_it=0;
	next=0;
	while(next!=-1)
	{
		next=s.find_first_of(" ",be_it);
		if(fb[s.substr(be_it,next - be_it)]==1)
		cout<<"Yes"<<endl;
		else if (fb[s.substr(be_it,next - be_it)]==3)
		{
			cout<<"Pathetic"<<endl;
		}
		
		else
		cout<<"No"<<endl;
		be_it=next+1;
	}
	
	
}
