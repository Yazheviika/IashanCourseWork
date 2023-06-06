#include <string>
#include "Vehicle.h"

Vehicle::Vehicle(std::string vehicle_model,
	std::string vehicle_color,
	std::string vehicle_condition,
	std::string vehicle_engine_type,
	int vehicle_price,
	int vehicle_year_of_manufacture,
	int vehicle_mileage_in_km,
	int vehicle_seller_id)
	: model(vehicle_model),
	color(vehicle_color),
	condition(vehicle_condition),
	engine_type(vehicle_engine_type),
	price_in_UAH(vehicle_price),
	year_of_manufacture(vehicle_year_of_manufacture),
	mileage_in_km(vehicle_mileage_in_km),
	seller_id(vehicle_seller_id) { }


std::string Vehicle::getModel() const { return model; }

std::string Vehicle::getColor() const { return color; }

std::string Vehicle::getCondition() const { return condition; }

std::string Vehicle::getEngineType() const { return engine_type; }

int Vehicle::getPriceInUAH() const { return price_in_UAH; }

int Vehicle::getYearOfManufacture() const { return year_of_manufacture; }

int Vehicle::getMileageInKm() const { return mileage_in_km; }

int Vehicle::getSellerId() const { return seller_id; }

void Vehicle::setModel(std::string model) { this->model = model; }

void Vehicle::setColor(std::string color) { this->color = color; }

void Vehicle::setCondition(std::string condition) { this->condition = condition; }

void Vehicle::setEngineType(std::string engine_type) { this->engine_type = engine_type; }

void Vehicle::setPriceInUAH(int price) { this->price_in_UAH = price; }

void Vehicle::setYearOfManufacture(int year) { this->year_of_manufacture = year; }

void Vehicle::setMileageInKm(int mileage) { this->mileage_in_km = mileage; };

void Vehicle::setSellerId(int seller_id) { this->seller_id = seller_id; }

void Vehicle::deleteFromFile(std::string filename) const
{
	std::ifstream file_to_read(filename);
	std::ofstream temporary_file("Files/temp.txt");

	if (!file_to_read)
	{
		std::cerr << "File " << filename << " couldn`t be opened for reading.\n";
		exit(1);///////////
	}
	if (!temporary_file)
	{
		std::cerr << "Temporary file for copying data couldn`t be created.\n";
		exit(1);////////////
	}

	std::string vehicle;
	while (getline(file_to_read, vehicle))
	{
		std::istringstream stringAsStream(vehicle);
		std::string token;
		getline(stringAsStream, token, ':');

		std::string curr_id;
		getline(stringAsStream, curr_id, ',');

		if (std::stoi(curr_id) != getId())
			temporary_file << vehicle << '\n';
	}

	file_to_read.close();
	temporary_file.close();

	std::ofstream file_to_copy(filename, std::ios::trunc);
	std::ifstream file_to_copy_from("Files/temp.txt");

	if (!file_to_copy)
	{
		std::cerr << "File " << filename << " couldn`t be opened for writing.\n";
		exit(1);///////////
	}
	if (!file_to_copy_from)
	{
		std::cerr << "Temporary file for copying data couldn`t be created.\n";
		exit(1);////////////
	}

	while (getline(file_to_copy_from, vehicle))
		file_to_copy << vehicle << '\n';

	file_to_copy.close();
	file_to_copy_from.close();

	int Status = std::remove("Files/temp.txt");
	if (Status != 0)
		std::cerr << "Temporary file couldn`t be removed.\n";
}

void Vehicle::printBriefInformation()
{
	std::cout << "(Id: " << getId() << ") ";
	std::cout << "Vehicle: " << getModel() << " - " << getPriceInUAH() << " UAH" << std::endl;
}

void Vehicle::printAllInformation()
{
	std::cout << "Id: " << std::setw(17) << "" << getId() << std::endl;
	std::cout << "Model: " << std::setw(14) << "" << getModel() << std::endl;
	std::cout << "Price: " << std::setw(14) << "" << getPriceInUAH() << " UAH" << std::endl;
	std::cout << "Color: " << std::setw(14) << "" << getColor() << std::endl;
	std::cout << "Condition: " << std::setw(11) << "" << getCondition() << std::endl;
	std::cout << "Engine type: " << std::setw(9) << "" << getEngineType() << std::endl;
	std::cout << "Year of manufacture: " << "" << getYearOfManufacture() << std::endl;
	std::cout << "Mileage: " << std::setw(13) << "" << getMileageInKm() << " km" << std::endl;
}
