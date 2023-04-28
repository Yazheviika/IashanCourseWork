#include <iostream>
#include <string>

#include "PersonalData.h"
#include "CurrentDate.h"
#include "RegistrationData.h"
#include "DatingAgencyUserData.h"

DatingAgencyUserData::DatingAgencyUserData(std::string user_nickname, short int user_age, char user_sex, std::string user_phone_number,
	std::string user_description, std::string user_partner_requirements, std::string user_hobbies, int user_register_number)
	: PersonalData(user_sex, user_age, user_phone_number), nickname(user_nickname), person_description(user_description),
	partner_requirements(user_partner_requirements), hobbies(user_hobbies)
{

}