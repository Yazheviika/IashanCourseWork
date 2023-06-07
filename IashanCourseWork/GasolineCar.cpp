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

void GasolineCar::getDataFromString(std::string string)
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
	setFuelType(token);

	std::getline(string_as_stream, token, ',');
	setFuelMileagePer100Km(std::stoi(token));
}

std::istream& operator>>(std::istream& stream, GasolineCar& car) 
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

	std::cout << "Type of fuel: ";
	std::getline(stream, input_string);
	car.setFuelType(input_string);

	std::cout << "Mileage in liters per km: ";
	stream >> input_number;
	car.setFuelMileagePer100Km(input_number);

	return stream;
}