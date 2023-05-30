#include <iostream>
#include <string>
#include "IUsersContainer.h"
#include "BaseEntity.h"
#include "BuyersContainer.h"
#include "SellersContainer.h"
#include "Buyer.h"
#include "Seller.h"

User* logIn(IUsersContainer* container);

User* signUp(IUsersContainer* container, std::string filename);

int main()
{
	std::string buyers_file = "Files/buyers.txt",
		sellers_file = "Files/sellers.txt",
		vehicles_file = "Files/vehicles.txt",
		transactions_file = "Files/transactions.txt";

	BuyersContainer buyers_repos(buyers_file);
	SellersContainer sellers_repos(sellers_file);
	
	bool runProgram = true;
	while (runProgram)
	{
		system("cls");
		std::cout << "Choose your actions:\n"
			<< "1. Log in\n"
			<< "2. Sign up\n"
			<< "0. Finish program\n\n"
			<< "Your decisinon: ";

		int choice;
		std::cin >> choice;

		switch (choice)
		{
		case 1: 
			system("cls");
			std::cout << "Do you want to log in as a:\n"
				<< "1. Buyer\n"
				<< "2. Seller\n"
				<< "0. Go back\n\n"
				<< "Your decisinon: ";

			int user_type;
			std::cin >> user_type;
			switch (user_type)
			{
			case 1: 
			{
				system("cls");

				Buyer* current_buyer = dynamic_cast<Buyer*>(logIn(&buyers_repos));
				if (current_buyer == nullptr)
					break;
				current_buyer->printBriefInformation();
				int r;
				std::cin >> r;

				break;
			}
			case 2:
			{
				system("cls");
				Seller* current_seller = dynamic_cast<Seller*>(logIn(&sellers_repos));
				if (current_seller == nullptr)
					break;

				current_seller->printBriefInformation();
				int r;
				std::cin >> r;

				break;
			}
			case 0: break;
			}

			break;

		case 2: 
		{
			system("cls");
			std::cout << "Do you want to sign up as a:\n"
				<< "1. Buyer\n"
				<< "2. Seller\n"
				<< "0. Go back\n\n"
				<< "Your decisinon: ";

			int user_type;
			std::cin >> user_type;
			switch (user_type)
			{
			case 1:
			{
				system("cls");
				Buyer* current_buyer = dynamic_cast<Buyer*>(signUp(&buyers_repos, buyers_file));
				if (current_buyer == nullptr)
					break;

				current_buyer->printBriefInformation();
				int r;
				std::cin >> r;

				break;
			}
			case 2:
			{
				system("cls");
				Seller* current_buyer = dynamic_cast<Seller*>(signUp(&sellers_repos, sellers_file));
				if (current_buyer == nullptr)
					break;

				current_buyer->printBriefInformation();
				int r;
				std::cin >> r;

				break;
			}
			case 0: break;
			}
			
			break;
		}
		case 0: runProgram = false; break;
		}
	}
}

User* logIn(IUsersContainer* container)
{
	User* user = nullptr;

	bool dataCorrectness = false;
	while (!dataCorrectness)
	{
		std::cout << "Login: ";
		std::string login;
		std::cin >> login;

		std::cout << "Password: ";
		std::string password;
		std::cin >> password;

		user = container->findByLoginAndPassword(login, password).get();
		if (user == nullptr)
		{
			system("cls");
			std::cout << "You wrote wrong login or password. Try again?\n"
				<< "1. Yes\n"
				<< "2. No\n\n"
				<< "Your decision: ";

			int choise;
			std::cin >> choise;
			if (choise == 1)
			{
				system("cls");
				continue;
			}
			else
				break;
		}
		else
			break;
	}
	return user;
}

User* signUp(IUsersContainer* container, std::string filename)
{
	bool dataCorrectness = false;
	while (!dataCorrectness)
	{
		std::string login;
		bool correctLogin = false;
		do
		{
			std::cout << "Come up with a login: ";
			std::cin >> login;

			if (container->findByLogin(login) != nullptr)
			{
				system("cls");
				std::cout << "The login \"" << login << "\" is already exist.\n\n"
					<< "Try again ? \n"
					<< "1. Yes\n"
					<< "2. No\n\n"
					<< "Your decision: ";

				int choise;
				std::cin >> choise;
				if (choise == 1)
				{
					system("cls");
					continue;
				}
				else
					return nullptr;
			}

			else
				!correctLogin;

		} while (container->findByLogin(login) != nullptr);

		if (dynamic_cast<SellersContainer*>(container))
		{
			Seller* user = new Seller;

			user->setLogin(login);

			std::cout << "Password: ";
			std::string password;
			std::cin >> password;
			user->setPassword(password);

			system("cls");
			std::cout << "Fill your profile with information about yourself.\n\n";

			std::cout << "Name: ";
			std::string name;
			std::cin >> name;
			user->setName(name);

			std::cout << "Surname: ";
			std::string surname;
			std::cin >> surname;
			user->setSurname(surname);

			std::cout << "Age: ";
			int age;
			std::cin >> age;
			user->setAge(age);

			std::cout << "Individual entrepreneur number: ";
			std::string individual_entrepreneur_number;
			std::cin >> individual_entrepreneur_number;
			user->setIndividualEnterpreneurNumber(individual_entrepreneur_number);

			std::cout << "Company name: ";
			std::string company_name;
			std::cin >> company_name;
			user->setCompanyName(company_name);

			std::cout << "Sertificate number: ";
			std::string sertificate_number;
			std::cin >> sertificate_number;
			user->setSertificateNumber(sertificate_number);

			container->addUserIntoContainerAndFile(std::make_shared<Seller>(*user), filename);
			return user;
		}
		
		else 
		{
			Buyer* user = new Buyer;

			user->setLogin(login);

			std::cout << "Password: ";
			std::string password;
			std::cin >> password;
			user->setPassword(password);

			system("cls");
			std::cout << "Fill your profile with information about yourself.\n\n";

			std::cout << "Name: ";
			std::string name;
			std::cin >> name;
			user->setName(name);

			std::cout << "Surname: ";
			std::string surname;
			std::cin >> surname;
			user->setSurname(surname);

			std::cout << "Age: ";
			int age;
			std::cin >> age;
			user->setAge(age);

			std::cout << "Buyer driving record in years: ";
			int driving_record_in_years;
			std::cin >> driving_record_in_years;
			user->setDrivingRecordInYears(driving_record_in_years);

			std::cout << "Your city: ";
			std::string city;
			std::cin >> city;
			user->setCity(city);

			container->addUserIntoContainerAndFile(std::make_shared<Buyer>(*user), filename);
			return user;
		}
	}
}