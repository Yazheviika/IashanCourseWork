#include <string>
#include "PassengerTransport.h"

PassengerTransport::PassengerTransport(std::string passenger_transport_model,
	std::string passenger_transport_color,
	std::string passenger_transport_condition,
	std::string passenger_transport_engine_type,
	int passenger_transport_price,
	int passenger_transport_year_of_manufacture,
	int passenger_transport_mileage_in_km,
	int passenger_transport_passenger_capacity)
	: Vehicle(passenger_transport_model,
		passenger_transport_color,
		passenger_transport_condition,
		passenger_transport_engine_type,
		passenger_transport_price,
		passenger_transport_year_of_manufacture,
		passenger_transport_mileage_in_km),
	passenger_capacity(passenger_transport_passenger_capacity) { }

int PassengerTransport::getPassengerCapacity() const { return passenger_capacity; }

void PassengerTransport::setPassengerCapacity(int passenger_capacity)
{
	this->passenger_capacity = passenger_capacity;
}

void PassengerTransport::printAllInformation()
{
	std::cout << "Passenger transport:\n\n";

	Vehicle::printAllInformation();

	std::cout << "Capacity: " << std::setw(11) << "" << getPassengerCapacity() << " passengers" << std::endl;
}

void PassengerTransport::clone(std::shared_ptr<Vehicle>& newVehicle) const {
	newVehicle = std::make_shared<PassengerTransport>(*this);
}

void PassengerTransport::addIntoFile(std::string filename) const
{
	std::ofstream file_to_write(filename, std::ios::app);
	if (!file_to_write)
	{
		std::cerr << "File " << filename << " couldn`t be opened for writing.\n";
		exit(1);///////////
	}
	file_to_write << "P:"
		<< getId() << ','
		<< getSellerId() << ','
		<< getModel() << ','
		<< getPriceInUAH() << ','
		<< getColor() << ','
		<< getYearOfManufacture() << ','
		<< getCondition() << ','
		<< getEngineType() << ','
		<< getMileageInKm() << ','
		<< getPassengerCapacity() << '\n';

	file_to_write.close();
}

void PassengerTransport::getDataFromString(std::string string)
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
	setPassengerCapacity(std::stoi(token));
}

std::istream& operator>>(std::istream& stream, PassengerTransport& passenger_transport)
{
	std::cout << "Model: ";
	std::string input_string;
	std::cin.ignore();
	std::getline(stream, input_string);
	passenger_transport.setModel(input_string);

	std::cout << "Price in UAH: ";
	int input_number;
	stream >> input_number;
	passenger_transport.setPriceInUAH(input_number);

	std::cout << "Color: ";
	std::cin.ignore();
	std::getline(stream, input_string);
	passenger_transport.setColor(input_string);

	std::cout << "Year of manufacture: ";
	stream >> input_number;
	passenger_transport.setYearOfManufacture(input_number);

	std::cout << "Condition (excellent/good/ok/bad): ";
	std::cin.ignore();
	std::getline(stream, input_string);
	passenger_transport.setCondition(input_string);

	std::cout << "Type of engine: ";
	std::getline(stream, input_string);
	passenger_transport.setEngineType(input_string);

	std::cout << "Mileage in km: ";
	stream >> input_number;
	passenger_transport.setMileageInKm(input_number);

	std::cout << "Passenger capacity: ";
	stream >> input_number;
	passenger_transport.setPassengerCapacity(input_number);

	return stream;
}