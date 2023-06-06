#pragma once
#include "Vehicle.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

class PassengerTransport : public Vehicle
{
private:
	int passenger_capacity;

public:
	PassengerTransport(std::string passenger_transport_model = "",
		std::string passenger_transport_color = "",
		std::string passenger_transport_condition = "",
		std::string passenger_transport_engine_type = "",
		int passenger_transport_price = 0,
		int passenger_transport_year_of_manufacture = 0,
		int passenger_transport_mileage_in_km = 0,
		int passenger_transport_passenger_capacity = 0);

	int getPassengerCapacity() const;

	void setPassengerCapacity(int passenger_capacity);

	virtual void printAllInformation() override;

	void clone(std::shared_ptr<Vehicle>& newVehicle) const override;

	void addIntoFile(std::string filename) const override;

	friend std::istream& operator>>(std::istream& stream, PassengerTransport& passenger_transport);
};

