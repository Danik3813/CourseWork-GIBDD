#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "car.h"
class CarBase
{
private:
	std::vector<Car> car_base;
	std::string password;
	std::string filename;
public:
	CarBase();
	size_t GetSize() const;
	std::string GetFileName() const;
	std::string GetPassword() const;
	void SetPassword(std::string password);
	void SaveToFile();
	void AllPrint() const;
	void PrintById(int car_id) const;
	void AddCar(Car car);
	void EditCar(int car_id, Car car);
	void DeleteCarById(int car_id);
	void Clear();
};
