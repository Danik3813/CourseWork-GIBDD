#include "carbase.h"
CarBase::CarBase()
{
	filename = "carbase.csv";
	int car_id, mileage, fines_quantity;
	std::string plate_number, human_name, model;
	std::ifstream file;
	file.open(filename);
	std::string car_line;
	if (file.is_open()) {
		while (std::getline(file, car_line))
		{
			std::stringstream car_stream(car_line);
			std::string str_part;
			std::getline(car_stream, str_part, ';');
			car_id = stoi(str_part);
			std::getline(car_stream, str_part, ';');
			plate_number = str_part;
			std::getline(car_stream, str_part, ';');
			human_name = str_part;
			std::getline(car_stream, str_part, ';');
			model = str_part;
			std::getline(car_stream, str_part, ';');
			mileage = stoi(str_part);
			std::getline(car_stream, str_part, ';');
			fines_quantity = stoi(str_part);
			Car car(car_id, plate_number, human_name, model, mileage, fines_quantity);
			car_base.push_back(car);
		}
	}
	file.close();
	//file.open("password.txt");
	//std::getline(file, password);
	//file.close();
}

size_t CarBase::GetSize() const
{
	return car_base.size();
}

std::string CarBase::GetFileName() const
{
	return filename;
}

void CarBase::SaveToFile()
{
	std::ofstream file;
	file.open(filename);
	for (int i = 0; i < car_base.size(); i++)
	{
		file << std::to_string(car_base[i].GetCarId()) + ";" + \
			car_base[i].GetPlateNumber() + ";" + \
			car_base[i].GetHumanName() + ";" + \
			car_base[i].GetModel() + ";" + \
			std::to_string(car_base[i].GetMileage()) + ";" + \
			std::to_string(car_base[i].GetFinesQuantity());
	}
	file.close();
}

void CarBase::AllPrint() const
{
	for (int i = 0; i < car_base.size(); i++)
	{
		std::cout << car_base[i].GetCarId() << " " << \
			car_base[i].GetPlateNumber() << " " << \
			car_base[i].GetHumanName() << " " << \
			car_base[i].GetModel() << " " << \
			car_base[i].GetMileage() << " " << \
			car_base[i].GetFinesQuantity() << std::endl;
	}
}

void CarBase::PrintById(int car_id) const
{
	for (int i = 0; i < car_base.size(); i++)
	{
		if (car_base[i].GetCarId() == car_id)
		{
			std::cout << car_base[i].GetCarId() << " " << \
				car_base[i].GetPlateNumber() << " " << \
				car_base[i].GetHumanName() << " " << \
				car_base[i].GetModel() << " " << \
				car_base[i].GetMileage() << " " << \
				car_base[i].GetFinesQuantity() << std::endl;
		}
	}
}

void CarBase::AddCar(Car car)
{
	car_base.push_back(car);
}

void CarBase::EditCar(int car_id, Car car)
{
	for (int i = 0; i < car_base.size(); i++)
	{
		if (car_id == car_base[i].GetCarId()) car_base[i] = car;
	}
}

void CarBase::DeleteCarById(int car_id)
{
	car_base.erase(car_base.begin() + car_id - 1);
	for (int i = 0; i < car_base.size(); i++)
	{
		car_base[i].SetCarId(i + 1);
	}
}

void CarBase::Clear()
{
	car_base.clear();
}
