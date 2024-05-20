#include "menu.h"
#include <iostream>
Menu::Menu()
{
	//������ ������
	std::ifstream file;
	file.open("config/password.txt");
	std::getline(file, password);
	file.close();
	password_status = false;
	//������ �����
	file.open("config/color.txt");
	std::string color;
	std::getline(file, color);
	file.close();
	const char* p_color = color.c_str();
	system(p_color);
}

void Menu::MenuName() {
	std::cout << "������ �����������, ������������������ � �����" << std::endl;
}

/*
void Menu::App(Menu &menu)
{
	menu.MenuName();
	menu.SetFileName();
}

void Menu::SetFileName()
{
	system("cls");
	std::cout << "������� �������� ����� (��� ���� �����): " << std::endl << ">> ";
	std::string filename;
	std::cin >> filename;
	CarBase car_base;
}*/

void Menu::Start(Menu& menu, CarBase& car_base) {
	system("cls");
	menu.MenuName();
	int choice;
	std::cout << "�������� ����� ������ � �������:" << std::endl \
		<< "1. ������������" << std::endl << "2. �������������" << std::endl << "3. �����" << std::endl << ">> ";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		menu.UserMenu(menu, car_base);
		break;
	case 2:
		menu.AdminMenu(menu, car_base);
		break;
	case 3:
		menu.Exit(car_base);
		break;
	}
}

void Menu::UserMenu(Menu& menu, CarBase& car_base)
{
	system("cls");
	int choice, car_id;
	std::cout << "����� ������: ������������" << std::endl \
		<< "1. ������� ���������� � ���� �����������" << std::endl << "2. ������� ���������� �� ����� ����������" << std::endl << "3. �������� �������� �����" \
		<< std::endl << "4. �����" << std::endl << ">> ";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		car_base.AllPrint();
		system("pause");
		menu.UserMenu(menu, car_base);
		break;
	case 2:
		system("cls");
		std::cout << "������� �������������" << std::endl << ">> ";
		std::cin >> car_id;
		car_base.PrintById(car_id);
		system("pause");
		menu.UserMenu(menu, car_base);
		break;
	case 3:
		menu.ChangeColor(menu, car_base, 'U');
		break;
	case 4:
		menu.Start(menu, car_base);
		break;
	}
}

void Menu::Exit(CarBase& car_base)
{
	car_base.SaveToFile();
	exit(0);
}

void Menu::AdminMenu(Menu& menu, CarBase& car_base)
{
	system("cls");
	if (password_status == false) { menu.InputPassword(menu, car_base); };
	menu.MenuName();
	int choice, car_id, mileage, fines_quantity;
	std::string plate_number, human_name, model;
	std::cout << "����� ������: �������������" << std::endl << \
		"1. ������� ���������� � ���� �����������" << std::endl << "2. ������� ���������� �� ����� ����������" << std::endl << \
		"3. �������� ����������" << std::endl << "4. ������������� ���������� �� ����������" << std::endl << "5. �������� ������" << \
		std::endl << "6. ������� ������� �� ��������������" << std::endl << "7. �������� ������" << std::endl << "8. C�������� ����" << std::endl \
		<< "9. �������� �������� �����" << std::endl << "10. �����" << std::endl << ">> ";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		car_base.AllPrint();
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 2:
		system("cls");
		std::cout << "������� �������������" << std::endl << ">> ";
		std::cin >> car_id;
		car_base.PrintById(car_id);
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 3:
	{
		system("cls");
		std::cout << "������� ��������������� �����: ";
		std::cin >> plate_number;
		std::cout << "������� �.�.� ���������: ";
		std::cin >> human_name;
		std::cout << "������� ������ ����������: ";
		std::cin >> model;
		std::cout << "������� ������ ����������: ";
		std::cin >> mileage;
		std::cout << "������� ����� ���������� �������: ";
		std::cin >> fines_quantity;
		if (car_base.GetSize() == 0) {
			car_id = 1;
		}
		else {
			car_id = car_base.GetSize() + 1;
		}
		Car car(car_id, plate_number, human_name, model, mileage, fines_quantity);
		car_base.AddCar(car);
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	}
	case 4: {
		system("cls");
		std::cout << "������� ������������� ����������: " << std::endl << ">> ";
		std::cin >> car_id;
		std::cout << "������ ������ �� ����������" << std::endl;
		car_base.PrintById(car_id);
		std::cout << "����� ������ �� ����������" << std::endl;
		std::cout << "������� ����� ��������������� �����: ";
		std::cin >> plate_number;
		std::cout << "������� ����� �.�.� ���������: ";
		std::cin >> human_name;
		std::cout << "������� ����� ������ ����������: ";
		std::cin >> model;
		std::cout << "������� ����� ������ ����������: ";
		std::cin >> mileage;
		std::cout << "������� ����� ����� ���������� �������: ";
		std::cin >> fines_quantity;
		Car car(car_id, plate_number, human_name, model, mileage, fines_quantity);
		car_base.EditCar(car_id, car);
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	}
	case 5:
		menu.ChangePassword(menu, car_base);
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 6:
		system("cls");
		std::cout << "������� �������������" << std::endl << ">> ";
		std::cin >> car_id;
		car_base.DeleteCarById(car_id);
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 7:
		system("cls");
		car_base.Clear();
		std::cout << "������ ������" << std::endl;
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 8:
		system("cls");
		car_base.SaveToFile();
		std::cout << "������ ��������" << std::endl;
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 9:
		menu.ChangeColor(menu, car_base, 'A');
		break;
	case 10:
		menu.Start(menu, car_base);
		break;
	}
}

