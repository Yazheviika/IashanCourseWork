#pragma once
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
#include <map>
#include <vector>
#include "Iterator.h"
#include "Transaction.h"

class TransactionsContainer
{
private:
	std::shared_ptr<Transaction>* data;
	int length;

public:
	TransactionsContainer();

	TransactionsContainer(int size);

	TransactionsContainer(std::string filename);

	~TransactionsContainer();

	TransactionsContainer& operator=(const TransactionsContainer& other);

	int getLength();

	Iterator<std::shared_ptr<Transaction>> begin() const { return data; }

	Iterator<std::shared_ptr<Transaction>> end() const { return data + length; }

	void erase();

	void resize(int new_length);

	void push_back(std::shared_ptr<Transaction> transaction);

	Transaction& operator[](int index);

	void addTransactionIntoContainerAndFile(std::shared_ptr<Transaction> transaction, std::string filename);

	void removeFromContainerAndFileByBuyerAndVehicleId(int buyer_id, int vehicle_id, std::string filename);

	void removeFromContainerAndFileByBuyerId(int buyer_id, std::string filename);

	void removeFromContainerAndFileBySellerId(int seller_id, std::string filename);

	std::shared_ptr<Transaction> findByBuyerAndVehicleId(int buyer_id, int vehicle_id);

	TransactionsContainer findByBuyerId(int buyer_id);

	void findBySellerId(int seller_id, std::map<int, std::vector<int>>& result);
};

