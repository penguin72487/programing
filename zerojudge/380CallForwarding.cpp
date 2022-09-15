#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;
class call_forward{
public:
    int phone_number;
    int adj_Call[10000]={0};
    int call[10000];
    call_forward(int t_phone_number){
        phone_number = t_phone_number;
    }
    void insert(int l,int r,int t_Call){
        adj_Call[l]+=t_Call;
        adj_Call[l+r+1]-=t_Call;
    }
    int operator[](int i){
        return call[i];
    }
    // constexpr call_forward& operator=(call_forward& tmp){
    //     phone_number = tmp.phone_number;
    // }
    void done(){
        for(int i=0,sum=0;i<10000;i++){
            sum+=adj_Call[i];
            call[i]=sum;
        }
    }
};
void output(int time,int call_Phone,int call){
    cout << "AT ";
    for (int i = 0; i < 3 - log10(time); ++i)
    {
        cout << "0";
    }
    cout << time << " CALL TO ";
    for (int i = 0; i < 3 - log10(call_Phone); ++i)
    {
        cout << "0";
    }
    cout << call_Phone << " RINGS ";
    for (int i = 0; i < 3 - log10(call); ++i)
    {
        cout << "0";
    }
    cout << call << "\n";

}
int main()
{
    cin.tie (0)->sync_with_stdio(0);
    cout.tie(0);
    cout << "CALL FORWARDING OUTPUT\n";
    int count = 0;
    int t;
    cin >> t;
    int input[4];
    unordered_map<int, call_forward*> ic_PhoneMap;
    while(cin >> input[0])
    {
        if(input[0]==0){
            break;
        }
        cin>>input[1]>>input[2]>>input[3];
        if(ic_PhoneMap.find(input[0])==ic_PhoneMap.end()){
            ic_PhoneMap[input[0]] = new call_forward(input[0]);
        }
        ic_PhoneMap[input[0]]->insert(input[1],input[2],input[3]);
    }
    for(auto it=ic_PhoneMap.begin();it!=ic_PhoneMap.end();++it)
    {
        it->second->done();
    }
    while(t--)
    {
        ++count;
        cout << "SYSTEM " << count << "\n";
        int time;
        while(cin >> time)
        {
            if(time ==9000)
            {
                if(t>0)
                {
                    cin >> time;
                }

                break;
            }
            
            int call_Phone;
            cin>>call_Phone;
            if(ic_PhoneMap.find(call_Phone) == ic_PhoneMap.end())
            {
                output(time, call_Phone, call_Phone);
                continue;
            }
            unordered_map<int, int> called;
            //called[call_Phone] = 1;
            int i_Call_Phone = call_Phone;
            
            for (; ic_PhoneMap[i_Call_Phone]->call[time];)
            {
                if(called.find(i_Call_Phone)!=called.end())
                {
                    i_Call_Phone = 9999;
                    break;
                }
                called[i_Call_Phone]=1;
                i_Call_Phone=ic_PhoneMap[i_Call_Phone]->call[time];
                if(ic_PhoneMap.find(i_Call_Phone)==ic_PhoneMap.end())
                {
                    break;
                }

            }
            output(time, call_Phone, i_Call_Phone);
        }
    }
    for(auto it=ic_PhoneMap.begin();it!=ic_PhoneMap.end();++it)
    {
        delete it->second;
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
