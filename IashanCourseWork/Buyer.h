#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "User.h"

class Buyer: public User
{
private:
	int driving_record_in_years;
	std::string city;

public:
	Buyer(std::string buyer_name = "",
		std::string buyer_surname = "",
		std::string buyer_login = "",
		std::string buyer_password = "",
		int buyer_age = 0, 
		int buyer_driving_record= 0, 
		std::string buyer_city = "");

	int getDrivingRecordInYears() const;
	
	std::string getCity() const;

	void setDrivingRecordInYears(int years);

	void setCity(std::string city);

	friend std::istream& operator>>(std::istream& is, Buyer& buyer);

	virtual void printAllInformation() override;
};

