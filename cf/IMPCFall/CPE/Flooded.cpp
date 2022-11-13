#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iomanip>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    int k = 0;
    while(cin>>n>>m)
    {
        ++k;
        if(n==m&&n==0)
        {
            break;
        }
        

        vector<long long> region;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int t;
                cin >> t;
                region.push_back(t);
            }
        }
        long long flood;
        cin >> flood;
        flood /= 100;
        cout << "Region " << k<<"\n";
        if(n==m&&n==1)
        {
            cout << "Water level is "<<fixed <<setprecision(2)<< float(region[0]+flood) << " meters.\n";
            cout << "100.00 percent of the region is under water.\n";
        }
        sort(region.begin(),region.end());
        vector<long long> pre_Sum(n*m);
        partial_sum(region.begin(), region.end(), pre_Sum.begin());
        bool flag = 0;
        for(int i=0;i<n*m;++i)
        {
            long long sum =region[i]*(i+1)-pre_Sum[i];
            if(sum>=flood)
            {
                //cout << region[i-1]<< "\n";
                sum = region[i-1]*(i)-pre_Sum[i-1];
                float f = float(flood -sum) / (float)(i);
                cout<<"Water level is "<<fixed <<setprecision(2)<< region[i-1]+f<< " meters.\n";
                cout << float(i) / float(n*m)*100 << " percent of the region is under water.\n";
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            int i = n*m;
            long long sum = region[i-1]*(i)-pre_Sum[i-1];
            float f = float(flood -sum) / (float)(i);
            cout<<"Water level is "<<fixed <<setprecision(2)<< region[i-1]+f<< " meters.\n";
            cout << float(i) / float(n*m)*100 << " percent of the region is under water.\n";
        }
        

    }
    return 0;
}