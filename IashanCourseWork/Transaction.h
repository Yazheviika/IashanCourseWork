#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "TransactionStatus.h"
#include "Buyer.h"
#include "Seller.h"
#include "Vehicle.h"

class Transaction
{
private:
	int buyer_id;
	int seller_id;
	int vehicle_id;
	TransactionStatus status;

public:
	Transaction(int buyer_id = 0, int seller_id = 0, int vehicle_id = 0, int Status = 1);

	Transaction(const Buyer &buyer, const Seller &seller, const Vehicle &vehicle, TransactionStatus status = TransactionStatus::Pending);

	int getBuyerId() const;

	int getSellerId() const;

	int getVehicleId() const;

	TransactionStatus getStatus() const;

	void setBuyerId(int id);

	void setSellerId(int id);

	void setVehicleId(int id);

	void setStatus(TransactionStatus Status);

	void addIntoFile(std::string filename) const;

	void deleteFromFile(std::string filename) const;

	void readDataFromFileString(std::string string_to_tokenize);

	friend std::ostream& operator<<(std::ostream& out, const Transaction& transaction);
};

