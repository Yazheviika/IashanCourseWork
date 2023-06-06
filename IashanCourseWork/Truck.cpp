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

std::istream& operator>>(std::istream& stream, Truck& truck) {
    std::string token;

    std::getline(stream, token, ',');
    truck.setId(std::stoi(token));

	std::getline(stream, token, ',');
	truck.setSellerId(std::stoi(token));

    std::getline(stream, token, ',');
    truck.setModel(token);

    std::getline(stream, token, ',');
    truck.setPriceInUAH(std::stoi(token));

    std::getline(stream, token, ',');
    truck.setColor(token);

    std::getline(stream, token, ',');
    truck.setYearOfManufacture(std::stoi(token));

    std::getline(stream, token, ',');
    truck.setCondition(token);

    std::getline(stream, token, ',');
    truck.setEngineType(token);

    std::getline(stream, token, ',');
    truck.setMileageInKm(std::stoi(token));

    std::getline(stream, token, ',');
    truck.setCargoCapacityInTons(std::stoi(token));

    return stream;
}