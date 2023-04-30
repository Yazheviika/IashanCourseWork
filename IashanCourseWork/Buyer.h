#pragma once
#include "User.h"

class Buyer: public User
{
private:
	int driving_record_in_years;
	std::string city;

public:
	Buyer(std::string buyer_name, 
		std::string buyer_surname, 
		std::string buyer_login,
		std::string buyer_password, 
		int buyer_age, 
		int buyer_driving_record, 
		std::string buyer_city);

	int getDrivingRecordInYear();
	
	std::string getCity();

	void setDrivingRecordInYear(int years);

	void setCity(std::string city);

	//virtual void registrateUser(int a) override;
};

