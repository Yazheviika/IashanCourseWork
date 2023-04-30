#pragma once
#include "BaseEntity.h"
//#include <stdio.h>
//#include <sqlite3.h>

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

	std::string getName();

	std::string getSurname();

	std::string getLogin();

	std::string getPassword();

	int getAge();

	void setName(std::string name);

	void setSurname(std::string surname);

	void setLogin(std::string login);

	void setPassword(std::string password);

	void setAge(int age);

	virtual void registrateUser()
	{
		sqlite3* db;
	}
};

