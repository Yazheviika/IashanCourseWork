#include <iostream>
#include <string>
#include <stdio.h>
#include <sqlite3.h>
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

std::string Seller::getIndividualEnterpreneurNumber() { return individual_entrepreneur_number; }

std::string Seller::getCompanyName() { return company_name; }

std::string Seller::getSertificateNumber() { return sertificate_number; }

//void Seller::registrateUser(int a)
//{
	/*std::string query = "INSERT INTO my_table (age, name) VALUES (21, 'Maxim'), (18, 'Vika');";

	int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);

	if (rc != SQLITE_OK)
	{
		std::cerr << "Cannot insert data: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
	}*/
//}
