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

	virtual int getLength() override;

	Iterator<std::shared_ptr<Seller>> begin() const { return data; }

	Iterator<std::shared_ptr<Seller>> end() const { return data + length; }

	virtual void erase() override;

	virtual void resize(int new_length) override;

	virtual void push_back(std::shared_ptr<User> user) override;

	virtual void remove(int index) override;

	Seller& operator[](int index);

	virtual void addUserIntoContainerAndFile(std::shared_ptr<User> user, std::string filename) override;

	virtual std::shared_ptr<User> findById(int id) override;

	virtual std::shared_ptr<User> findByLogin(std::string login) override;

	virtual std::shared_ptr<User> findByLoginAndPassword(std::string login, std::string password) override;

private:
	int findMaxId();

	void addIntoFile(const Seller& buyer, std::string filename);

	void removeFromFileById(int id, std::string filename);
};

