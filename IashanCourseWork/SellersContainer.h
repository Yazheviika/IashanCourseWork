#pragma once
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
#include "IUsersContainer.h"
#include "Iterator.h"
#include "Seller.h"

class SellersContainer : public IUsersContainer
{
private:
	std::shared_ptr<Seller>* data;
	int length;

public:
	SellersContainer();

	SellersContainer(int size);

	SellersContainer(std::string filename);

	~SellersContainer();

	int getLength() override;

	Iterator<std::shared_ptr<Seller>> begin() const { return data; }

	Iterator<std::shared_ptr<Seller>> end() const { return data + length; }

	void erase() override;

	void resize(int new_length) override;

	void push_back(std::shared_ptr<User> user) override;

	Seller& operator[](int index);

	void addUserIntoContainerAndFile(std::shared_ptr<User> user, std::string filename) override;

	void removeFromContainerAndFileById(int id, std::string filename) override;

	std::shared_ptr<User> findById(int id) override;

	std::shared_ptr<User> findByLogin(std::string login) override;

	std::shared_ptr<User> findByLoginAndPassword(std::string login, std::string password) override;

private:
	int findMaxId();
};

