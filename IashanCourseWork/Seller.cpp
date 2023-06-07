#include <iostream>
#include <string>
#include <sstream>
#include "Seller.h"

Seller::Seller(std::string seller_name,
	std::string seller_surname,
	std::string seller_login,
	std::string seller_password,
	int seller_age,
	std::string seller_individual_entrepreneur_number,
	std::string seller_company_name,
	std::string seller_sertificate_number)
	: User(seller_name, seller_surname, seller_login,
		seller_password, seller_age),
	individual_entrepreneur_number(seller_individual_entrepreneur_number),
	company_name(seller_company_name),
	sertificate_number(seller_sertificate_number) { }

std::string Seller::getIndividualEnterpreneurNumber() const { return individual_entrepreneur_number; }

std::string Seller::getCompanyName() const { return company_name; }

std::string Seller::getSertificateNumber() const { return sertificate_number; }

void Seller::setIndividualEnterpreneurNumber(std::string IEN) { individual_entrepreneur_number = IEN; }

void Seller::setCompanyName(std::string name) { company_name = name; }

void Seller::setSertificateNumber(std::string number) { sertificate_number = number; }

void Seller::addIntoFile(std::string filename) const
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
		<< getIndividualEnterpreneurNumber() << ","
		<< getCompanyName() << ','
		<< getSertificateNumber() << '\n';

	file_to_write.close();
}

void Seller::printAllInformation()
{
	std::cout << "Id: " << std::setw(28) << "" << getId() << std::endl;
	std::cout << "Full name: " << std::setw(21) << "" << getName() << " " << getSurname() << std::endl;
	std::cout << "Age: " << std::setw(27) << "" << getAge() << std::endl;
	std::cout << "Individual interpreneur number: " << getIndividualEnterpreneurNumber() << std::endl;
	std::cout << "Company name: " << std::setw(18) << "" << getCompanyName() << std::endl;
	std::cout << "Sertificate number: " << std::setw(12) << "" << getSertificateNumber() << std::endl;
}

std::istream& operator>>(std::istream& stream, Seller& seller) {
    std::string token;
	
	std::getline(stream, token, ',');
    seller.setId(std::stoi(token));

    std::getline(stream, token, ',');
    seller.setName(token);

    std::getline(stream, token, ',');
    seller.setSurname(token);

    std::getline(stream, token, ',');
    seller.setLogin(token);

    std::getline(stream, token, ',');
    seller.setPassword(token);

    std::getline(stream, token, ',');
    seller.setAge(std::stoi(token));

    std::getline(stream, token, ',');
    seller.setIndividualEnterpreneurNumber(token);

    std::getline(stream, token, ',');
    seller.setCompanyName(token);

    std::getline(stream, token, ',');
    seller.setSertificateNumber(token);

    return stream;
}