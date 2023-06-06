#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "IUsersContainer.h"
#include "BaseEntity.h"
#include "BuyersContainer.h"
#include "SellersContainer.h"
#include "VehiclesContainer.h"
#include "TransactionsContainer.h"
#include "TransactionStatus.h"
#include "Vehicle.h"
#include "GasolineCar.h"
#include "ElectricCar.h"
#include "PassengerTransport.h"
#include "Truck.h"
#include "Buyer.h"
#include "Seller.h"

User* logIn(IUsersContainer* container);

User* signUp(IUsersContainer* container, std::string filename);

void BuyerInterface(Buyer& buyer);

void SellerInterface(const BuyersContainer& buyers_repos,
	SellersContainer& sellers_repos,
	VehiclesContainer& vehicles_repos,
	TransactionsContainer& transactions_repos,
	std::string filename);

void goThroughAdvertisements(Buyer& buyer);


std::string buyers_file = "Files/buyers.txt",
sellers_file = "Files/sellers.txt",
vehicles_file = "Files/vehicles.txt",
transactions_file = "Files/transactions.txt";

BuyersContainer buyers_repos(buyers_file);
SellersContainer sellers_repos(sellers_file);
VehiclesContainer vehicles_repos(vehicles_file);
TransactionsContainer transactions_repos(transactions_file);

