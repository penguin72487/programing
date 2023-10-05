#include <iostream>

int main(){
	int intarr_Num[5]={1, 2, 3, 4, 5};
	int* intptr_Num;
	intptr_Num= intarr_Num;
	
	std::cout<< &intarr_Num[0] << "\n";
	std::cout<< intptr_Num << "\n";
	std::cout<< &intptr_Num << "\n";
	std::cout<< *intptr_Num << "\n";
	std::cout<< *(intptr_Num+1) << "\n";
	return 0;
}
