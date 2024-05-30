#pragma once
#include <string>
class Car
{
private:
	int car_id;
	std::string plate_number;
	std::string name;
	std::string surname;
	std::string father_name;
	std::string brand;
	std::string model;
	int mileage;
	int fines_quantity;
public:
	Car(int car_id, std::string plate_number,\
		std::string name, std::string surname,\
		std::string father_name,\
		std::string brand, std::string model,\
		int mileage, int fines_quantity);
	int GetCarId() const;
	void SetCarId(int car_id);
	std::string GetPlateNumber() const;
	std::string GetName() const;
	std::string GetSurname() const;
	std::string GetFatherName() const;
	std::string GetBrand() const;
	std::string GetModel() const;
	int GetMileage() const;
	int GetFinesQuantity() const;
};

