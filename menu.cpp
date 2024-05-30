#include "menu.h"
#include <iostream>
//глобальные переменные
int choice, car_id, mileage, fines_quantity;
std::string input_choice, input_car_id, plate_number,\
name, surname, father_name,\
brand, model,\
input_password, input_mileage, input_fines_quantity;

Menu::Menu()
{
	//Чтение пароля
	std::fstream file("config/password.txt");
	file.open("password.txt");
	std::getline(file, password);
	if (password.length() == 0) 
	{
		password = "adm";
		file << password;
	}
	file.close();
	password_status = false;
	//Чтение цвета
	file.open("config/color.txt");
	std::string color;
	std::getline(file, color);
	if (color.length() == 0)
	{
		color = "color 0F";
		file << color;
	}
	file.close();
	const char* p_color = color.c_str();
	system(p_color);
}

void Menu::MenuName() {
	std::cout << "Список автомобилей, зарегистрированных в ГИБДД" << std::endl;
}

void Menu::Start(Menu& menu, CarBase& car_base) {
	system("cls");
	menu.MenuName();
	std::cout << "Выберите режим работы с данными:" << std::endl \
		<< "1. Пользователь" << std::endl << "2. Администратор" << std::endl << "3. Выход" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "Вы ввели не число!" << std::endl;
		system("pause");
		menu.Start(menu, car_base);
	}
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
	default:
		system("cls");
		std::cout << "Нет такой команды!" << std::endl;
		system("pause");
		menu.Start(menu, car_base);
		break;
	}
}

void Menu::UserMenu(Menu& menu, CarBase& car_base)
{
	system("cls");
	car_id = -1;
	std::cout << "Режим работы: пользователь" << std::endl \
		<< "1. Вывести информацию о всех автомобилях" << std::endl << "2. Вывести информацию об одном автомобиле" << std::endl << "3. Изменить цветовую схему" \
		<< std::endl << "4. Назад" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "Вы ввели не число!" << std::endl;
		system("pause");
		menu.UserMenu(menu, car_base);
	}
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
		std::cin >> input_car_id;
		try
		{
			car_id = stoi(input_car_id);
		}
		catch (std::exception ex)
		{
			std::cout << "Вы ввели не число!" << std::endl;
		}
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
	default:
		system("cls");
		std::cout << "Нет такой команды!" << std::endl;
		system("pause");
		menu.UserMenu(menu, car_base);
		break;
	}
}

void Menu::AdminMenu(Menu& menu, CarBase& car_base) 
{
	system("cls");
	if (password_status == false) { menu.InputPassword(menu, car_base); };
	menu.MenuName();
	std::cout << "Режим работы: администратор" << std::endl << \
		"1. Вывести информацию о всех автомобилях" << std::endl << "2. Вывести информацию об одном автомобиле" << std::endl << \
		"3. Добавить автомобиль" << std::endl << "4. Редактировать информацию об автомобиле" << std::endl << "5. Изменить пароль" << \
		std::endl << "6. Удалить элемент по идентификатору" << std::endl << "7. Очистить список" << std::endl << "8. Отсортировать список" << std::endl << "9. Cохранить файл" << std::endl \
		<< "10. Изменить цветовую схему" << std::endl << "11. Назад" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "Вы ввели не число!" << std::endl;
		system("pause");
		menu.AdminMenu(menu, car_base);
	}
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
		std::cin >> input_car_id;
		try
		{
			car_id = stoi(input_car_id);
		}
		catch (std::exception ex)
		{
			std::cout << "Вы ввели не число!" << std::endl;
		}
		car_base.PrintById(car_id);
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	case 3:
	{
		system("cls");
		menu.AddInfo(menu, car_base);
		if (car_base.GetSize() == 0) {
			car_id = 1;
		}
		else {
			car_id = car_base.GetSize() + 1;
		}
		Car car(car_id, plate_number, name, surname, father_name, brand, model, mileage, fines_quantity);
		car_base.AddCar(car);
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	}
	case 4: {
		system("cls");
		car_id = -1;
		std::cout << "Введите идентификатор автомобиля: " << std::endl << ">> ";
		std::cin >> input_car_id;
		try
		{
			car_id = stoi(input_car_id);
		}
		catch (std::exception ex)
		{
			std::cout << "Вы ввели не число!" << std::endl;
			system("pause");
		}
		if (car_id == -1) menu.AdminMenu(menu, car_base);
		std::cout << "Старые данные об автомобиле" << std::endl;
		car_base.PrintById(car_id);
		std::cout << "Новые данные об автомобиле" << std::endl;
		menu.AddInfo(menu, car_base);
		Car car(car_id, plate_number, name, surname, father_name, brand, model, mileage, fines_quantity);
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
		car_id = -1;
		std::cout << "Введите идентификатор" << std::endl << ">> ";
		std::cin >> input_car_id;
		try
		{
			car_id = stoi(input_car_id);
		}
		catch (std::exception ex)
		{
			std::cout << "Вы ввели не число!" << std::endl;
			system("pause");
		}
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
	default:
		system("cls");
		std::cout << "Нет такой команды!" << std::endl;
		system("pause");
		menu.AdminMenu(menu, car_base);
		break;
	}
}

