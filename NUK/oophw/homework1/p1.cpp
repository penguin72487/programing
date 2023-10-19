#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,section-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")

#define cube_macro(x) x * x * x  // macro 

long long cube_regular(const long long& s) { return s * s * s; } // function
inline long long cube_inline(const long long& s) { return s * s * s; } //inline function

double diffclock(clock_t& clock1, clock_t& clock2)
{
	return double(clock1-clock2) / CLOCKS_PER_SEC;
}

int main() 
{
	cin.tie(0)->sync_with_stdio(0);
		cout.tie(0); // untie cin & cout
		double re_avg=0;
		double in_avg=0;
		double ma_avg=0;
		vector<double> re_time;
		vector<double> in_time;
		vector<double> ma_time;

		int t = 10;
		int kt = 3000;
		for (int i{0}; i != 10;++i)
		{
			clock_t begin = clock();
			long long k{1}; // move declaration of k outside of loop
			for(; k < kt ; k++) // remove k declaration from here
	        {
	            cout << "The side length of your cube: "<< k << "\n";
				cout << "Volume of cube with side "<< k << " is " << cube_regular(k) << "\n";
			}
			clock_t end = clock();
			double elapsed_secs = diffclock(end, begin);
			re_avg += elapsed_secs/t;
			re_time.push_back(elapsed_secs);
		}
		for (int i{0}; i != 10;++i)
		{
			clock_t begin = clock();
			long long k{1}; // move declaration of k outside of loop
			for(; k < kt ; k++) // remove k declaration from here
	        {
	            cout << "The side length of your cube: "<< k << "\n";
				cout << "Volume of cube with side "<< k << " is " << cube_inline(k) << "\n";
			}
			clock_t end = clock();
			double elapsed_secs = diffclock(end, begin);
			in_avg += elapsed_secs/t;
			in_time.push_back(elapsed_secs);
		}
		for (int i{0}; i != 10;++i)
		{
			clock_t begin = clock();
			long long k{1}; // move declaration of k outside of loop
			for(; k < kt ; k++) // remove k declaration from here
	        {
	            cout << "The side length of your cube: "<< k << "\n";
				cout << "Volume of cube with side "<< k << " is " << cube_macro(k) << "\n";
			}
			clock_t end = clock();
			double elapsed_secs = diffclock(end, begin);
			ma_avg += elapsed_secs/t;
			ma_time.push_back(elapsed_secs);
		}

		for (int i = 0; i < t;++i)
		{
			cout<<i<<"st run: "<<re_time[i]<<"seconds\n";
		}
		cout << "Then compute Avg_regular and you get the average of these 10 numbers =" << re_avg << "\n";
		for(int i = 0; i < t;++i)
		{
			cout<<i<<"st run: "<<in_time[i]<<"seconds\n";
		}
		cout << "Then compute Avg_inline and you get the average of these 10 numbers =" << in_avg << "\n";
		for(int i = 0; i < t;++i)
		{
			cout<<i<<"st run: "<<ma_time[i]<<"seconds\n";
		}
		cout << "Then compute Avg_macro and you get the average of these 10 numbers =" << ma_avg << "\n";
		return 0; 
}
