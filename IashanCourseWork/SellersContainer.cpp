#include "SellersContainer.h"

SellersContainer::SellersContainer()
	:length(0), data(nullptr) { }

SellersContainer::SellersContainer(int length)
{
	data = new std::shared_ptr<Seller>[length];
	this->length = length;

	for (int i = 0; i < length; i++) {
		data[i] = std::make_shared<Seller>();
	}
}

SellersContainer::SellersContainer(std::string filename)
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

	data = new std::shared_ptr<Seller>[numberOfObjects];
	length = numberOfObjects;

	file_to_read.clear();
	file_to_read.seekg(0, std::ios::beg);

	int index = 0;
	while (std::getline(file_to_read, line))
	{
		Seller seller;
		seller.getDataFromString(line);

		data[index] = std::make_shared<Seller>(seller);
		index++;
	}

	file_to_read.close();
}

SellersContainer::~SellersContainer()
{
	delete[] data;
}

int SellersContainer::getLength() { return length; }

void SellersContainer::erase()
{
	delete[] data;
	data = nullptr;
	length = 0;
}

void  SellersContainer::resize(int new_length)
{
	if (new_length == length)
		return;

	if (new_length <= 0)
	{
		erase();
		return;
	}

	std::shared_ptr<Seller>* new_data = new std::shared_ptr<Seller>[new_length];

	if (length > 0)
	{
		int elementsToCopy = (new_length > length) ? length : new_length;

		for (int i = 0; i < elementsToCopy; i++)
		{
			new_data[i] = std::make_shared<Seller>(*data[i]);
		}
	}

	delete[] data;

	length = new_length;
	data = new_data;
}

void SellersContainer::push_back(std::shared_ptr<User> user)
{
	resize(length + 1);

	std::shared_ptr<Seller> seller = std::dynamic_pointer_cast<Seller>(user);

	data[length - 1] = std::make_shared<Seller>(*seller);
}

Seller& SellersContainer::operator[](int index)
{
	assert(index >= 0 && index < length);
	return *(data[index]);
}

void SellersContainer::addUserIntoContainerAndFile(std::shared_ptr<User> user, std::string filename)
{
	std::shared_ptr<Seller> seller = std::dynamic_pointer_cast<Seller>(user);

	if (length != 0)
		seller->setId(findMaxId() + 1);
	else
		seller->setId(1);
	push_back(seller);
	seller->addIntoFile(filename);
}

void SellersContainer::removeFromContainerAndFileById(int id, std::string filename)
{
	if (length == 1)
	{
		erase();
		return;
	}

	std::shared_ptr<Seller>* new_data = new std::shared_ptr<Seller>[length - 1];

	int new_index = 0;
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getId() != id)
		{
			new_data[new_index] = std::make_shared<Seller>(**iter);
			new_index++;
		}
		else
			(*iter)->deleteFromFile(filename);
	}

	delete[] data;

	--length;
	data = new_data;
}

std::shared_ptr<User> SellersContainer::findById(int id)
{
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getId() == id)
			return *iter;
	}

	return nullptr;
}

std::shared_ptr<User> SellersContainer::findByLogin(std::string login)
{
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getLogin() == login)
			return *iter;
	}

	return nullptr;
}

std::shared_ptr<User> SellersContainer::findByLoginAndPassword(std::string login, std::string password)
{
	std::shared_ptr<Seller> seller = std::dynamic_pointer_cast<Seller>(findByLogin(login));

	if (seller == nullptr)
		return nullptr;

	if (seller->getPassword() == password)
		return seller;

	return nullptr;
}

int SellersContainer::findMaxId()
{
	int maxId = 1;
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getId() > maxId)
			maxId = (*iter)->getId();
	}

	return maxId;
}

