#include "TransactionsContainer.h"

TransactionsContainer::TransactionsContainer()
	:length(0), data(nullptr) { }

TransactionsContainer::TransactionsContainer(int length)
{
	data = new std::shared_ptr<Transaction>[length];
	this->length = length;

	for (int i = 0; i < length; i++) {
		data[i] = std::make_shared<Transaction>();
	}
}

TransactionsContainer::TransactionsContainer(std::string filename)
{
	std::ifstream file_to_read;
	file_to_read.open(filename);

	if (!file_to_read)
	{
		std::cerr << "File " << filename << " couldn`t be opened for writing.\n";
		exit(1);
	}

	int numberOfObjects = 0;
	std::string line;
	while (std::getline(file_to_read, line))
		numberOfObjects++;

	data = new std::shared_ptr<Transaction>[numberOfObjects];
	length = numberOfObjects;

	file_to_read.clear();
	file_to_read.seekg(0, std::ios::beg);

	int index = 0;
	while (std::getline(file_to_read, line))
	{
		Transaction transaction;
		transaction.readDataFromFileString(line);

		data[index] = std::make_shared<Transaction>(transaction);
		index++;
	}

	file_to_read.close();
}

TransactionsContainer::~TransactionsContainer()
{
	delete[] data;
}

TransactionsContainer& TransactionsContainer::operator=(const TransactionsContainer& other)
{
	{
		if (this == &other)
			return *this;

		delete[] data;

		length = other.length;
		data = new std::shared_ptr<Transaction>[length];
		for (int i = 0; i < length; i++)
		{
			if (other.data[i] != nullptr)
			{
				data[i] = std::make_shared< Transaction>(*other.data[i]);
			}
			else
			{
				data[i] = nullptr;
			}
		}

		return *this;
	}
}

int TransactionsContainer::getLength() { return length; }

void TransactionsContainer::erase()
{
	delete[] data;
	data = nullptr;
	length = 0;
}

void  TransactionsContainer::resize(int new_length)
{
	if (new_length == length)
		return;

	if (new_length <= 0)
	{
		erase();
		return;
	}

	std::shared_ptr<Transaction>* new_data = new std::shared_ptr<Transaction>[new_length];

	if (length > 0)
	{
		int elementsToCopy = (new_length > length) ? length : new_length;

		for (int i = 0; i < elementsToCopy; i++)
		{
			new_data[i] = std::make_shared<Transaction>(*data[i]);
		}
	}

	delete[] data;

	length = new_length;
	data = new_data;
}

void TransactionsContainer::push_back(std::shared_ptr<Transaction> transaction)
{
	resize(length + 1);

	data[length - 1] = std::make_shared<Transaction>(*transaction);
}

Transaction& TransactionsContainer::operator[](int index)
{
	assert(index >= 0 && index < length);
	return *(data[index]);
}

void TransactionsContainer::addTransactionIntoContainerAndFile(std::shared_ptr<Transaction> transaction, std::string filename)
{
	if (findByBuyerAndVehicleId(transaction->getBuyerId(), transaction->getVehicleId()) == nullptr)
	{
		push_back(transaction);
		transaction->addIntoFile(filename);

	}
}

void TransactionsContainer::removeFromContainerAndFileByBuyerAndVehicleId(int buyer_id, int vehicle_id, std::string filename)
{
	if (length == 1)
	{
		erase();
		return;
	}

	std::shared_ptr<Transaction>* new_data = new std::shared_ptr<Transaction>[length - 1];

	int new_index = 0;
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getBuyerId() != buyer_id || (*iter)->getVehicleId() != vehicle_id)
		{
			new_data[new_index] = std::make_shared<Transaction>(**iter);
			new_index++;
		}
		else
			(*iter)->deleteFromFile(filename);
	}

	delete[] data;

	--length;
	data = new_data;
}

void TransactionsContainer::removeFromContainerAndFileByBuyerId(int buyer_id, std::string filename)
{
	if (length == 1)
	{
		erase();
		return;
	}

	std::shared_ptr<Transaction>* new_data = new std::shared_ptr<Transaction>[length - 1];

	int new_index = 0;
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getBuyerId() != buyer_id)
		{
			new_data[new_index] = std::make_shared<Transaction>(**iter);
			new_index++;
		}
		else
			(*iter)->deleteFromFile(filename);
	}

	delete[] data;

	--length;
	data = new_data;
}

void TransactionsContainer::removeFromContainerAndFileBySellerId(int seller_id, std::string filename)
{
	if (length == 1)
	{
		erase();
		return;
	}

	std::shared_ptr<Transaction>* new_data = new std::shared_ptr<Transaction>[length - 1];

	int new_index = 0;
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getSellerId() != seller_id)
		{
			new_data[new_index] = std::make_shared<Transaction>(**iter);
			new_index++;
		}
		else
			(*iter)->deleteFromFile(filename);
	}

	delete[] data;

	--length;
	data = new_data;
}

std::shared_ptr<Transaction> TransactionsContainer::findByBuyerAndVehicleId(int buyer_id, int vehicle_id)
{
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getBuyerId() == buyer_id && (*iter)->getVehicleId() == vehicle_id)
		{
			return std::make_shared<Transaction>(**iter);
		}
	}
	return nullptr;
}

TransactionsContainer TransactionsContainer::findByBuyerId(int buyer_id)
{
	TransactionsContainer found_container;

	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getBuyerId() == buyer_id)
			found_container.push_back(std::make_shared<Transaction>(**iter));
	}

	return found_container;
}

void TransactionsContainer::findBySellerId(int seller_id, std::map<int, std::vector<int>>& result)
{
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getSellerId() == seller_id)
		{
			int vehicle_id = (*iter)->getVehicleId();
			int buyer_id = (*iter)->getBuyerId();

			result[vehicle_id].push_back(buyer_id);
		}
	}
}