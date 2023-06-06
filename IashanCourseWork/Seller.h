#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "User.h"

class Seller: public User
{
private:
	std::string individual_entrepreneur_number;
	std::string company_name;
	std::string sertificate_number;

public:
	Seller(std::string seller_name = "",
		std::string seller_surname = "",
		std::string seller_login = "",
		std::string seller_password = "",
		int seller_age = 0,
		std::string seller_individual_entrepreneur_number = "",
		std::string seller_company_name = "",
		std::string seller_sertificate_number = "");

	std::string getIndividualEnterpreneurNumber() const;

	std::string getCompanyName() const;

	std::string getSertificateNumber() const;

	void setIndividualEnterpreneurNumber(std::string IEN);

	void setCompanyName(std::string name);

	void setSertificateNumber(std::string number);

	void addIntoFile(std::string filename) const override;

	friend std::istream& operator>>(std::istream& is, Seller& seller);

	virtual void printAllInformation() override;
};

