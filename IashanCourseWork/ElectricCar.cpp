#include "ElectricCar.h"

ElectricCar::ElectricCar(
	std::string car_model,
	std::string car_color,
	std::string car_condition,
	std::string car_engine_type,
	int car_price,
	int car_year_of_manufacture,
	int car_mileage_in_km,
	std::string car_additional_facilities,
	std::string car_battery_type,
	int car_power_in_watts)
	: Car(car_model,
		car_color,
		car_condition,
		car_engine_type,
		car_price,
		car_year_of_manufacture,
		car_mileage_in_km,
		car_additional_facilities),
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

void ElectricCar::clone(std::shared_ptr<Vehicle>& newVehicle) const {
	newVehicle = std::make_shared<ElectricCar>(*this);
}

void ElectricCar::addIntoFile(std::string filename) const
{
	std::ofstream file_to_write(filename, std::ios::app);
	if (!file_to_write)
	{
		std::cerr << "File " << filename << " couldn`t be opened for writing.\n";
		exit(1);///////////
	}
	file_to_write << "E:"
		<< getId() << ','
		<< getSellerId() << ','
		<< getModel() << ','
		<< getPriceInUAH() << ','
		<< getColor() << ','
		<< getYearOfManufacture() << ','
		<< getCondition() << ','
		<< getEngineType() << ','
		<< getMileageInKm() << ','
		<< getAdditionalFacilities() << ','
		<< getBatteryType() << ','
		<< getPowerInWatts() << '\n';

	file_to_write.close();
}

std::istream& operator>>(std::istream& stream, ElectricCar& car) {
	std::string token;

	std::getline(stream, token, ',');
	car.setId(std::stoi(token));

	std::getline(stream, token, ',');
	car.setSellerId(std::stoi(token));

	std::getline(stream, token, ',');
	car.setModel(token);

	std::getline(stream, token, ',');
	car.setPriceInUAH(std::stoi(token));

	std::getline(stream, token, ',');
	car.setColor(token);

	std::getline(stream, token, ',');
	car.setYearOfManufacture(std::stoi(token));

	std::getline(stream, token, ',');
	car.setCondition(token);

	std::getline(stream, token, ',');
	car.setEngineType(token);

	std::getline(stream, token, ',');
	car.setMileageInKm(std::stoi(token));

	std::getline(stream, token, ',');
	car.setAdditionalFacilities(token);

	std::getline(stream, token, ',');
	car.setBatteryType(token);

	std::getline(stream, token, ',');
	car.setPowerInWatts(std::stoi(token));

	return stream;
}


