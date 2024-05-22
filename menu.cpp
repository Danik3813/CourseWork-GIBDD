#include "menu.h"
#include <iostream>
Menu::Menu()
{
	//Чтение пароля
	std::ifstream file;
	file.open("config/password.txt");
	std::getline(file, password);
	file.close();
	password_status = false;
	//Чтение цвета
	file.open("config/color.txt");
	std::string color;
	std::getline(file, color);
	file.close();
	const char* p_color = color.c_str();
	system(p_color);
}

void Menu::MenuName() {
	std::cout << "Список автомобилей, зарегистрированных в ГИБДД" << std::endl;
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
	std::cout << "Введите название файла (или путь файла): " << std::endl << ">> ";
	std::string filename;
	std::cin >> filename;
	CarBase car_base;
}*/

void Menu::Start(Menu& menu, CarBase& car_base) {
	system("cls");
	menu.MenuName();
	int choice;
	std::cout << "Выберите режим работы с данными:" << std::endl \
		<< "1. Пользователь" << std::endl << "2. Администратор" << std::endl << "3. Выход" << std::endl << ">> ";
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
	std::cout << "Режим работы: пользователь" << std::endl \
		<< "1. Вывести информацию о всех автомобилях" << std::endl << "2. Вывести информацию об одном автомобиле" << std::endl << "3. Изменить цветовую схему" \
		<< std::endl << "4. Назад" << std::endl << ">> ";
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
		std::cout << "Введите идентификатор" << std::endl << ">> ";
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
	std::string plate_number, name, surname, father_name, model;
	std::cout << "Режим работы: администратор" << std::endl << \
		"1. Вывести информацию о всех автомобилях" << std::endl << "2. Вывести информацию об одном автомобиле" << std::endl << \
		"3. Добавить автомобиль" << std::endl << "4. Редактировать информацию об автомобиле" << std::endl << "5. Изменить пароль" << \
		std::endl << "6. Удалить элемент по идентификатору" << std::endl << "7. Очистить список" << std::endl << "8. Отсортировать список" << std::endl << "9. Cохранить файл" << std::endl \
		<< "10. Изменить цветовую схему" << std::endl << "11. Назад" << std::endl << ">> ";
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
		std::cout << "Введите идентификатор" << std::endl << ">> ";
		std::cin >> car_id;
		car_base.PrintById(car_id);
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 3:
	{
		system("cls");
		std::cout << "Введите регистрационный номер: ";
		std::cin >> plate_number;
		std::cout << "Введите фамилию владельца: ";
		std::cin >> surname;
		std::cout << "Введите имя владельца: ";
		std::cin >> name;
		std::cout << "Введите отчество владельца: ";
		std::cin >> father_name;
		std::cout << "Введите модель автомобиля: ";
		std::cin >> model;
		std::cout << "Введите пробег автомобиля: ";
		std::cin >> mileage;
		std::cout << "Введите число полученных штрафов: ";
		std::cin >> fines_quantity;
		if (car_base.GetSize() == 0) {
			car_id = 1;
		}
		else {
			car_id = car_base.GetSize() + 1;
		}
		Car car(car_id, plate_number, name, surname, father_name, model, mileage, fines_quantity);
		car_base.AddCar(car);
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	}
	case 4: {
		system("cls");
		std::cout << "Введите идентификатор автомобиля: " << std::endl << ">> ";
		std::cin >> car_id;
		std::cout << "Старые данные об автомобиле" << std::endl;
		car_base.PrintById(car_id);
		std::cout << "Новые данные об автомобиле" << std::endl;
		std::cout << "Введите новый регистрационный номер: ";
		std::cin >> plate_number;
		std::cout << "Введите новую фамилию владельца: ";
		std::cin >> surname;
		std::cout << "Введите новое имя владельца: ";
		std::cin >> name;
		std::cout << "Введите новое отчество владельца: ";
		std::cin >> father_name;
		std::cout << "Введите новую модель автомобиля: ";
		std::cin >> model;
		std::cout << "Введите новый пробег автомобиля: ";
		std::cin >> mileage;
		std::cout << "Введите новое число полученных штрафов: ";
		std::cin >> fines_quantity;
		Car car(car_id, plate_number, name, surname, father_name, model, mileage, fines_quantity);
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
		std::cout << "Введите идентификатор" << std::endl << ">> ";
		std::cin >> car_id;
		car_base.DeleteCarById(car_id);
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 7:
		system("cls");
		car_base.Clear();
		std::cout << "Список очищен" << std::endl;
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 8:
		menu.MenuSort(menu, car_base);
		break;
	case 9:
		system("cls");
		car_base.SaveToFile();
		std::cout << "Список сохранен" << std::endl;
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 10:
		menu.ChangeColor(menu, car_base, 'A');
		break;
	case 11:
		menu.Start(menu, car_base);
		break;
	}
}

