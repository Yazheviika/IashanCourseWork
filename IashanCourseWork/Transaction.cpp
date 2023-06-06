#include "Transaction.h"

Transaction::Transaction(int buyer_id, 
	int seller_id, 
	int vehicle_id, 
	int Status)
{
	this->buyer_id = buyer_id;
	this->seller_id = seller_id;
	this->vehicle_id = vehicle_id;
	this->status = static_cast<TransactionStatus>(Status);
}

Transaction::Transaction(const Buyer& buyer, 
	const Seller& seller, 
	const Vehicle& vehicle, 
	TransactionStatus status)
{
	buyer_id = buyer.getId();
	seller_id = seller.getId();
	vehicle_id = vehicle.getId();
	this->status = status;
}

int Transaction::getBuyerId() const { return buyer_id; }

int Transaction::getSellerId() const { return seller_id; }

int Transaction::getVehicleId() const { return vehicle_id; }

TransactionStatus Transaction::getStatus() const { return status; }

void Transaction::setBuyerId(int id) { buyer_id = id; }

void Transaction::setSellerId(int id) { seller_id = id; }

void Transaction::setVehicleId(int id) { vehicle_id = id; }

void Transaction::setStatus(TransactionStatus Status) { this->status = Status; }

void Transaction::addIntoFile(std::string filename) const
{
	std::ofstream file_to_write(filename, std::ios::app);
	if (!file_to_write)
	{
		std::cerr << "File " << filename << " couldn`t be opened for writing.\n";
		exit(1);///////////
	}
	file_to_write
		<< getBuyerId() << ','
		<< getSellerId() << ','
		<< getVehicleId() << ','
		<< static_cast<int>(getStatus()) << '\n';

	file_to_write.close();
}

void Transaction::deleteFromFile(std::string filename) const
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

	std::string transaction;
	while (getline(file_to_read, transaction))
	{
		std::istringstream stringAsStream(transaction);
		std::string buyer_id;
		getline(stringAsStream, buyer_id, ',');

		std::string token;
		getline(stringAsStream, token, ',');

		std::string vehicle_id;
		getline(stringAsStream, vehicle_id, ',');

		if (std::stoi(buyer_id) != this->buyer_id || (std::stoi(vehicle_id) != this->vehicle_id))
			temporary_file << transaction << '\n';
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

	while (getline(file_to_copy_from, transaction))
		file_to_copy << transaction << '\n';

	file_to_copy.close();
	file_to_copy_from.close();

	int Status = std::remove("Files/temp.txt");
	if (Status != 0)
		std::cerr << "Temporary file couldn`t be removed.\n";
}

void Transaction::readDataFromFileString(std::string string_to_tokenize)
{
	std::istringstream stringAsStream(string_to_tokenize);
	std::string token;

	std::getline(stringAsStream, token, ',');
	setBuyerId(std::stoi(token));

	std::getline(stringAsStream, token, ',');
	setSellerId(std::stoi(token));

	std::getline(stringAsStream, token, ',');
	setVehicleId(std::stoi(token));

	std::getline(stringAsStream, token, ',');
	setStatus(static_cast<TransactionStatus>(std::stoi(token)));
}

std::ostream& operator<<(std::ostream& out, const Transaction& transaction)
{
	out << "Buyer ID: " << transaction.buyer_id << std::endl;
	out << "Seller ID: " << transaction.seller_id << std::endl;
	out << "Vehicle ID: " << transaction.vehicle_id << std::endl;
	out << "Status: ";
	switch (transaction.status)
	{
	case TransactionStatus::Pending:
		out << "Pending";
		break;
	case TransactionStatus::Sold:
		out << "Sold";
		break;
	case TransactionStatus::Canceled:
		out << "Canceled";
		break;
	}
	out << std::endl;

	return out;
}
