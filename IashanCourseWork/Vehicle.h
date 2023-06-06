#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include "BaseEntity.h"

class Vehicle : public BaseEntity
{
private:
	std::string model;
	std::string color;
	std::string condition;
	std::string engine_type;
	int price_in_UAH;
	int year_of_manufacture;
	int mileage_in_km;
	int seller_id;

public:
	Vehicle(std::string vehicle_model,
		std::string vehicle_color,
		std::string vehicle_condition,
		std::string vehicle_engine_type,
		int vehicle_price,
		int vehicle_year_of_manufacture,
		int vehicle_mileage_in_km,
		int vehicle_seller_id = 0);

	std::string getModel() const;

	std::string getColor() const;

	std::string getCondition() const;

	std::string getEngineType() const;

	int getPriceInUAH() const;

	int getYearOfManufacture() const;

	int getMileageInKm() const;

	int getSellerId() const;

	void setModel(std::string model);

	void setColor(std::string color);

	void setCondition(std::string condition);

	void setEngineType(std::string engine_type);

	void setPriceInUAH(int price);

	void setYearOfManufacture(int year);

	void setMileageInKm(int year);
	
	void setSellerId(int seller_id);

	virtual void printBriefInformation() override;

	virtual void printAllInformation() = 0;

	virtual void clone(std::shared_ptr<Vehicle>& newVehicle) const = 0;

	virtual void addIntoFile(std::string filename) const = 0;

	void deleteFromFile(std::string filename) const;
};

