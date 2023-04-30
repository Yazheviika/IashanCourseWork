#include <string>
#include <stdio.h>
#include <sqlite3.h>
#include "Buyer.h"

Buyer::Buyer(std::string buyer_name, 
	std::string buyer_surname, 
	std::string buyer_login,
	std::string buyer_password,
	int buyer_age,
	int buyer_driving_record,
	std::string buyer_city)
	: User(buyer_name, buyer_surname, buyer_login, buyer_password, buyer_age),
	driving_record_in_years(buyer_driving_record), 
	city(buyer_city) { }

int Buyer::getDrivingRecordInYear() { return driving_record_in_years; }

std::string Buyer::getCity() { return city; }

void Buyer::setDrivingRecordInYear(int years) { driving_record_in_years = years; }

void Buyer::setCity(std::string city) { this->city = city; }

//void Buyer::registrateUser(int a)
//{
//	setAge(15);
//}