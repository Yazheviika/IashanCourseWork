#include "GasolineCar.h"

GasolineCar::GasolineCar(
	std::string car_model,
	std::string car_color,
	std::string car_condition,
	std::string car_engine_type,
	int car_price,
	int car_year_of_manufacture,
	int car_mileage_in_km,
	std::string car_additional_facilities,
	std::string car_fuel_type,
	int car_fuel_mileage)
	: Car(car_model,
		car_color,
		car_condition,
		car_engine_type,
		car_price,
		car_year_of_manufacture,
		car_mileage_in_km,
		car_additional_facilities),
	fuel_type(car_fuel_type),
	fuel_mileage_per_100km(car_fuel_mileage) { }

int GasolineCar::getFuelMileagePer100Km() const { return fuel_mileage_per_100km; }

std::string GasolineCar::getFuelType() const { return fuel_type; }

void GasolineCar::setFuelMileagePer100Km(int mileage) { fuel_mileage_per_100km = mileage; }

void GasolineCar::setFuelType(std::string type) { fuel_type = type; }

void GasolineCar::printAllInformation()
{
	std::cout << "Gasoline car:\n\n";

	Vehicle::printAllInformation();

	std::cout << "Fuel type: " << std::setw(10) << "" << getFuelType() << std::endl;
	std::cout << "Fuel mileage: " << std::setw(7) << "" << getFuelMileagePer100Km() << " l per 100 km" << std::endl;
}

void GasolineCar::clone(std::shared_ptr<Vehicle>& newVehicle) const {
	newVehicle = std::make_shared<GasolineCar>(*this);
}

void GasolineCar::addIntoFile(std::string filename) const
{
	std::ofstream file_to_write(filename, std::ios::app);
	if (!file_to_write)
	{
		std::cerr << "File " << filename << " couldn`t be opened for writing.\n";
		exit(1);///////////
	}
	file_to_write << "G:"
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
		<< getFuelType() << ','
		<< getFuelMileagePer100Km() << '\n';

	file_to_write.close();
}

std::istream& operator>>(std::istream& stream, GasolineCar& car) {
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
	car.setFuelType(token);

	std::getline(stream, token, ',');
	car.setFuelMileagePer100Km(std::stoi(token));

	return stream;
}