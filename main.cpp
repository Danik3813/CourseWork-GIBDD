#include "carbase.h"
#include "menu.h"
int main()
{
	setlocale(LC_ALL, "ru");
	CarBase car_base;
	Menu menu;
	menu.Start(menu, car_base);
}