void Menu::InputPassword(Menu& menu, CarBase& car_base)
{
	system("cls");
	menu.MenuName();
	std::cout << "������� ������: " << std::endl << ">> ";
	std::string input_password;
	std::cin >> input_password;
	while (true) {
		if (password == input_password) { system("cls"); password_status = true; break; };
		std::cout << "�� ������� ����� ������, ���������� ����� (��� ������ ����������� quit): " << std::endl << ">> ";
		std::cin >> input_password;
		if (input_password == "quit") menu.Start(menu, car_base);
	}
}

void Menu::ChangePassword(Menu& menu, CarBase& car_base)
{
	system("cls");
	menu.MenuName();
	std::string input_password;
	std::cout << "������� ������ ������: " << std::endl << ">> ";
	std::cin >> input_password;
	while (true)
	{
		if (password == input_password) { password_status = true; break; };
		std::cout << "�� ������� ����� ������, ���������� ����� (��� ������ ����������� quit): " << std::endl << ">> ";
		std::cin >> input_password;
		if (input_password == "quit") menu.AdminMenu(menu, car_base);
	}
	std::cout << "������� ����� ������: " << std::endl << ">> ";
	std::cin >> input_password;
	password = input_password;
}

void Menu::SetColor(Menu& menu, const char* color)
{
	system(color);
	std::ofstream file;
	file.open("config/color.txt");
	file << color;
	file.close();
}

void Menu::ChangeColor(Menu& menu, CarBase& car_base, const char access)
{
	system("cls");
	std::cout << "�������� �������� �����" << std::endl << "1. �����-�����" << std::endl << "2. �����-������" << std::endl << \
		"3. ����-������" << std::endl << "4. ����-�����" << std::endl << "5. ����-�������" << std::endl << "6. �����" << std::endl << ">> ";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		menu.SetColor(menu, "color 0F");
		system("cls");
		std::cout << "�������� ����� ��������" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	case 2:
		menu.SetColor(menu, "color 06");
		system("cls");
		std::cout << "�������� ����� ��������" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	case 3:
		menu.SetColor(menu, "color F0");
		system("cls");
		std::cout << "�������� ����� ��������" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	case 4:
		menu.SetColor(menu, "color F1");
		system("cls");
		std::cout << "�������� ����� ��������" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	case 5:
		menu.SetColor(menu, "color F2");
		system("cls");
		std::cout << "�������� ����� ��������" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	case 6:
		if (access == 'A') menu.AdminMenu(menu, car_base);
		else menu.UserMenu(menu, car_base);
		break;
	}
}
