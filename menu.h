#pragma once
#pragma once
#include "carbase.h"
#include <string>
class Menu
{
private:
	std::string password;
	bool password_status;
public:
	Menu();
	void MenuName();
	void Start(Menu& menu, CarBase& car_base);
	void UserMenu(Menu& menu, CarBase& car_base);
	void AdminMenu(Menu& menu, CarBase& car_base);
	void AddInfo(Menu& menu, CarBase& car_base);
	void InputPassword(Menu& menu, CarBase& car_base);
	void ChangePassword(Menu& menu, CarBase& car_base);
	void SetColor(Menu& menu, const char* color);
	void ChangeColor(Menu& menu, CarBase& car_base, const char access);
	void MenuSort(Menu& menu, CarBase& car_base);
	void MenuTypeSort(Menu& menu, CarBase& car_base, std::string field_name);
	void Exit(CarBase& car_base);
};
