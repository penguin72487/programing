#include <iostream>

using namespace std;
int n;
bool find(string s[],string tmp)
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
bool fn_string(string s[],string tmp);
int main()
{

    while(cin>>n)
    {
         string s[n];
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
         if(fn_string(s,c_s))
         {
             cout<<"TRUE\n";
         }
         else
         {
             cout<<"FALSE\n";
         }

    }

}
bool fn_string(string s[],string tmp)
{
    if(find((s,tmp)))
    {
        return 1;
    }

}
