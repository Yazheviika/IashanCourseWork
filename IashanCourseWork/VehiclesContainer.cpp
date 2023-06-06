#include "VehiclesContainer.h"

VehiclesContainer::VehiclesContainer()
	:length(0), data(nullptr) { }

VehiclesContainer::VehiclesContainer(int length)
{
	data = new std::shared_ptr<Vehicle>[length];
	this->length = length;

	for (int i = 0; i < length; i++) {
		data[i] = nullptr;
	}
}

VehiclesContainer::VehiclesContainer(std::string filename)
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

	data = new std::shared_ptr<Vehicle>[numberOfObjects];
	length = numberOfObjects;

	for (int i = 0; i < length; i++) {
		data[i] = nullptr;
	}

	file_to_read.clear();
	file_to_read.seekg(0, std::ios::beg);

	int index = 0;
	while (getline(file_to_read, line))
	{
		std::istringstream stringAsStream(line);
		std::string token;
		getline(stringAsStream, token, ':');
		char vehicle_type = token[0];

		getline(stringAsStream, token);

		switch (vehicle_type)
		{
		case 'E':
		{
			ElectricCar vehicle;
			vehicle.getDataFromString(token);
			data[index] = std::make_shared<ElectricCar>(vehicle);

			break;
		}
		case 'G':
		{
			GasolineCar vehicle;
			vehicle.getDataFromString(token);
			data[index] = std::make_shared<GasolineCar>(vehicle);

			break;
		}
		case 'P':
		{
			PassengerTransport vehicle;
			vehicle.getDataFromString(token);
			data[index] = std::make_shared<PassengerTransport>(vehicle);

			break;
		}
		case 'T':
		{
			Truck vehicle;
			vehicle.getDataFromString(token);
			data[index] = std::make_shared<Truck>(vehicle);

			break;
		}
		}

		index++;
	}

	file_to_read.close();
}

VehiclesContainer::VehiclesContainer(const VehiclesContainer& other)
{
	length = other.length;
	data = new std::shared_ptr<Vehicle>[length];

	for (int i = 0; i < length; i++)
	{
		if (other.data[i] != nullptr)
		{
			other.data[i]->clone(data[i]);
		}
		else
		{
			data[i] = nullptr;
		}
	}
}

VehiclesContainer::~VehiclesContainer()
{
	delete[] data;
}

VehiclesContainer& VehiclesContainer::operator=(const VehiclesContainer& other)
{
	if (this == &other)
		return *this;

	delete[] data;

	length = other.length;
	data = new std::shared_ptr<Vehicle>[length];
	for (int i = 0; i < length; i++)
	{
		if (other.data[i] != nullptr)
		{
			other.data[i]->clone(data[i]);
		}
		else
		{
			data[i] = nullptr;
		}
	}

	return *this;
}

int VehiclesContainer::getLength() const { return length; }

Iterator<std::shared_ptr<Vehicle>> VehiclesContainer::begin() const { return data; }

Iterator<std::shared_ptr<Vehicle>> VehiclesContainer::end() const { return data + length; }

void VehiclesContainer::erase()
{
	delete[] data;
	data = nullptr;
	length = 0;
}

void  VehiclesContainer::resize(int new_length)
{
	if (new_length == length)
		return;

	if (new_length <= 0)
	{
		erase();
		return;
	}

	std::shared_ptr<Vehicle>* new_data = new std::shared_ptr<Vehicle>[new_length];

	if (length > 0)
	{
		int elementsToCopy = (new_length > length) ? length : new_length;

		for (int i = 0; i < elementsToCopy; i++)
			data[i]->clone(new_data[i]);
	}

	delete[] data;

	length = new_length;
	data = new_data;
}

void VehiclesContainer::push_back(std::shared_ptr<Vehicle> vehicle)
{
	resize(length + 1);

	data[length - 1] = vehicle;
}

