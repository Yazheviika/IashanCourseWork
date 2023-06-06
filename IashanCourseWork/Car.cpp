#include <string>
#include "Car.h"

Car::Car(std::string car_model,
	std::string car_color,
	std::string car_condition,
	std::string car_engine_type,
	int car_price,
	int car_year_of_manufacture,
	int car_mileage_in_km,
	std::string car_additional_facilities)
	: Vehicle(car_model,
		car_color,
		car_condition,
		car_engine_type,
		car_price,
		car_year_of_manufacture,
		car_mileage_in_km),
	additional_facilities(car_additional_facilities) { }

std::string Car::getAdditionalFacilities() const { return additional_facilities; }

void Car::setAdditionalFacilities(std::string additional_facilities)
{
	this->additional_facilities = additional_facilities;
}