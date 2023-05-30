#include <iostream>
#include "Vehicle.h"
#include "Truck.h"

Truck::Truck(std::string truck_model,
	std::string truck_color,
	std::string truck_condition,
	std::string truck_engine_type,
	int truck_price,
	int truck_year_of_manufacture,
	int truck_mileage_in_km,
	int truck_cargo_capacity)
	: Vehicle(truck_model, 
		truck_color,
		truck_condition,
		truck_engine_type,
		truck_price,
		truck_year_of_manufacture,
		truck_mileage_in_km),
	cargo_capacity_in_tons(truck_cargo_capacity) { }

int Truck::getCargoCapacityInTons() const { return cargo_capacity_in_tons; }

void Truck::setCargoCapacityInTons(int cargo_capacity) 
{
	cargo_capacity_in_tons = cargo_capacity;
}

void Truck::printAllInformation()
{
	std::cout << "Electric car:\n\n";

	Vehicle::printAllInformation();

	std::cout << "Cargo capacity: " << std::setw(5) << "" << getCargoCapacityInTons() << " tons" << std::endl;
}