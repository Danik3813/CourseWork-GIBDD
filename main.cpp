#include "carbase.h"
#include "menu.h"
#include "Windows.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CarBase car_base;
	Menu menu;
	menu.Start(menu, car_base);
}
