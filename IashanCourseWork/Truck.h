#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
private:
	int cargo_capacity_in_tons;

public:
	Truck(std::string truck_model = "",
		std::string truck_color = "",
		std::string truck_condition = "",
		std::string truck_engine_type = "",
		int truck_price = 0,
		int truck_year_of_manufacture = 0,
		int truck_mileage_in_km = 0,
		int truck_cargo_capacity = 0);

	int getCargoCapacityInTons() const;

	void setCargoCapacityInTons(int cargo_capacity);

	virtual void printAllInformation() override;
};

