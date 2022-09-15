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
        adj_Call[r+1]-=t_Call;
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
        ic_PhoneMap[input[0]] = new call_forward(input[0]);
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
                if(t>1)
                {
                    cin >> time;
                }

                break;
            }
            int call_Phone;
            cin>>call_Phone;
            if(ic_PhoneMap[time]==0)
            {
                cout << "AT ";
                for (int i = 0; i < 3-log10(time);++i)
                {
                    cout << "0";
                }
                cout << time << " CALL TO ";
                for (int i = 0; i < 3-log10(call_Phone);++i)
                {
                    cout << "0";
                }
                cout << call_Phone << " RINGS ";
                for (int i = 0; i < 3-log10(call_Phone);++i)
                {
                    cout << "0";
                }
                cout << call_Phone<<"\n";
            }
        }

    }
    for(auto it=ic_PhoneMap.begin();it!=ic_PhoneMap.end();++it)
    {
        delete it->second;
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
