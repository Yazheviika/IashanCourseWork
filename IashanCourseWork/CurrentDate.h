#pragma once
class CurrentDate
{
private:
	std::tm current_date;

public:
	CurrentDate();
		
	const std::tm& getCurrentDate();
	
};

