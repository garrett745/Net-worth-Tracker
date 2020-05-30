#pragma once

#include <fstream>
#include <string>

#include "date.h"

class assets
{
public:
	date date;

	// constructers
	assets();
	// public functions
	const float total(const bool justCurrent = false);
	const float yearOverYearChange();
	const float quarterOverQuarterChange();

private:
	// current assets
	float shortTermInvestments;
	float cash;
	float accountsRecivable;

	// non-current assets
	float longTermInvestments;
	float property;
	float vehicles;
	float other;

	// private functions
	const bool loadFromFile();
	const bool saveToFile();
	const bool checkIfFileExists();
};