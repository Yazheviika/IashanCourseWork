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

int Buyer::getDrivingRecordInYears() const { return driving_record_in_years; }

std::string Buyer::getCity() const { return city; }

void Buyer::setDrivingRecordInYears(int years) { driving_record_in_years = years; }

void Buyer::setCity(std::string city) { this->city = city; }

void Buyer::printAllInformation()
{
	std::cout << "Id: " << std::setw(12) << "" << getId() << std::endl;
	std::cout << "Full name: " << std::setw(5) << "" << getName() << " " << getSurname() << std::endl;
	std::cout << "Age: " << std::setw(11) << "" << getAge() << std::endl;
	std::cout << "Driving record: " << getDrivingRecordInYears() << " years" << std::endl;
	std::cout << "City: " << std::setw(10) << "" << getCity() << std::endl;
}

std::istream& operator>>(std::istream& stream, Buyer& buyer) {
    std::string token;

    getline(stream, token, ',');
    buyer.setId(std::stoi(token));

    std::getline(stream, token, ',');
    buyer.setName(token);

    std::getline(stream, token, ',');
    buyer.setSurname(token);

    std::getline(stream, token, ',');
    buyer.setLogin(token);

    std::getline(stream, token, ',');
    buyer.setPassword(token);

    std::getline(stream, token, ',');
    buyer.setAge(std::stoi(token));

    std::getline(stream, token, ',');
    buyer.setDrivingRecordInYears(std::stoi(token));

    std::getline(stream, token, ',');
    buyer.setCity(token);

    return stream;
}
