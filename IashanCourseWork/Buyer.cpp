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

void Buyer::addIntoFile(std::string filename) const
{
	std::ofstream file_to_write(filename, std::ios::app);
	if (!file_to_write)
	{
		std::cerr << "File " << filename << " couldn`t be opened for writing.\n";
		exit(1);///////////
	}

	file_to_write << getId() << ","
		<< getName() << ","
		<< getSurname() << ","
		<< getLogin() << ","
		<< getPassword() << ","
		<< getAge() << ","
		<< getDrivingRecordInYears() << ","
		<< getCity() << '\n';

	file_to_write.close();
}

void Buyer::getDataFromString(std::string string)
{
	std::istringstream string_as_stream(string);
	std::string token;

	getline(string_as_stream, token, ',');
	setId(std::stoi(token));

	std::getline(string_as_stream, token, ',');
	setName(token);

	std::getline(string_as_stream, token, ',');
	setSurname(token);

	std::getline(string_as_stream, token, ',');
	setLogin(token);

	std::getline(string_as_stream, token, ',');
	setPassword(token);

	std::getline(string_as_stream, token, ',');
	setAge(std::stoi(token));

	std::getline(string_as_stream, token, ',');
	setDrivingRecordInYears(std::stoi(token));

	std::getline(string_as_stream, token, ',');
	setCity(token);
}
