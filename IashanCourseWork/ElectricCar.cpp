#include "ElectricCar.h"

ElectricCar::ElectricCar(std::string car_model,
	std::string car_color,
	std::string car_condition,
	std::string car_engine_type,
	int car_price,
	int car_year_of_manufacture,
	int car_mileage_in_km,
	bool car_body,
	std::string car_aditional_facilities,
	std::string car_battery_type,
	int car_power_in_watts)
	: Car(car_model,
		car_color,
		car_condition,
		car_engine_type,
		car_price,
		car_year_of_manufacture,
		car_mileage_in_km,
		car_body,
		car_aditional_facilities),
	battery_type(car_battery_type),
	power_in_watts(car_power_in_watts) { }

int ElectricCar::getPowerInWatts() const { return power_in_watts; }

std::string ElectricCar::getBatteryType() const { return battery_type; }

void ElectricCar::setPowerInWatts(int power) { power_in_watts = power; }

void ElectricCar::setBatteryType(std::string type) { battery_type = type; }

void ElectricCar::printAllInformation()
{
	std::cout << "Electric car:\n\n";

	Vehicle::printAllInformation();

	std::cout << "Battery type: " << std::setw(7) << "" << getBatteryType() << std::endl;
	std::cout << "Power: " << std::setw(14) << "" << getPowerInWatts() << " watts" << std::endl;
}
