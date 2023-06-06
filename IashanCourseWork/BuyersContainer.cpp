#include "BuyersContainer.h"

BuyersContainer::BuyersContainer()
	:length(0), data(nullptr) { }

BuyersContainer::BuyersContainer(int length)
{
	data = new std::shared_ptr<Buyer>[length];
	this->length = length;

	for (int i = 0; i < length; i++) {
		data[i] = std::make_shared<Buyer>();
	}
}

BuyersContainer::BuyersContainer(std::string filename)
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

	data = new std::shared_ptr<Buyer>[numberOfObjects];
	length = numberOfObjects;

	file_to_read.clear();
	file_to_read.seekg(0, std::ios::beg);

	int index = 0;
	while (std::getline(file_to_read, line))
	{
		std::istringstream stringAsStream(line);

		Buyer buyer;
		stringAsStream >> buyer;//////////////////////////////////////////////

		data[index] = std::make_shared<Buyer>(buyer);
		index++;
	}

	file_to_read.close();
}

BuyersContainer::~BuyersContainer()
{
	delete[] data;
}

int BuyersContainer::getLength() { return length; }

void BuyersContainer::erase()
{
	delete[] data;
	data = nullptr;
	length = 0;
}

void  BuyersContainer::resize(int new_length)
{
	if (new_length == length)
		return;

	if (new_length <= 0)
	{
		erase();
		return;
	}

	std::shared_ptr<Buyer>* new_data = new std::shared_ptr<Buyer>[new_length];

	if (length > 0)
	{
		int elementsToCopy = (new_length > length) ? length : new_length;

		for (int i = 0; i < elementsToCopy; i++)
		{
			new_data[i] = std::make_shared<Buyer>(*data[i]);
		}
	}

	delete[] data;

	length = new_length;
	data = new_data;
}

void BuyersContainer::push_back(std::shared_ptr<User> user)
{
	resize(length + 1);

	std::shared_ptr<Buyer> buyer = std::dynamic_pointer_cast<Buyer>(user);

	data[length - 1] = std::make_shared<Buyer>(*buyer);
}

Buyer& BuyersContainer::operator[](int index)
{
	assert(index >= 0 && index < length);
	return *(data[index]);
}

void BuyersContainer::addUserIntoContainerAndFile(std::shared_ptr<User> user, std::string filename)
{
	std::shared_ptr<Buyer> buyer = std::dynamic_pointer_cast<Buyer>(user);

	if (length != 0)
		buyer->setId(findMaxId() + 1);
	else
		buyer->setId(1);
	push_back(buyer);
	buyer->addIntoFile(filename);
}

void BuyersContainer::removeFromContainerAndFileById(int id, std::string filename)
{
	if (length == 1)
	{
		erase();
		return;
	}

	std::shared_ptr<Buyer>* new_data = new std::shared_ptr<Buyer>[length - 1];

	int new_index = 0;
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getId() != id)
		{
			new_data[new_index] = std::make_shared<Buyer>(**iter);
			new_index++;
		}
		else
			(*iter)->deleteFromFile(filename);
	}

	delete[] data;

	--length;
	data = new_data;
}

std::shared_ptr<User> BuyersContainer::findById(int id)
{
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getId() == id)
			return *iter;
	}

	return nullptr;
}

std::shared_ptr<User> BuyersContainer::findByLogin(std::string login)
{
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getLogin() == login)
			return *iter;
	}

	return nullptr;
}

std::shared_ptr<User> BuyersContainer::findByLoginAndPassword(std::string login, std::string password)
{
	std::shared_ptr<Buyer> buyer = std::dynamic_pointer_cast<Buyer>(findByLogin(login));

	if (buyer == nullptr)
		return nullptr;

	if (buyer->getPassword() == password)
		return buyer;

	return nullptr;
}

int BuyersContainer::findMaxId()
{
	int maxId = 1;
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getId() > maxId)
			maxId = (*iter)->getId();
	}

	return maxId;
}

