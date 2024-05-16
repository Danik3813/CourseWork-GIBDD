#pragma once
#include <string>
class Car
{
private:
	int car_id;
	std::string plate_number;
	std::string human_name;
	std::string model;
	int mileage;
	int fines_quantity;
public:
	Car(int car_id, std::string plate_number, std::string human_name, std::string model, int mileage, int fines_quantity);
	int GetCarId() const;
	void SetCarId(int car_id);
	std::string GetPlateNumber() const;
	std::string GetHumanName() const;
	std::string GetModel() const;
	int GetMileage() const;
	int GetFinesQuantity() const;
};
