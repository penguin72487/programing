#include<stdio.h>
int n[1000000] = {};
int main() {
    int i, j;

    int max = 0;
	scanf("%d %d", &i, &j);
	if (j < i) {
		int c;
		c = i;
		i = j;
		j = c;
	}
	for (int a = i; a <= j; a++) {
		while (true) {
			n[a]++;
			if (a == 1)
				break;
			else if (a % 2 == 0)
				a = a / 2;
			else
				a = 3 * a + 1;
		}
		if (n[a] > max)
			max = n[a];
	}
	printf("%d %d %d", i, j, max);
	return 0;
}