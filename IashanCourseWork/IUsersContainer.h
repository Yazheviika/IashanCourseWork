#pragma once

#include <memory>
#include <string>
#include "Iterator.h"
#include "User.h"

class IUsersContainer
{
public:
	virtual int getLength() = 0;

	virtual void erase() = 0;

	virtual void resize(int new_length) = 0;

	virtual void push_back(std::shared_ptr<User> user) = 0;

	virtual void remove(int index) = 0;

	virtual void addUserIntoContainerAndFile(std::shared_ptr<User> user, std::string filename) = 0;

	virtual std::shared_ptr<User> findById(int id) = 0;

	virtual std::shared_ptr<User> findByLogin(std::string login) = 0;

	virtual std::shared_ptr<User> findByLoginAndPassword(std::string login, std::string password) = 0;
};