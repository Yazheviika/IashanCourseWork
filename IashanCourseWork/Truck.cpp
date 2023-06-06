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
	std::cout << "Truck:\n\n";

	Vehicle::printAllInformation();

	std::cout << "Cargo capacity: " << std::setw(5) << "" << getCargoCapacityInTons() << " tons" << std::endl;
}

void Truck::clone(std::shared_ptr<Vehicle>& newVehicle) const {
	newVehicle = std::make_shared<Truck>(*this);
}

void Truck::addIntoFile(std::string filename) const
{
	std::ofstream file_to_write(filename, std::ios::app);
	if (!file_to_write)
	{
		std::cerr << "File " << filename << " couldn`t be opened for writing.\n";
		exit(1);///////////
	}
	file_to_write << "T:"
		<< getId() << ','
		<< getSellerId() << ','
		<< getModel() << ','
		<< getPriceInUAH() << ','
		<< getColor() << ','
		<< getYearOfManufacture() << ','
		<< getCondition() << ','
		<< getEngineType() << ','
		<< getMileageInKm() << ','
		<< getCargoCapacityInTons() << '\n';

	file_to_write.close();
}

void Truck::getDataFromString(std::string string)
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
	setCargoCapacityInTons(std::stoi(token));
}

std::istream& operator>>(std::istream& stream, Truck& truck) {
	std::cout << "Model: ";
	std::string input_string;
	std::getline(stream, input_string);
	truck.setModel(input_string);

	std::cout << "Price in UAH: ";
	int input_number;
	stream >> input_number;
	truck.setPriceInUAH(input_number);

	std::cout << "Color: ";
	std::getline(stream, input_string);
	truck.setColor(input_string);

	std::cout << "Year of manufacture: ";
	stream >> input_number;
	truck.setYearOfManufacture(input_number);

	std::cout << "Condition (excellent/good/ok/bad): ";
	std::getline(stream, input_string);
	truck.setCondition(input_string);

	std::cout << "Type of engine: ";
	std::getline(stream, input_string);
	truck.setEngineType(input_string);

	std::cout << "Mileage in km: ";
	stream >> input_number;
	truck.setMileageInKm(input_number);

	std::cout << "Cargo capacity in tons: ";
	stream >> input_number;
	truck.setCargoCapacityInTons(input_number);

	return stream;
}