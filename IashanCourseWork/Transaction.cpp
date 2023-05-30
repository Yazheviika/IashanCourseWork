#include "Transaction.h"

Transaction::Transaction(int buyer_id, 
	int seller_id, 
	int vehicle_id, 
	Status status)
{
	this->buyer_id = buyer_id;
	this->seller_id = seller_id;
	this->vehicle_id = vehicle_id;
	this->status = status;
}

Transaction::Transaction(const Buyer& buyer, 
	const Seller& seller, 
	const Vehicle& vehicle, 
	Status status)
{
	buyer_id = buyer.getId();
	seller_id = seller.getId();
	vehicle_id = vehicle.getId();
	this->status = status;
}

int Transaction::getBuyerId() { return buyer_id; }

int Transaction::getSellerId() { return seller_id; }

int Transaction::getVehicleId() { return vehicle_id; }

Transaction::Status Transaction::getStatus() { return status; }

void Transaction::setBuyerId(int id) { buyer_id = id; }

void Transaction::setSellerId(int id) { seller_id = id; }

void Transaction::setVehicleId(int id) { vehicle_id = id; }

void Transaction::setStatus(Status status) { this->status = status; }


