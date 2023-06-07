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

std::shared_ptr<User> logIn(IUsersContainer* container);

std::shared_ptr<User> signUp(IUsersContainer* container, std::string filename);

void BuyerInterface(Buyer &buyer);

void SellerInterface(Seller &seller);

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

				std::shared_ptr<Buyer> current_buyer = std::dynamic_pointer_cast<Buyer>(logIn(&buyers_repos));
				if (current_buyer == nullptr)
					break;
				
				BuyerInterface(*current_buyer);

				break;
			}
			case 2:
			{
				system("cls");
				std::shared_ptr<Seller> current_seller = std::dynamic_pointer_cast<Seller>(logIn(&sellers_repos));
				if (current_seller == nullptr)
					break;

				SellerInterface(*current_seller);

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
				std::shared_ptr<Buyer> current_buyer = std::dynamic_pointer_cast<Buyer>(signUp(&buyers_repos, buyers_file));
				if (current_buyer == nullptr)
					break;

				BuyerInterface(*current_buyer);

				break;
			}
			case 2:
			{
				system("cls");
				std::shared_ptr<Seller> current_seller = std::dynamic_pointer_cast<Seller>(signUp(&sellers_repos, sellers_file));
				if (current_seller == nullptr)
					break;

				SellerInterface(*current_seller);

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

std::shared_ptr<User> logIn(IUsersContainer* container)
{
	std::shared_ptr<User> user;

	bool dataCorrectness = false;
	do{
		std::cout << "Login: ";
		std::string login;
		std::cin >> login;

		std::cout << "Password: ";
		std::string password;
		std::cin >> password;

		user = container->findByLoginAndPassword(login, password);
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
			else { break; }
		}
		else { break; }
	} while (true);

	return user;
}

std::shared_ptr<User> signUp(IUsersContainer* container, std::string filename)
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
			std::shared_ptr<Seller> user = std::make_shared<Seller>();

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

			container->addUserIntoContainerAndFile(user, filename);
			return user;
		}
		
		else 
		{
			std::shared_ptr<Buyer> user = std::make_shared<Buyer>();

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

			container->addUserIntoContainerAndFile(user, filename);
			return user;
		}
	}
}

void BuyerInterface(Buyer& buyer)
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

			std::cout << "\nPress Enter to continue.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			std::cin.get();
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
				int buyer_id = buyer.getId();
				buyers_repos.removeFromContainerAndFileById(buyer_id, buyers_file);
				transactions_repos.removeFromContainerAndFileByBuyerId(buyer_id, transactions_file);
				return;
			}
			else
				break;
		}
		case 0: return;
		}
	}
}

