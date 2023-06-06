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

void User::deleteFromFile(std::string filename) const
{
	std::ifstream file_to_read(filename);
	std::ofstream temporary_file("Files/temp.txt");

	if (!file_to_read)
	{
		std::cerr << "File " << filename << " couldn`t be opened for reading.\n";
		exit(1);///////////
	}
	if (!temporary_file)
	{
		std::cerr << "Temporary file for copying data couldn`t be created.\n";
		exit(1);////////////
	}

	std::string user;
	while (getline(file_to_read, user))
	{
		std::istringstream stringAsStream(user);
		std::string curr_id;
		getline(stringAsStream, curr_id, ',');

		if (std::stoi(curr_id) != getId())
			temporary_file << user << '\n';
	}

	file_to_read.close();
	temporary_file.close();

	std::ofstream file_to_copy(filename, std::ios::trunc);
	std::ifstream file_to_copy_from("Files/temp.txt");

	if (!file_to_copy)
	{
		std::cerr << "File " << filename << " couldn`t be opened for writing.\n";
		exit(1);///////////
	}
	if (!file_to_copy_from)
	{
		std::cerr << "Temporary file for copying data couldn`t be created.\n";
		exit(1);////////////
	}

	while (getline(file_to_copy_from, user))
		file_to_copy << user << '\n';

	file_to_copy.close();
	file_to_copy_from.close();

	int Status = std::remove("Files/temp.txt");
	if (Status != 0)
		std::cerr << "Temporary file couldn`t be removed.\n";
}

