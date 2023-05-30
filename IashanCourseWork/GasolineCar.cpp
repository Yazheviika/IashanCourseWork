#include "GasolineCar.h"

GasolineCar::GasolineCar(std::string car_model,
	std::string car_color,
	std::string car_condition,
	std::string car_engine_type,
	int car_price,
	int car_year_of_manufacture,
	int car_mileage_in_km,
	bool car_body,
	std::string car_aditional_facilities,
	std::string car_fuel_type,
	int car_fuel_mileage)
	: Car(car_model,
		car_color,
		car_condition,
		car_engine_type,
		car_price,
		car_year_of_manufacture,
		car_mileage_in_km,
		car_body,
		car_aditional_facilities),
	fuel_type(car_fuel_type),
	fuel_mileage_per_100km(car_fuel_mileage) { }

int GasolineCar::getFuelMileagePer100Km() const { return fuel_mileage_per_100km; }

std::string GasolineCar::getFuelType() const { return fuel_type; }

void GasolineCar::setFuelMileagePer100Km(int mileage) { fuel_mileage_per_100km = mileage; }

void GasolineCar::setFuelType(std::string type) { fuel_type = type; }

void GasolineCar::printAllInformation()
{
	std::cout << "Electric car:\n\n";

	Vehicle::printAllInformation();

	std::cout << "Fuel type: " << std::setw(10) << "" << getFuelType() << std::endl;
	std::cout << "Fuel mileage: " << std::setw(7) << "" << getFuelMileagePer100Km() << " l per 100 km" << std::endl;
}