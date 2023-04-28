#include <iostream>
#include "PersonalData.h"
#include "CurrentDate.h"
#include "DatingAgencyUserData.h"


int main()
{
	DatingAgencyUserData blabla("dsfs", 12, 'M', "2342", "dfsdfe", "refefew", "eefwef", 12313);
	std::cout << blabla.getAge();
	return 0;
}