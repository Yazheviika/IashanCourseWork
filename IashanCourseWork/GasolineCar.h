#pragma once
#include <string>
#include "Car.h"

class GasolineCar : public Car
{
private:
	int fuel_mileage_per_100km;
	std::string fuel_type;

public:
	GasolineCar(std::string car_model = "",
		std::string car_color = "",
		std::string car_condition = "",
		std::string car_engine_type = "",
		int car_price = 0,
		int car_year_of_manufacture = 0,
		int car_mileage_in_km = 0,
		bool car_body = 0,
		std::string car_aditional_facilities = "",
		std::string car_fuel_type = "",
		int car_fuel_mileage = 0);

	int getFuelMileagePer100Km() const;

	std::string getFuelType() const;

	void setFuelMileagePer100Km(int mileage);

	void setFuelType(std::string type);

	virtual void printAllInformation() override;
};

