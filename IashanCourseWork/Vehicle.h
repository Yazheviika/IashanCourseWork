#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sqlite3.h>
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

public:
	Vehicle(std::string vehicle_model,
		std::string vehicle_color,
		std::string vehicle_condition,
		std::string vehicle_engine_type,
		int vehicle_price,
		int vehicle_year_of_manufacture,
		int vehicle_mileage_in_km);

	std::string getModel() const;

	std::string getColor() const;

	std::string getCondition() const;

	std::string getEngineType() const;

	int getPriceInUAH() const;

	int getYearOfManufacture() const;

	int getMileageInKm() const;

	void setModel(std::string model);

	void setColor(std::string color);

	void setCondition(std::string condition);

	void setEngineType(std::string engine_type);

	void setPriceInUAH(int price);

	void setYearOfManufacture(int year);

	void setMileageInKm(int year);

	virtual void printBriefInformation() override;

	virtual void printAllInformation() = 0;
};