void Menu::AddInfo(Menu& menu, CarBase& car_base)
{
	std::cout << "При необходимости используйте quit для предварительного выхода" << std::endl;
	std::cout << "Введите регистрационный номер: " << std::endl << ">> ";
	std::cin >> plate_number;
	if (plate_number == "quit") menu.AdminMenu(menu, car_base);
	std::cout << "Введите фамилию владельца: " << std::endl << ">> ";;
	std::cin >> surname;
	if (surname == "quit") menu.AdminMenu(menu, car_base);
	std::cout << "Введите имя владельца: " << std::endl << ">> ";;
	std::cin >> name;
	if (name == "quit") menu.AdminMenu(menu, car_base);
	std::cout << "Введите отчество владельца: " << std::endl << ">> ";;
	std::cin >> father_name;
	if (father_name == "quit") menu.AdminMenu(menu, car_base);
	std::cout << "Введите марку автомобиля: " << std::endl << ">> ";;
	std::cin >> brand;
	if (brand == "quit") menu.AdminMenu(menu, car_base);
	std::cout << "Введите модель автомобиля: " << std::endl << ">> ";;
	std::cin >> model;
	if (model == "quit") menu.AdminMenu(menu, car_base);
	std::cout << "Введите пробег автомобиля: " << std::endl << ">> ";;
	std::cin >> input_mileage;
	if (input_mileage == "quit") menu.AdminMenu(menu, car_base);
	try
	{
		mileage = stoi(input_mileage);
	}
	catch (std::exception ex)
	{
		std::cout << "Вы ввели не число!" << std::endl;
		system("pause");
		menu.AdminMenu(menu, car_base);
	}
	std::cout << "Введите число полученных штрафов: " << std::endl << ">> ";
	std::cin >> input_fines_quantity;
	try
	{
		fines_quantity = stoi(input_fines_quantity);
	}
	catch (std::exception ex)
	{
		std::cout << "Вы ввели не число!" << std::endl;
		system("pause");
		menu.AdminMenu(menu, car_base);
	}
}

void Menu::InputPassword(Menu& menu, CarBase& car_base)
{
	system("cls");
	menu.MenuName();
	std::cout << "Введите пароль: " << std::endl << ">> ";
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
	std::cout << "Введите стырый пароль: " << std::endl << ">> ";
	std::cin >> input_password;
	while (true)
	{
		if (password == input_password) { password_status = false; break; };
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
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "Вы ввели не число!" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
	}
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
	default:
		system("cls");
		std::cout << "Нет такой команды!" << std::endl;
		system("pause");
		menu.ChangeColor(menu, car_base, access);
		break;
	}
}

void Menu::MenuSort(Menu& menu, CarBase& car_base)
{
	system("cls");
	menu.MenuName();
	std::cout << "Выберите поле сортировки"\
		<< std::endl << "1. Регистрационный номер" << std::endl << "2. Фамилия"\
		<< std::endl << "3. Имя" << std::endl << "4. Отчество"\
		<< std::endl << "5. Марка" << std::endl << "6. Модель" << std::endl << "7. Пробег"\
		<< std::endl << "8. Число штрафов" << std::endl << "9. Назад" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "Вы ввели не число!" << std::endl;
		system("pause");
		menu.MenuSort(menu, car_base);
	}
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
		menu.MenuTypeSort(menu, car_base, "brand");
	case 6:
		menu.MenuTypeSort(menu, car_base, "model");
		break;
	case 7:
		menu.MenuTypeSort(menu, car_base, "mileage");
		break;
	case 8:
		menu.MenuTypeSort(menu, car_base, "fines_quantity");
		break;
	case 9:
		menu.AdminMenu(menu, car_base);
		break;
	default:
		system("cls");
		std::cout << "Нет такой команды!" << std::endl;
		system("pause");
		menu.MenuSort(menu, car_base);
		break;
	}
}

void Menu::MenuTypeSort(Menu& menu, CarBase& car_base, std::string field_name)
{
	system("cls");
	std::cout << "Сортировка по полю: "\
		<< field_name << std::endl <<\
		"1. По возрастанию" << std::endl << "2. По убыванию"\
		<< std::endl << "3. Назад" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "Вы ввели не число!" << std::endl;
		system("pause");
		menu.MenuTypeSort(menu, car_base, field_name);
	}
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
	default:
		system("cls");
		std::cout << "Нет такой команды!" << std::endl;
		system("pause");
		menu.MenuTypeSort(menu, car_base, field_name);
		break;
	}
}

void Menu::Exit(CarBase& car_base)
{
	car_base.SaveToFile();
	exit(0);
}
