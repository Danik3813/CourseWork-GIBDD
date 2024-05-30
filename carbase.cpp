#include "carbase.h"
CarBase::CarBase()
{
	filename = "carbase.csv";
	int car_id, mileage, fines_quantity;
	std::string plate_number, name, surname,\
		father_name, model, brand;
	std::ifstream file;
	file.open(filename);
	std::string car_line;
	try 
	{
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
				surname = str_part;

				std::getline(car_stream, str_part, ';');
				name = str_part;

				std::getline(car_stream, str_part, ';');
				father_name = str_part;

				std::getline(car_stream, str_part, ';');
				brand = str_part;

				std::getline(car_stream, str_part, ';');
				model = str_part;

				std::getline(car_stream, str_part, ';');
				mileage = stoi(str_part);

				std::getline(car_stream, str_part, ';');
				fines_quantity = stoi(str_part);
				Car car(car_id, plate_number, name, surname, father_name, brand, model, mileage, fines_quantity);
				car_base.push_back(car);
			}
		}
	}
	catch (std::exception ex)
	{
		std::cout << "Проблемы со считыванием. " <<\
			"Программа аварийно остановлена!" << std::endl;
		system("pause");
		exit(0);
	}
	file.close();
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
			car_base[i].GetSurname() + ";" + \
			car_base[i].GetName() + ";" + \
			car_base[i].GetFatherName() + ";" + \
			car_base[i].GetBrand() + ";" + \
			car_base[i].GetModel() + ";" + \
			std::to_string(car_base[i].GetMileage()) + ";" + \
			std::to_string(car_base[i].GetFinesQuantity()) << std::endl;
	}
	file.close();
}

void CarBase::AllPrint() const
{
	for (int i = 0; i < car_base.size(); i++)
	{
		std::cout << car_base[i].GetCarId() << " " << \
			car_base[i].GetPlateNumber() << " " << \
			car_base[i].GetSurname() << " " << \
			car_base[i].GetName() << " " << \
			car_base[i].GetFatherName() << " " << \
			car_base[i].GetBrand() << " " << \
			car_base[i].GetModel() << " " << \
			car_base[i].GetMileage() << " " << \
			car_base[i].GetFinesQuantity() << std::endl;
	}
}

void CarBase::PrintById(int car_id) const
{
	for (int i = 0; i < car_base.size(); i++)
	{
		if (car_id == -1) break;
		if (car_base[i].GetCarId() == car_id)
		{
			std::cout << car_base[i].GetCarId() << " " << \
				car_base[i].GetPlateNumber() << " " << \
				car_base[i].GetSurname() << " " << \
				car_base[i].GetName() << " " << \
				car_base[i].GetFatherName() << " " << \
				car_base[i].GetBrand() << " " << \
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

//логические функции для сортировки
static bool sortByPlateNumberUpper(const Car left, const Car right)
{
	return left.GetPlateNumber() < right.GetPlateNumber();
}

static bool sortByPlateNumberLower(const Car left, const Car right)
{
	return left.GetPlateNumber() > right.GetPlateNumber();
}

static bool sortByNameUpper(const Car left, const Car right)
{
	return left.GetName() < right.GetName();
}

static bool sortByNameLower(const Car left, const Car right)
{
	return left.GetName() > right.GetName();
}

static bool sortBySurnameUpper(const Car left, const Car right)
{
	return left.GetSurname() < right.GetSurname();
}

static bool sortBySurnameLower(const Car left, const Car right)
{
	return left.GetSurname() > right.GetSurname();
}

static bool sortByFatherNameUpper(const Car left, const Car right)
{
	return left.GetFatherName() < right.GetFatherName();
}

static bool sortByFatherNameLower(const Car left, const Car right)
{
	return left.GetFatherName() > right.GetFatherName();
}

static bool sortByBrandUpper(const Car left, const Car right)
{
	return left.GetBrand() < right.GetBrand();
}

static bool sortByBrandLower(const Car left, const Car right)
{
	return left.GetBrand() > right.GetBrand();
}

static bool sortByModelUpper(const Car left, const Car right)
{
	return left.GetModel() < right.GetModel();
}

static bool sortByModelLower(const Car left, const Car right)
{
	return left.GetModel() > right.GetModel();
}

static bool sortByMileageUpper(const Car left, const Car right)
{
	return left.GetMileage() < right.GetMileage();
}

static bool sortByMileageLower(const Car left, const Car right)
{
	return left.GetMileage() > right.GetMileage();
}

static bool sortByFinesQuantityUpper(const Car left, const Car right)
{
	return left.GetFinesQuantity() < right.GetFinesQuantity();
}

static bool sortByFinesQuantityLower(const Car left, const Car right)
{
	return left.GetFinesQuantity() > right.GetFinesQuantity();
}

void CarBase::GetSorted(std::string field_name, char type)
{
	if (field_name == "plate_number" && type == 'U')
	{
		std::sort(begin(car_base), end(car_base), sortByPlateNumberUpper);
	}

	if (field_name == "plate_number" && type == 'L')
	{
		std::sort(begin(car_base), end(car_base), sortByPlateNumberLower);
	}

	if (field_name == "name" && type == 'U')
	{
		std::sort(begin(car_base), end(car_base), sortByNameUpper);
	}

	if (field_name == "name" && type == 'L')
	{
		std::sort(begin(car_base), end(car_base), sortByNameLower);
	}

	if (field_name == "surname" && type == 'U')
	{
		std::sort(begin(car_base), end(car_base), sortBySurnameUpper);
	}

	if (field_name == "surname" && type == 'L')
	{
		std::sort(begin(car_base), end(car_base), sortBySurnameLower);
	}

	if (field_name == "father_name" && type == 'U')
	{
		std::sort(begin(car_base), end(car_base), sortByFatherNameUpper);
	}

	if (field_name == "father_name" && type == 'L')
	{
		std::sort(begin(car_base), end(car_base), sortByFatherNameLower);
	}

	if (field_name == "brand" && type == 'U')
	{
		std::sort(begin(car_base), end(car_base), sortByBrandUpper);
	}

	if (field_name == "brand" && type == 'L')
	{
		std::sort(begin(car_base), end(car_base), sortByBrandLower);
	}

	if (field_name == "model" && type == 'U')
	{
		std::sort(begin(car_base), end(car_base), sortByModelUpper);
	}

	if (field_name == "model" && type == 'L')
	{
		std::sort(begin(car_base), end(car_base), sortByModelLower);
	}

	if (field_name == "mileage" && type == 'U')
	{
		std::sort(begin(car_base), end(car_base), sortByMileageUpper);
	}

	if (field_name == "mileage" && type == 'L')
	{
		std::sort(begin(car_base), end(car_base), sortByMileageLower);
	}

	if (field_name == "fines_quantity" && type == 'U')
	{
		std::sort(begin(car_base), end(car_base), sortByFinesQuantityUpper);
	}

	if (field_name == "fines_quantity" && type == 'L')
	{
		std::sort(begin(car_base), end(car_base), sortByFinesQuantityLower);
	}
}