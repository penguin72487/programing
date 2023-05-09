#include<iostream>

using namespace std;

int main(){
	cout << "hellow";
	return 0;
} 
//g++ test.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system
//g++ test.cpp -o test -I<C:\SFML-2.5.1\include> -L<C:\SFML-2.5.1\lib> -lsfml-graphics -lsfml-window -lsfml-system
cd NUK\HW
clang++ test.cpp -o test.exe -Wall -g -Og -static-libgcc -fcolor-diagnostics --target=x86_64-w64-mingw -std=c++17 -std=c++2a -I C:/SFML-2.5.1/include -L C:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
./test

