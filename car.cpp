#include "car.h"

Car::Car(int car_id, std::string plate_number,\
	std::string name, std::string surname, std::string father_name,\
	std::string brand, std::string model, int mileage, int fines_quantity)
{
	this->car_id = car_id;
	this->plate_number = plate_number;
	this->name = name;
	this->surname = surname;
	this->father_name = father_name;
	this->brand = brand;
	this->model = model;
	this->mileage = mileage;
	this->fines_quantity = fines_quantity;
}

int Car::GetCarId() const
{
	return car_id;
}

void Car::SetCarId(int car_id)
{
	this->car_id = car_id;
}

std::string Car::GetPlateNumber() const
{
	return plate_number;
}

std::string Car::GetName() const
{
	return name;
}

std::string Car::GetSurname() const
{
	return surname;
}

std::string Car::GetFatherName() const
{
	return father_name;
}

std::string Car::GetBrand() const
{
	return brand;
}

std::string Car::GetModel() const
{
	return model;
}

int Car::GetMileage() const
{
	return mileage;
}

int Car::GetFinesQuantity() const
{
	return fines_quantity;
}
