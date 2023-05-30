#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
private:
	bool body;
	std::string aditional_facilities;

public:
	Car(std::string car_model,
		std::string car_color,
		std::string car_condition,
		std::string car_engine_type,
		int car_price,
		int car_year_of_manufacture,
		int car_mileage_in_km,
		bool car_body,
		std::string car_aditional_facilities);

	bool getBody() const;

	std::string getAditionalFacilities() const;

	void setBody(bool vody);

	void setAditionalFacilities(std::string aditional_facility);
};

