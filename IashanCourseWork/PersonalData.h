#pragma once

class PersonalData
{
protected:
	char m_sex;
	short int m_age;
	std::string m_phone_number;


	  

	PersonalData(char sex, short int age, std::string phone_number);

	char getSex();

	short int getAge();

	std::string getPhoneNumber();
};

