#include<iostream>
using namespace std;
int main()
{
	int* p = new int ;//一個 
	delete p;
	
	
	
	int* it= new int [1000000000];//一為陣列 
	delete [] it;
	
	
	
	int** jt= new int* [10];//二維陣列10*10
	for(int i=0;i<10;i++)
	{
		*(jt+i)=new int [10];
	} 
	for(int i=0;i<10;i++)
	{
		delete [] *(jt+i);
	} 
	delete [] jt;
}

