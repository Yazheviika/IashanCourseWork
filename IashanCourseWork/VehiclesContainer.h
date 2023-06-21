#pragma once
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
#include "Vehicle.h"
#include "GasolineCar.h"
#include "ElectricCar.h"
#include "PassengerTransport.h"
#include "Truck.h"
#include "VehicleType.h"
#include "Iterator.h"

class VehiclesContainer
{
private:
	std::shared_ptr<Vehicle>* data;
	int length;

public:
	VehiclesContainer();

	VehiclesContainer(int size);

	VehiclesContainer(std::string filename);

	VehiclesContainer(const VehiclesContainer& other);

	VehiclesContainer& operator=(const VehiclesContainer& other);

	~VehiclesContainer();

	int getLength() const;

	Iterator<std::shared_ptr<Vehicle>> begin() const;

	Iterator<std::shared_ptr<Vehicle>> end() const;

	void erase();

	void resize(int new_length);

	void push_back(std::shared_ptr<Vehicle> vehicle);

	void removeFromContainerAndFileById(int id, std::string filename);

	void removeFromContainerAndFileBySellerId(int seller_id, std::string filename);

	Vehicle& operator[](int index);

	void addVehicleIntoContainerAndFile(std::shared_ptr<Vehicle> vehicle, std::string filename);

	std::shared_ptr<Vehicle> findById(int id) const;

	VehiclesContainer findByModel(std::string model) const;

	VehiclesContainer findByPrice(int min_price, int max_price) const;

	VehiclesContainer findByType(VehicleType type) const;

	VehiclesContainer findBySellerId(int seller_id) const;

private:
	int findMaxId() const;
};

