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
	std::cout << "Electric car:\n\n";

	Vehicle::printAllInformation();

	std::cout << "Capacity: " << std::setw(11) << "" << getPassengerCapacity() << " passengers" << std::endl;
}