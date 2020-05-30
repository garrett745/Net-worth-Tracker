#include "Assets.h"

assets::assets()
{
	saveToFile();
}

const float assets::total(const bool justCurrent)
{
	float total = 0;

	total += shortTermInvestments + cash + accountsRecivable;

	if (!justCurrent)
	{
		total += longTermInvestments + property + vehicles + other;
	}

	return total;
}

const bool assets::checkIfFileExists()
{
	std::ifstream inFile("C:\\ProgramData\\NetWorth");

	if (inFile.get() == EOF)
	{
		return false;
	}
	else
	{
		return true;
	}
}

const bool assets::saveToFile()
{
	std::ofstream inFile("C:\\ProgramData\\NetWorth");

	if (inFile)
	{
		if (checkIfFileExists() == true)
		{

		}
	}
	else
	{
		return false;
	}
}