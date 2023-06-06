#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
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
		std::string car_additional_facilities = "",
		std::string car_fuel_type = "",
		int car_fuel_mileage = 0);

	int getFuelMileagePer100Km() const;

	std::string getFuelType() const;

	void setFuelMileagePer100Km(int mileage);

	void setFuelType(std::string type);

	virtual void printAllInformation() override;

	void clone(std::shared_ptr<Vehicle>& newVehicle) const override;

	void addIntoFile(std::string filename) const override;

	void getDataFromString(std::string string) override;

	friend std::istream& operator>>(std::istream& stream, GasolineCar& car);
};

