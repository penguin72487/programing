#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	/*
	
	
	*/
	int dice[7][5];
	int i,j;
	for(i=1;i<=6;i++)
	{
		for(j=1;j<=4;j++)
		{
			dice[i][j]=i;
		}	
	}	
	int cmd;
	while(cin>>cmd&&cmd!=EOF)
	{
		switch(cmd)
		{
			int temp,temp2,temp3;
			case 1:
				
				swap(dice[1][1],dice[4][1]);
				swap(dice[4][1],dice[6][1]);
				swap(dice[6][1],dice[3][1]);
				
				
				
		
				swap(dice[1][4],dice[4][4]);
				swap(dice[4][4],dice[6][4]);
				swap(dice[6][4],dice[3][4]);
		
				
				
			
				swap(dice[2][1],dice[2][2]);
				swap(dice[2][2],dice[2][3]);
				swap(dice[2][3],dice[2][4]);
			
					//以下是輸出
				printf("    %d %d\n",dice[3][2],dice[3][1]);
				printf("    %d %d\n",dice[3][3],dice[3][4]);
				printf("%d %d %d %d %d %d %d %d\n",dice[5][2],dice[5][1],dice[1][2],dice[1][1],dice[2][2],dice[2][1],dice[6][2],dice[6][1]);
				printf("%d %d %d %d %d %d %d %d\n",dice[5][3],dice[5][4],dice[1][3],dice[1][4],dice[2][3],dice[2][4],dice[6][3],dice[6][4]);
				printf("    %d %d\n",dice[4][2],dice[4][1]);
				printf("    %d %d\n",dice[4][3],dice[4][4]);
			break;
			case 2:
				
				swap(dice[1][1],dice[2][1]);
				swap(dice[2][1],dice[6][1]);
				swap(dice[6][1],dice[5][1]);
			
				
				
			
				swap(dice[1][2],dice[2][2]);
				swap(dice[2][2],dice[6][2]);
				swap(dice[6][2],dice[5][2]);
			
				
			
				swap(dice[3][1],dice[3][2]);
				swap(dice[3][2],dice[3][3]);
				swap(dice[3][3],dice[3][4]);
				
				
				printf("    %d %d\n",dice[3][2],dice[3][1]);
				printf("    %d %d\n",dice[3][3],dice[3][4]);
				printf("%d %d %d %d %d %d %d %d\n",dice[5][2],dice[5][1],dice[1][2],dice[1][1],dice[2][2],dice[2][1],dice[6][2],dice[6][1]);
				printf("%d %d %d %d %d %d %d %d\n",dice[5][3],dice[5][4],dice[1][3],dice[1][4],dice[2][3],dice[2][4],dice[6][3],dice[6][4]);
				printf("    %d %d\n",dice[4][2],dice[4][1]);
				printf("    %d %d\n",dice[4][3],dice[4][4]);
			break;
			case 3:
				
				swap(dice[1][2],dice[3][2]);
				swap(dice[3][2],dice[6][2]);
				swap(dice[6][2],dice[4][2]);
				
				
				
				
				swap(dice[1][3],dice[3][3]);
				swap(dice[3][3],dice[6][3]);
				swap(dice[6][3],dice[4][3]);
				
				
				
				swap(dice[5][1],dice[5][2]);
				swap(dice[5][2],dice[5][3]);
				swap(dice[5][3],dice[5][4]);
				
				printf("    %d %d\n",dice[3][2],dice[3][1]);
				printf("    %d %d\n",dice[3][3],dice[3][4]);
				printf("%d %d %d %d %d %d %d %d\n",dice[5][2],dice[5][1],dice[1][2],dice[1][1],dice[2][2],dice[2][1],dice[6][2],dice[6][1]);
				printf("%d %d %d %d %d %d %d %d\n",dice[5][3],dice[5][4],dice[1][3],dice[1][4],dice[2][3],dice[2][4],dice[6][3],dice[6][4]);
				printf("    %d %d\n",dice[4][2],dice[4][1]);
				printf("    %d %d\n",dice[4][3],dice[4][4]);
			break;
			case 4:
				
				swap(dice[1][3],dice[5][3]);
				swap(dice[5][3],dice[6][3]);
				swap(dice[6][3],dice[2][3]);
			
				
				
			
				swap(dice[1][4],dice[5][4]);
				swap(dice[5][4],dice[6][4]);
				swap(dice[6][4],dice[2][4]);
			
				
			
				swap(dice[4][1],dice[4][2]);
				swap(dice[4][2],dice[4][3]);
				swap(dice[4][3],dice[4][4]);
				
				
				printf("    %d %d\n",dice[3][2],dice[3][1]);
				printf("    %d %d\n",dice[3][3],dice[3][4]);
				printf("%d %d %d %d %d %d %d %d\n",dice[5][2],dice[5][1],dice[1][2],dice[1][1],dice[2][2],dice[2][1],dice[6][2],dice[6][1]);
				printf("%d %d %d %d %d %d %d %d\n",dice[5][3],dice[5][4],dice[1][3],dice[1][4],dice[2][3],dice[2][4],dice[6][3],dice[6][4]);
				printf("    %d %d\n",dice[4][2],dice[4][1]);
				printf("    %d %d\n",dice[4][3],dice[4][4]);
			break;
			
		}
			
	}
	
	//以下是輸出
	printf("    %d %d\n",dice[1][2],dice[1][1]);
	printf("    %d %d\n",dice[1][3],dice[1][4]);
	
} 

