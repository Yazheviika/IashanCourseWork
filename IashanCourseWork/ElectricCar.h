#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Car.h"

class ElectricCar : public Car
{
private:
	int power_in_watts;
	std::string battery_type;

public:
	ElectricCar(std::string car_model = "",
		std::string car_color = "",
		std::string car_condition = "",
		std::string car_engine_type = "",
		int car_price = 0,
		int car_year_of_manufacture = 0,
		int car_mileage_in_km = 0,
		bool car_body = 0,
		std::string car_aditional_facilities = "",
		std::string car_battery_type = "",
		int car_power_in_watts = 0);

	int getPowerInWatts() const;

	std::string getBatteryType() const;

	void setPowerInWatts(int power);

	void setBatteryType(std::string type);
	
	virtual void printAllInformation() override;
};