void Menu::InputPassword(Menu& menu, CarBase& car_base)
{
	system("cls");
	menu.MenuName();
	std::cout << "Введите пароль: " << std::endl << ">> ";
	std::string input_password;
	std::cin >> input_password;
	while (true) {
		if (password == input_password) { system("cls"); password_status = true; break; };
		std::cout << "Вы неверно ввели пароль, попробуйте снова (для выхода используйте quit): " << std::endl << ">> ";
		std::cin >> input_password;
		if (input_password == "quit") menu.Start(menu, car_base);
	}
}

void Menu::ChangePassword(Menu& menu, CarBase& car_base) 
{
	system("cls");
	menu.MenuName();
	std::string input_password;
	std::cout << "Введите стырый пароль: " << std::endl << ">> ";
	std::cin >> input_password;
	while (true)
	{
		if (password == input_password) { password_status = true; break; };
		std::cout << "Вы неверно ввели пароль, попробуйте снова (для выхода используйте quit): " << std::endl << ">> ";
		std::cin >> input_password;
		if (input_password == "quit") menu.AdminMenu(menu, car_base);
	}
	std::cout << "Введите новый пароль: " << std::endl << ">> ";
	std::cin >> input_password;
	password = input_password;
	std::ofstream file;
	file.open("config/password.txt");
	file << password;
	file.close();
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
	std::cout << "Выберите цветовую схему" << std::endl << "1. Черно-белая" << std::endl << "2. Черно-желтая" << std::endl << \
		"3. Бело-черная" << std::endl << "4. Бело-синяя" << std::endl << "5. Бело-зеленая" << std::endl << "6. Назад" << std::endl << ">> ";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		menu.SetColor(menu, "color 0F");
		system("cls");
		std::cout << "Цветовая схема изменена" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	case 2:
		menu.SetColor(menu, "color 06");
		system("cls");
		std::cout << "Цветовая схема изменена" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	case 3:
		menu.SetColor(menu, "color F0");
		system("cls");
		std::cout << "Цветовая схема изменена" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	case 4:
		menu.SetColor(menu, "color F1");
		system("cls");
		std::cout << "Цветовая схема изменена" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	case 5:
		menu.SetColor(menu, "color F2");
		system("cls");
		std::cout << "Цветовая схема изменена" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	case 6:
		if (access == 'A') menu.AdminMenu(menu, car_base);
		else menu.UserMenu(menu, car_base);
		break;
	}
}

void Menu::MenuSort(Menu& menu, CarBase& car_base)
{
	system("cls");
	menu.MenuName();
	std::cout << "Выберите поле сортировки" << std::endl << "1. Регистрационный номер" << std::endl << "2. Фамилия" << std::endl << "3. Имя" << std::endl << "4. Отчество"\
		<< std::endl << "5. Модель" << std::endl << "6. Пробег" << std::endl << "7. Число штрафов" << std::endl << "8. Назад" << std::endl << ">> ";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		menu.MenuTypeSort(menu, car_base, "plate_number");
		break;
	case 2:
		menu.MenuTypeSort(menu, car_base, "surname");
		break;
	case 3:
		menu.MenuTypeSort(menu, car_base, "name");
		break;
	case 4:
		menu.MenuTypeSort(menu, car_base, "father_name");
		break;
	case 5:
		menu.MenuTypeSort(menu, car_base, "model");
		break;
	case 6:
		menu.MenuTypeSort(menu, car_base, "mileage");
		break;
	case 7:
		menu.MenuTypeSort(menu, car_base, "fines_quantity");
		break;
	case 8:
		menu.AdminMenu(menu, car_base);
		break;
	}
}

void Menu::MenuTypeSort(Menu& menu, CarBase& car_base, std::string field_name)
{
	system("cls");
	std::cout << "Сортировка по полю" << field_name << std::endl << "1. По возрастанию" << std::endl << "2. По убыванию" << std::endl << \
		"3. Назад" << std::endl << ">> ";
	int choice;
	std::cin >> choice;
	CarBase sort_car_base = car_base;
	switch (choice)
	{
	case 1:
		sort_car_base.GetSorted(field_name, 'U');
		sort_car_base.AllPrint();
		system("pause");
		menu.MenuTypeSort(menu, car_base, field_name);
		break;
	case 2:
		sort_car_base.GetSorted(field_name, 'L');
		sort_car_base.AllPrint();
		system("pause");
		menu.MenuTypeSort(menu, car_base, field_name);
		break;
	case 3:
		menu.MenuSort(menu, car_base);
		break;
	}
}
