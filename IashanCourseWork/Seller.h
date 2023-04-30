#pragma once
#include "User.h"

class Seller: User
{
private:
	std::string individual_entrepreneur_number;
	std::string company_name;
	std::string sertificate_number;

public:
	Seller(std::string seller_name,
		std::string seller_surname,
		std::string seller_login,
		std::string seller_password,
		int seller_age,
		std::string seller_individual_entrepreneur_number,
		std::string seller_company_name,
		std::string seller_sertificate_number);

	std::string getIndividualEnterpreneurNumber();

	std::string getCompanyName();

	std::string getSertificateNumber();

	//virtual void registrateUser(int a) override;
};