void SellerInterface(Seller& seller)
{
	bool runInterface = true;

	while (runInterface)
	{
		system("cls");

		std::cout << "Hello, Seller!\n";
		seller.printBriefInformation();
		std::cout << '\n';

		std::cout << "Actions you can perform: \n"
			<< "1. View full account info\n"
			<< "2. View active advertisements\n"
			<< "3. Add new advertisement\n"
			<< "4. View purchase offers\n"
			<< "5. Delete account\n"
			<< "0. Log out\n\n"
			<< "Your decisinon: ";

		int decision;
		std::cin >> decision;

		switch (decision)
		{
		case 1:
		{
			system("cls");

			std::cout <<
				"Full information about your account is:\n\n";
			seller.printAllInformation();

			std::cout << "\nPress Enter to continue.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			std::cin.get();
			break;
		}
		case 2:
		{
			system("cls");
			VehiclesContainer seller_container = vehicles_repos.findBySellerId(seller.getId());

			bool exit_loop = false;
			for (auto iter = seller_container.begin(); iter != seller_container.end() && !exit_loop; iter++)
			{
				system("cls");
				(*iter)->printAllInformation();

				std::cout << "\n\n1. View next\n"
					<< "2. Delete\n"
					<< "0. Stop viewing\n\n"
					<< "Your decisinon: ";

				int next_actions;
				std::cin >> next_actions;

				switch (next_actions)
				{
				case 1: break;
				case 2:
				{
					system("cls");

					std::cout << "Are you sure to delete this advertisement?\n"
						<< "1. Yes\n"
						<< "0. No\n"
						<< "Your decisinon: ";

					int deleting;
					std::cin >> deleting;
					if (deleting)
					{
						vehicles_repos.removeFromContainerAndFileById((*iter)->getId(), vehicles_file);
						break;
					}
					else
						break;
				}
				case 0: exit_loop = true; break;
				}
			}
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "What type of vehicle do you want to sell?\n"
				<< "1. Electric car\n"
				<< "2. Gasoline car\n"
				<< "3. Truck\n"
				<< "4. Passenger transport\n"
				<< "0. Go back\n\n"
				<< "Your decisinon: ";

			int vehicle_type;
			std::cin >> vehicle_type;

			system("cls");
			std::cout << "Fill in the information about the car.\n\n";
			switch (vehicle_type)
			{
			case 1:
			{
				ElectricCar electric_car;
				std::cin >> electric_car;

				electric_car.setSellerId(seller.getId());
				vehicles_repos.addVehicleIntoContainerAndFile(std::make_shared<ElectricCar>(electric_car), vehicles_file);

				system("cls");
				std::cout << "A new advetrisement was successfully added.\n"
					<< "Press Enter to continue.\n";
				std::cin.ignore();
				std::cin.get();
				break;
			}
			case 2:
			{
				GasolineCar gasoline_car;
				std::cin >> gasoline_car;

				gasoline_car.setSellerId(seller.getId());
				vehicles_repos.addVehicleIntoContainerAndFile(std::make_shared<GasolineCar>(gasoline_car), vehicles_file);

				system("cls");
				std::cout << "A new advetrisement was successfully added.\n"
					<< "Press Enter to continue.\n";
				std::cin.ignore();
				std::cin.get();
				break;
			}
			case 3:
			{
				Truck truck;
				std::cin >> truck;

				truck.setSellerId(seller.getId());
				vehicles_repos.addVehicleIntoContainerAndFile(std::make_shared<Truck>(truck), vehicles_file);

				system("cls");
				std::cout << "A new advetrisement was successfully added.\n"
					<< "Press Enter to continue.\n";
				std::cin.ignore();
				std::cin.get();
				break;
			}
			case 4:
			{
				PassengerTransport passenger_transport;
				std::cin >> passenger_transport;

				passenger_transport.setSellerId(seller.getId());
				vehicles_repos.addVehicleIntoContainerAndFile(std::make_shared<PassengerTransport>(passenger_transport), vehicles_file);

				system("cls");
				std::cout << "A new advetrisement was successfully added.\n"
					<< "Press Enter to continue.\n";
				std::cin.ignore();
				std::cin.get();
				break;
			}
			case 0: break;
			}
			break;
		}
		case 4:
		{
			system("cls");

			std::map<int, std::vector<int>> seller_offers;
			transactions_repos.findBySellerId(seller.getId(), seller_offers);

			int number_of_offers = 0;
			for (auto iter = seller_offers.begin(); iter != seller_offers.end(); iter++)
			{
				number_of_offers += iter->second.size();
			}

			std::cout << "For now, you have " << number_of_offers << " purchase offers of the following vehicles:\n\n";

			for (auto iter = seller_offers.begin(); iter != seller_offers.end(); iter++)
			{
				vehicles_repos.findById(iter->first)->printBriefInformation();
			}

			std::cout << "\n1. Cancel all offers of some vehicle\n"
				<< "2. View potential buyers of some vehicle\n"
				<< "0. Go back\n\n"
				<< "Your decision: ";
			
			int next_step;
			std::cin >> next_step;

			switch(next_step)
			{
			case 1:
			{
				std::cout << "\nChoose vehicle by id to cancele offers: ";
				int vehicle_id_to_cancel;
				std::cin >> vehicle_id_to_cancel;

				break;
			}
			case 2:
			{

				break;
			}
			case 0: break;
			}

			break;
		}
		case 5:
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
				int seller_id = seller.getId();
				sellers_repos.removeFromContainerAndFileById(seller_id, sellers_file);
				transactions_repos.removeFromContainerAndFileBySellerId(seller_id, transactions_file);
				vehicles_repos.removeFromContainerAndFileBySellerId(seller_id, vehicles_file);
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