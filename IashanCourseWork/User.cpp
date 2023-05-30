#include <string>
#include <stdio.h>
#include <sqlite3.h>
#include "User.h"

User::User(std::string user_name, 
	std::string user_surname, 
	std::string user_login, 
	std::string user_password, 
	int user_age)
	: BaseEntity(),
	name(user_name), 
	surname(user_surname), 
	login(user_login), 
	password(user_password), 
	age(user_age) { }

std::string User::getName() const { return name; }

std::string User::getSurname() const { return surname; }

std::string User::getLogin() const { return login; }

std::string User::getPassword() const { return password; }

int User::getAge() const { return age; }

void User::setName(std::string name) { this->name = name; }

void User::setSurname(std::string surname) { this->surname = surname; }

void User::setLogin(std::string login) { this->login = login; }

void User::setPassword(std::string password) { this->password = password; }

void User::setAge(int age) { this->age = age; }

void User::printBriefInformation()
{
	std::cout << "(Id: " << getId() << ") ";
	std::cout << "Full name: " << getName() << " " << getSurname() << std::endl;
}