void VehiclesContainer::removeFromContainerAndFileById(int id, std::string filename)
{
	if (length == 1)
	{
		erase();
		return;
	}

 	std::shared_ptr<Vehicle>* new_data = new std::shared_ptr<Vehicle>[length - 1];
	
	int new_index = 0;
	for (int i = 0; i < length; i++) {
		if (data[i]->getId() != id) {
			data[i]->clone(new_data[new_index]);
			new_index++;
		}
		else
		{
			data[i]->deleteFromFile(filename);
		}
	}

	delete[] data;

	--length;
	data = new_data;
}

void VehiclesContainer::removeFromContainerAndFileBySellerId(int seller_id, std::string filename)
{
	if (length == 1)
	{
		erase();
		return;
	}

	std::shared_ptr<Vehicle>* new_data = new std::shared_ptr<Vehicle>[length - 1];

	int new_index = 0;
	for (int i = 0; i < length; i++) {
		if (data[i]->getSellerId() != seller_id) {
			data[i]->clone(new_data[new_index]);
			new_index++;
		}
		else
		{
			data[i]->deleteFromFile(filename);
		}
	}

	delete[] data;

	--length;
	data = new_data;
}

Vehicle& VehiclesContainer::operator[](int index)
{
	assert(index >= 0 && index < length);
	return *(data[index]);
}

void VehiclesContainer::addVehicleIntoContainerAndFile(std::shared_ptr<Vehicle> vehicle, std::string filename)
{
	if (length != 0)
		vehicle->setId(findMaxId() + 1);
	else
		vehicle->setId(1);
	push_back(vehicle);
	vehicle->addIntoFile(filename);
}

std::shared_ptr<Vehicle> VehiclesContainer::findById(int id) const
{
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getId() == id)
		{
			std::shared_ptr<Vehicle> new_ptr;
			(*iter)->clone(new_ptr);
			
			return new_ptr;
		}
	}
	return nullptr;
}

VehiclesContainer VehiclesContainer::findByModel(std::string model) const
{
	VehiclesContainer subcontainer;
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getModel().find(model) != std::string::npos)
		{
			std::shared_ptr<Vehicle> new_ptr;
			(*iter)->clone(new_ptr);
			subcontainer.push_back(new_ptr);
		}
	}
	return subcontainer;
}

VehiclesContainer VehiclesContainer::findByPrice(int min_price, int max_price) const
{
	VehiclesContainer subcontainer;
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getPriceInUAH() >= min_price && (*iter)->getPriceInUAH() <= max_price)
		{
			std::shared_ptr<Vehicle> new_ptr;
			(*iter)->clone(new_ptr);
			subcontainer.push_back(new_ptr);
		}
	}
	return subcontainer;
}

VehiclesContainer VehiclesContainer::findByType(VehicleTypes type) const
{
	VehiclesContainer subcontainer;
	switch (type)
	{
	case VehicleTypes::ElectricCar:
	{
		for (auto iter = begin(); iter != end(); iter++)
		{
			if (std::dynamic_pointer_cast<ElectricCar>(*iter) != nullptr)
			{
				std::shared_ptr<Vehicle> new_ptr;
				(*iter)->clone(new_ptr);
				subcontainer.push_back(new_ptr);
			}
		}
		break;
	}
	case VehicleTypes::GasolineCar:
	{
		for (auto iter = begin(); iter != end(); iter++)
		{
			if (std::dynamic_pointer_cast<GasolineCar>(*iter) != nullptr)
				subcontainer.push_back(*iter);
		}
		break;
	}
	case VehicleTypes::Truck:
	{
		for (auto iter = begin(); iter != end(); iter++)
		{
			if (std::dynamic_pointer_cast<Truck>(*iter) != nullptr)
				subcontainer.push_back(*iter);
		}
		break;
	}
	case VehicleTypes::PassengerTransport:
	{
		for (auto iter = begin(); iter != end(); iter++)
		{
			if (std::dynamic_pointer_cast<PassengerTransport>(*iter) != nullptr)
				subcontainer.push_back(*iter);
		}
		break;
	}
	}

	return subcontainer;
}

int VehiclesContainer::findMaxId() const
{
	int maxId = 1;
	for (auto iter = begin(); iter != end(); iter++)
	{
		if ((*iter)->getId() > maxId)
			maxId = (*iter)->getId();
	}

	return maxId;
}
