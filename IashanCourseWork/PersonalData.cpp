#include <iostream>
#include <string>
#include "PersonalData.h"

PersonalData::PersonalData(char sex, short int age, std::string phone_number)
	:m_sex(sex), m_age(age), m_phone_number(phone_number) { }

char PersonalData::getSex() { return m_sex; }

short int PersonalData::getAge() { return m_age; }

std::string PersonalData::getPhoneNumber() { return m_phone_number; }
