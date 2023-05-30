#pragma once
#include <sqlite3.h>

class BaseEntity
{
private:
	int id;

public:
	BaseEntity();

	int getId() const;

	void setId(int id);

	virtual void printAllInformation() = 0;

	virtual void printBriefInformation() = 0;
};

