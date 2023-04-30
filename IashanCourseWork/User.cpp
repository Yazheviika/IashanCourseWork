#include <string>
#include <stdio.h>
#include <sqlite3.h>
#include "User.h"

User::User(std::string user_name, 
	std::string user_surname, 
	std::string user_login, 
	std::string user_password, 
	int user_age)
	: name(user_name), 
	surname(user_surname), 
	login(user_login), 
	password(user_password), 
	age(user_age) { }

std::string User::getName() { return name; }

std::string User::getSurname() { return surname; }

std::string User::getLogin() { return login; }

std::string User::getPassword() { return password; }

int User::getAge() { return age; }

void User::setName(std::string name) { this->name = name; }

void User::setSurname(std::string surname) { this->surname = surname; }

void User::setLogin(std::string login) { this->login = login; }

void User::setPassword(std::string password) { this->password = password; }

void User::setAge(int age) { this->age = age; }



