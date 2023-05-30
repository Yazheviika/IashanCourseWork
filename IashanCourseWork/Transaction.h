#pragma once
#include "Buyer.h"
#include "Seller.h"
#include "Vehicle.h"

class Transaction
{
public:
	enum class Status { Active, Pending,  Sold };

private:
	int buyer_id;
	int seller_id;
	int vehicle_id;
	Status status;

public:
	Transaction(int buyer_id = 0, int seller_id = 0, int vehicle_id = 0, Status status = Status::Active);

	Transaction(const Buyer &buyer, const Seller &seller, const Vehicle &vehicle, Status status = Status::Active);

	int getBuyerId();

	int getSellerId();

	int getVehicleId();

	Status getStatus();

	void setBuyerId(int id);

	void setSellerId(int id);

	void setVehicleId(int id);

	void setStatus(Status status);
};

