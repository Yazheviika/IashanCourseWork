#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
private:
	std::string additional_facilities;

public:
	Car(std::string car_model,
		std::string car_color,
		std::string car_condition,
		std::string car_engine_type,
		int car_price,
		int car_year_of_manufacture,
		int car_mileage_in_km,
		std::string car_additional_facilities);

	std::string getAdditionalFacilities() const;

	void setAdditionalFacilities(std::string additional_facility);
};

