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

std::istream& operator>>(std::istream& stream, PassengerTransport& passenger_transport)
{
    std::string token;

    std::getline(stream, token, ',');
    passenger_transport.setId(std::stoi(token));

	std::getline(stream, token, ',');
	passenger_transport.setSellerId(std::stoi(token));

    std::getline(stream, token, ',');
    passenger_transport.setModel(token);

    std::getline(stream, token, ',');
    passenger_transport.setPriceInUAH(std::stoi(token));

    std::getline(stream, token, ',');
    passenger_transport.setColor(token);

    std::getline(stream, token, ',');
    passenger_transport.setYearOfManufacture(std::stoi(token));

    std::getline(stream, token, ',');
    passenger_transport.setCondition(token);

    std::getline(stream, token, ',');
    passenger_transport.setEngineType(token);

    std::getline(stream, token, ',');
    passenger_transport.setMileageInKm(std::stoi(token));

    std::getline(stream, token, ',');
    passenger_transport.setPassengerCapacity(std::stoi(token));

    return stream;
}