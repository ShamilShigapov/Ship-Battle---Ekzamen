#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include "Header.h"
using namespace std;




int main()
{
	system("chcp 1251 > nul");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	system("pause");

	game_manager();

	return 0;
}