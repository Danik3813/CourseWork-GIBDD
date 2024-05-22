#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "car.h"
#include <algorithm>
class CarBase
{
private:
	std::vector<Car> car_base;
	std::string filename;
public:
	CarBase();
	std::vector<Car> GetCarBase() const;
	size_t GetSize() const;
	std::string GetFileName() const;
	void SaveToFile();
	void AllPrint() const;
	void PrintById(int car_id) const;
	void AddCar(Car car);
	void EditCar(int car_id, Car car);
	void DeleteCarById(int car_id);
	void Clear();
	void GetSorted(std::string field_name, char type);
};
