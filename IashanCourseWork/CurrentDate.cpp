#include <iostream>
#include <chrono>
#include <ctime>

#include "CurrentDate.h"

CurrentDate::CurrentDate()
{
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_t = std::chrono::system_clock::to_time_t(now);
	current_date = *std::localtime(&now_t);
}

const std::tm& CurrentDate::getCurrentDate()
{
	return current_date;
}
