#include <iostream>
using namespace std;
class country{
public :
    int meddle[3]={0};
    string name;
    country(){

    }
    country(int g,int s,int b,string ss)
    {
        meddle[0] = g;
        meddle[1] = s;
        meddle[2] = b;
        name = ss;
    }
    void operator= (country &t)
    {
        meddle[0] = t.meddle[0];
        meddle[1] = t.meddle[1];
        meddle[2] = t.meddle[2];
        name = t.name;
    }
    bool operator >(country &C2){
        if(meddle[0] == C2.meddle[0]){
            if(meddle[1] == C2.meddle[1]){    
                if(meddle[2] == C2.meddle[2]){
                    for(auto it=name.begin(),jt=C2.name.begin(); it!=name.end()||jt!=C2.name.end(); ++it,++jt){
                        if(*it==*jt)
                        {
                            continue;
                        }
                        else {
                            return (*it > *jt);
                        }
                        
                    }
                }
                else {
                    return (meddle[2] > C2.meddle[2]);
                }
            }
            else {
                return (meddle[1] > C2.meddle[1]);
            }
        }
        else {
            return (meddle[0] > C2.meddle[0]);
        }

        return 0;
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int g;
    int s;
    int b;
    string ss;
    country best_Country(0,0,0,"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    for(int i=0;i<n;i++){
        cin >> g >> s >> b;
        getline(cin, ss);
        cin.sync();
        country tmp(g,s,b,ss);
        if(tmp>best_Country)
        {
            best_Country=tmp;
        }
    }
    cout << best_Country.name<<"\n";
}