#pragma once
#include "RegistrationData.h"

class DatingAgencyUserData: public PersonalData
{
private:
	std::string nickname;
	std::string person_description;
	std::string partner_requirements;
	std::string hobbies;
	RegistrationData date;

public:
	DatingAgencyUserData(std::string user_nickname, short int user_age, char user_sex, std::string user_phone_number,
		std::string user_description, std::string user_partner_requirements, std::string user_hobbies, int register_number);

	using PersonalData::getAge;


};

