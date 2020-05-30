#pragma once
#include "date.h"

class liabilities
{
public:
	date date;

private:
	// current liabilities
	float creditCards;
	float personalLoans_C;
	float carLoan_C;
	float accountsPayable;

	// non-current liabilities
	float personalLoans_NC;
	float carLoan_NC;
	float morgage;

	// functions
	const float total(const bool justCurrent = false);
	const float yearOverYearChange();
	const float quarterOverQuarterChange();
	const bool loadFromFile();
	const bool saveToFile();
};