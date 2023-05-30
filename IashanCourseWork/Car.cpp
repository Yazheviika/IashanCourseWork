#include <string>
#include "Car.h"

Car::Car(std::string car_model,
	std::string car_color,
	std::string car_condition,
	std::string car_engine_type,
	int car_price,
	int car_year_of_manufacture,
	int car_mileage_in_km,
	bool car_body,
	std::string car_aditional_facilities)
	: Vehicle(car_model,
		car_color,
		car_condition,
		car_engine_type,
		car_price,
		car_year_of_manufacture,
		car_mileage_in_km),
	body(car_body),
	aditional_facilities(car_aditional_facilities) { }

bool Car::getBody() const { return body; }

std::string Car::getAditionalFacilities() const { return aditional_facilities; }

void Car::setBody(bool body) { this->body = body; }

void Car::setAditionalFacilities(std::string aditional_facilities)
{
	this->aditional_facilities = aditional_facilities;
}