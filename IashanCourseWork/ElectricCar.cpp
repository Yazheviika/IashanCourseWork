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

void ElectricCar::getDataFromString(std::string string)
{
	std::istringstream string_as_stream(string);
	std::string token;

	std::getline(string_as_stream, token, ',');
	setId(std::stoi(token));

	std::getline(string_as_stream, token, ',');
	setSellerId(std::stoi(token));

	std::getline(string_as_stream, token, ',');
	setModel(token);

	std::getline(string_as_stream, token, ',');
	setPriceInUAH(std::stoi(token));

	std::getline(string_as_stream, token, ',');
	setColor(token);

	std::getline(string_as_stream, token, ',');
	setYearOfManufacture(std::stoi(token));

	std::getline(string_as_stream, token, ',');
	setCondition(token);

	std::getline(string_as_stream, token, ',');
	setEngineType(token);

	std::getline(string_as_stream, token, ',');
	setMileageInKm(std::stoi(token));

	std::getline(string_as_stream, token, ',');
	setAdditionalFacilities(token);

	std::getline(string_as_stream, token, ',');
	setBatteryType(token);

	std::getline(string_as_stream, token, ',');
	setPowerInWatts(std::stoi(token));
}

std::istream& operator>>(std::istream& stream, ElectricCar& car) 
{
	std::cout << "Model: ";
	std::string input_string;
	std::cin.ignore();
	std::getline(stream, input_string);
	car.setModel(input_string);

	std::cout << "Price in UAH: ";
	int input_number;
	stream >> input_number;
	car.setPriceInUAH(input_number);

	std::cout << "Color: ";
	std::cin.ignore();
	std::getline(stream, input_string);
	car.setColor(input_string);

	std::cout << "Year of manufacture: ";
	stream >> input_number;
	car.setYearOfManufacture(input_number);

	std::cout << "Condition (excellent/good/ok/bad): ";
	std::cin.ignore();
	std::getline(stream, input_string);
	car.setCondition(input_string);

	std::cout << "Type of engine: ";
	std::getline(stream, input_string);
	car.setEngineType(input_string);

	std::cout << "Mileage in km: ";
	stream >> input_number;
	car.setMileageInKm(input_number);

	std::cout << "Additional facilities (max 20 symbols): ";
	std::cin.ignore();
	std::getline(stream, input_string);
	car.setAdditionalFacilities(input_string);

	std::cout << "Type of battery: ";
	std::getline(stream, input_string);
	car.setBatteryType(input_string);

	std::cout << "Power in watts: ";
	stream >> input_number;
	car.setPowerInWatts(input_number);

	return stream;
}


