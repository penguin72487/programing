#include <iostream>

using namespace std;
int n;
string s[100];
bool fn_find(string tmp)
{
    for(int i=0;i<n;i++)
    {
        if(s[i]==tmp)
        {
            return 1;
        }
    }
    return 0;
}
bool fn_string(string tmp);

int main()
{

    while(cin>>n)
    {
         
         for(int i=0;i<n;i++)
         {
             cin>>s[i];
         }
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<s[i].length();j++)
             {
                 if(s[i][j]<='Z')
                 {
                     s[i][j]+='z'-'Z';
                 }
             }
         }
         string c_s;
         cin>>c_s;
         if(fn_string(c_s))
         {
             cout<<"TRUE\n";
         }
         else
         {
             cout<<"FALSE\n";
         }

    }

}
bool fn_string(string tmp)
{
    if(fn_find((tmp)))
    {
        return 1;
    }
    for (int i= 1; i<=tmp.length();i++)
	{
		if (fn_find(tmp.substr(0,i)) &&fn_string( tmp.substr(i,tmp.length()- i)))
		{
            return true;
        }

	}
	return false;

}

