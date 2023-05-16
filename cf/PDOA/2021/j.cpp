#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n, m, temp, flag, sum;
	vector<long long> a;
		scanf("%d", &m);
		for (long long j = 0; j < m; ++j) {
			scanf("%d", &temp);
			a.push_back(temp);
		}

		flag = 0;
		sum = 1;
		for (long long j = 1; j < m; ++j) {
			if (flag == 0 && a[j - 1] > a[j]) {
				++sum;
				flag = 1;
			}
			else if (flag == 1 && a[j - 1] < a[j]) {
				++sum;
				flag = 0;
			}
		}

		printf("%d\n", sum);
		a.clear();

	return 0;
}