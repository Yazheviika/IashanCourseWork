#include <string>
#include "Vehicle.h"

Vehicle::Vehicle(std::string vehicle_model,
	std::string vehicle_color,
	std::string vehicle_condition,
	std::string vehicle_engine_type,
	int vehicle_price,
	int vehicle_year_of_manufacture,
	int vehicle_mileage_in_km)
	: model(vehicle_model),
	color(vehicle_color),
	condition(vehicle_condition),
	engine_type(vehicle_engine_type),
	price_in_UAH(vehicle_price),
	year_of_manufacture(vehicle_year_of_manufacture),
	mileage_in_km(vehicle_mileage_in_km) { }


std::string Vehicle::getModel() const { return model; }

std::string Vehicle::getColor() const { return color; }

std::string Vehicle::getCondition() const { return condition; }

std::string Vehicle::getEngineType() const { return engine_type; }

int Vehicle::getPriceInUAH() const { return price_in_UAH; }

int Vehicle::getYearOfManufacture() const { return year_of_manufacture; }

int Vehicle::getMileageInKm() const { return mileage_in_km; }

void Vehicle::setModel(std::string model) { this->model = model; }

void Vehicle::setColor(std::string color) { this->color = color; }

void Vehicle::setCondition(std::string condition) { this->condition = condition; }

void Vehicle::setEngineType(std::string engine_type) { this->engine_type = engine_type; }

void Vehicle::setPriceInUAH(int price) { this->price_in_UAH = price; }

void Vehicle::setYearOfManufacture(int year) { this->year_of_manufacture = year; }

void Vehicle::setMileageInKm(int mileage) { this->mileage_in_km = mileage; };

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