int main()
{
	/*std::string buyers_file = "Files/buyers.txt",
		sellers_file = "Files/sellers.txt",
		vehicles_file = "Files/vehicles.txt",
		transactions_file = "Files/transactions.txt";

	BuyersContainer buyers_repos(buyers_file);
	SellersContainer sellers_repos(sellers_file);
	VehiclesContainer vehicles_repos(vehicles_file);
	TransactionsContainer transactions_repos(transactions_file);*/

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
				
				BuyerInterface(*current_buyer);

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
				correctLogin = true;

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

void BuyerInterface(Buyer &buyer)
{
	bool runInterface = true;

	while (runInterface)
	{
		system("cls");

		std::cout << "Hello, Buyer!\n";
		buyer.printBriefInformation();
		std::cout << '\n';

		std::cout << "Actions you can perform: \n"
			<< "1. View full account info\n"
			<< "2. View advertisements\n"
			<< "3. View transactions\n"
			<< "4. Delete account\n"
			<< "0. Log out\n\n"
			<< "Your decisinon: ";

		int decision;
		std::cin >> decision;

		switch (decision)
		{
		case 1:
		{
			system("cls");

			std::cout << "Full information about your account is:\n\n";
			buyer.printAllInformation();

			std::cout << "\nEnter any sumbol to continue: ";
			char to_continue;
			std::cin >> to_continue;
			break;
		}
		case 2:
		{
			goThroughAdvertisements(buyer);
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "Your transactions are: \n\n";

			TransactionsContainer current_buyer_transactions = transactions_repos.findByBuyerId(buyer.getId());

			if (current_buyer_transactions.getLength() == 0)
			{
				system("cls");
				std::cout << "You have no transactions.\n"
					<< "Press Enter to continue.\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.clear();
				std::cin.get();
				break;
			}

			int max_on_the_page = 0;
			for (auto iter = current_buyer_transactions.begin(); iter != current_buyer_transactions.end(); iter++)
			{
				if (max_on_the_page % 3 == 0 && max_on_the_page != 0)
				{
					std::cout << "Enter vehicle id to delete related transaction\n"
						<< "or enter 0 to view next page with transactions.\n\n"
						<< "Your decision: ";

					int next_step;
					std::cin >> next_step;

					if (next_step)
					{
						transactions_repos.removeFromContainerAndFileByBuyerAndVehicleId(buyer.getId(), next_step, transactions_file);
					}
				}

				max_on_the_page++;

				std::cout << "-----------Transaction #" << max_on_the_page << '\n';

				if ((*iter)->getStatus() == TransactionStatus::Sold)
					std::cout << "Congratulations on your purchase!\n";
				else if((*iter)->getStatus() == TransactionStatus::Pending)
					std::cout << "Seller will contact you.\n";
				else
					std::cout << "Unfortunately, this transaction was canceled.\n";

				std::cout << "Vehicle: ";
				vehicles_repos.findById((*iter)->getVehicleId())->printBriefInformation();
				std::cout << "Seller: ";
				sellers_repos.findById((*iter)->getSellerId())->printBriefInformation();
				std::cout << '\n';
			}
			std::cout << "Enter vehicle id to delete related transaction\n"
					<< "or enter 0 to go to the main menu.\n\n"
					<< "Your decision: ";

			int next_step;
			std::cin >> next_step;

			if (next_step)
				transactions_repos.removeFromContainerAndFileByBuyerAndVehicleId(buyer.getId(), next_step, transactions_file);

			break;
		}
		case 4: 
		{
			system("cls");

			std::cout << "Are you sure you want to delete your account permanently?\n"
				<< "1. Yes\n"
				<< "0. No\n\n"
				<< "Your decisinon: ";

			int is_deleting;
			std::cin >> is_deleting;
			if (is_deleting)
			{
				buyers_repos.removeFromContainerAndFileById(buyer.getId(), buyers_file);
				transactions_repos.removeFromContainerAndFileByBuyerId(buyer.getId(), buyers_file);
				return;
			}
			else
				break;
		}
		case 0: return;
		}
	}
}

void goThroughAdvertisements(Buyer& buyer)
{
	system("cls");

	std::cout << "How do you want to do the search?\n"
		<< "1. View all advertisements\n"
		<< "2. Search by vehicle type\n"
		<< "3. Search by price\n"
		<< "4. Search by name\n"
		<< "0. Go back\n\n"
		<< "Your decisinon: ";

	int decision;
	std::cin >> decision;

	VehiclesContainer search_container;

	switch (decision)
	{
	case 1: { search_container = vehicles_repos; break; }
	case 2:
	{
		while(true)
		{
			system("cls");

			std::cout << "Do you want to find:\n"
				<< "1. Electric car\n"
				<< "2. Gasoline car\n"
				<< "3. Truck\n"
				<< "4. Passenger transport\n"
				<< "0. Go to the main menu\n\n"
				<< "Your decisinon: ";

			int vehicle_type;
			std::cin >> vehicle_type;

			if (vehicle_type == 0)
				return;

			search_container = vehicles_repos.findByType(static_cast<VehicleTypes>(vehicle_type));

			if (search_container.getLength() == 0)
			{
				system("cls");
				std::cout << "Unfortunately, no advertisement for your query.\n"
					<< "Press Enter to continue.\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.clear();
				std::cin.get();
			}
			else
				break;
		}
		break;
	}
	case 3:
	{
		while (true)
		{
			system("cls");

			std::cout << "Enter the minimum price in UAH: ";
			unsigned int min_price;
			std::cin >> min_price;

			std::cout << "Enter the maximum price in UAH: ";
			unsigned int max_price;
			std::cin >> max_price;
			
			std::cout << "\nVehicles priced from " << min_price << " to " << max_price << " UAH will be in search of.\n"
				<< "1. Continue\n"
				<< "0. Go to the main menu\n\n"
				<< "Your decisinon: ";

			int continuation;
			std::cin >> continuation;

			if (continuation == 0)
				return;

			search_container = vehicles_repos.findByPrice(min_price, max_price);

			if (search_container.getLength() == 0)
			{
				system("cls");
				std::cout << "Unfortunately, no advertisement for your query.\n"
					<< "Press Enter to continue.\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.clear();
				std::cin.get();
			}
			else
				break;
		}
		break;
	}
	case 4:
	{
		while (true)
		{
			system("cls");

			std::cout << "Enter the model: ";
			std::string model;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			std::getline(std::cin, model);

			std::cout << "\nVehicles named \"" << model << "\" will be in search of.\n"
				<< "1. Continue\n"
				<< "0. Go to the main menu\n\n"
				<< "Your decisinon: ";

			int continuation;
			std::cin >> continuation;

			if (continuation == 0)
				return;

			search_container = vehicles_repos.findByModel(model);

			if (search_container.getLength() == 0)
			{
				system("cls");
				std::cout << "Unfortunately, no advertisement for your query.\n"
					<< "Press Enter to continue.\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.clear();
				std::cin.get();
			}
			else
				break;
		}
		break;
	}
	case 0: return;
	}

	for (auto iter = search_container.begin(); iter != search_container.end(); iter++)
	{
		system("cls");
		(*iter)->printAllInformation();

		std::cout << "\n\n1. Skip\n"
			<< "2. Make a purchase request\n"
			<< "0. Stop search\n\n"
			<< "Your decisinon: ";

		int next_actions;
		std::cin >> next_actions;

		switch (next_actions)
		{
		case 1: break;
		case 2:
		{
			system("cls");

			transactions_repos.addTransactionIntoContainerAndFile(std::make_shared<Transaction>(Transaction(buyer.getId(), (*iter)->getSellerId(), (*iter)->getId())), transactions_file);
			std::cout << "Your request was sent. The seller will contact you.\n"
				<< "1. Continue viewing\n"
				<< "0. Go to the main menu\n"
				<< "Your decisinon: ";

			int continuation;
			std::cin >> continuation;
			if (continuation)
				break;
			else
				return;
		}
		case 0: return;
		}
	}
}