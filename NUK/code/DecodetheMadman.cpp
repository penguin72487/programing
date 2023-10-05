#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    while(getline(cin,s))
    {
        for(auto it:s)
        {
            if(it<='Z'&&it>='A')
            {
                it=it-'A'+'a';
            }
            switch (it)
            {
                    case '=':cout<<"0";break;
                    case '-':cout<<"9";break;
                    case '0':cout<<"8";break;
                    case '9':cout<<"7";break;
                    case '8':cout<<"6";break;
                    case '7':cout<<"5";break;
                    case '6':cout<<"4";break;
                    case '5':cout<<"3";break;
                    case '4':cout<<"2";break;
                    case '3':cout<<"1";break;
                    case '2':cout<<"`";break;

                    case '\\':cout<<"[";break;
                    case ']':cout<<"p";break;
                    case '[':cout<<"o";break;
                    case 'p':cout<<"i";break;
                    case 'o':cout<<"u";break;
                    case 'i':cout<<"y";break;
                    case 'u':cout<<"t";break;
                    case 'y':cout<<"r";break;
                    case 't':cout<<"e";break;
                    case 'r':cout<<"w";break;
                    case 'e':cout<<"q";break;

                    case '\'':cout<<"l";break;
                    case ';':cout<<"k";break;
                    case 'l':cout<<"j";break;
                    case 'k':cout<<"h";break;
                    case 'j':cout<<"g";break;
                    case 'h':cout<<"f";break;
                    case 'g':cout<<"d";break;
                    case 'f':cout<<"s";break;
                    case 'd':cout<<"a";break;
                    case 's':cout<<".";break;
                    case '/':cout<<",";break;
                    case '.':cout<<"m";break;
                    case ',':cout<<"n";break;
                    case 'm':cout<<"b";break;
                    case 'n':cout<<"v";break;
                    case 'b':cout<<"c";break;
                    case 'v':cout<<"x";break;
                    case 'c':cout<<"z";break;
                    default : cout<<" ";break;
            }
        }
        cout<<"\n";
    }


    cin.sync();


    return 0;
}