#include<stdio.h>
#include<stdlib.h>
int main(){
	int count = 0, sum = 0;
	scanf_s("%d", &count);
	for (int i = 1; i <= count; i++){
		int num1 = 0, num2 = 0;
        sum = 0;
        scanf_s("%d %d", &num1, &num2);
		for (int j = num1; j <= num2; j ++){
			if (j % 2 == 1){
				sum =sum+j;
			}
		}
		printf("Case %d: %d\n", i, sum);
	}

	//system("pause");
	return 0;
}