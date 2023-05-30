#pragma once
#include <iostream>
#include <string>
#include "BaseEntity.h"

class User: public BaseEntity
{
private:
	std::string name;
	std::string surname;
	std::string login;
	std::string password;
	int age;

public: 
	User(std::string user_name, 
		std::string user_surname, 
		std::string user_login, 
		std::string user_password, 
		int user_age);

	std::string getName() const;

	std::string getSurname() const;

	std::string getLogin() const;

	std::string getPassword() const;

	int getAge() const;

	void setName(std::string name);

	void setSurname(std::string surname);

	void setLogin(std::string login);

	void setPassword(std::string password);

	void setAge(int age);

	virtual void printBriefInformation() override;
};
