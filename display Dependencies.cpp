#include "display Dependencies.h"

bool checkIfValidNum(std::string input)
{
	try
	{
		float numToCheck = std::stof(input);

		return true;
	}
	catch (std::invalid_argument)
	{
		std::cout << "ERROR: \"invalid_argument\" the input was not convertable to a number\n";
		return false;
	}
	catch (std::out_of_range) {
		std::cout << "ERROR: \"out_of_range\" the input was not convertable to a number\n";
		return false;
	}
}

float roundDecimalNumber(float numToRound, int numOfPlaces)
{
	if (numToRound > 0)
	{
		if (numOfPlaces == 0)
		{
			return (int)(numToRound + 0.5);
		}
		numToRound = (int)(numToRound * (pow(10, numOfPlaces)) + .5);
		return (float)(numToRound / (pow(10, numOfPlaces)));
	}
	else
	{
		if (numOfPlaces == 0)
		{
			return (int)(numToRound - 0.5);
		}
		numToRound = (int)(numToRound * (pow(10, numOfPlaces)) - .5);
		return (float)(numToRound / (pow(10, numOfPlaces)));
	}
}

int getLimitedInt(std::vector<int> possableValues, size_t numOfPossableAns, bool allowRounding)
{
	std::string input;
	float numToCheck = 0;
	while (true)
	{
		std::cout << "Input: ";		std::cin >> input;		std::cout << std::endl;

		if (input == "quit")
		{
			return false;
		}

		if (checkIfValidNum(input) == true)
		{
			if (allowRounding)
			{
				numToCheck = roundDecimalNumber(std::stof(input));
				if (std::stof(input) != numToCheck)
				{
					std::cout << "non-integer number detected, rounding to nearest int value\n";
				}
			}
			else
			{
				numToCheck = std::stof(input);
			}
			for (int i = 0; i < numOfPossableAns; i++)
			{
				if (possableValues[i] == numToCheck)
				{
					return numToCheck;
				}
			}
		}
		std::cout << "Invalid Input: please try again\n";
	}
}

int getAnyInt(bool allowRounding, bool allowNegatives)
{
	std::string input;
	int numToCheck = 0;
	while (true)
	{
		std::cout << "Input: ";		std::cin >> input;		std::cout << std::endl;

		if (input == "quit")
		{
			return false;
		}

		if (checkIfValidNum(input) == true)
		{
			if (!allowNegatives)
			{
				if (std::stof(input) < 0)
				{
					std::cout << "Negative number detected, please enter 0 or a positive number\n";
					continue;
				}
			}
			if (allowRounding)
			{
				numToCheck = roundDecimalNumber(std::stof(input));
				if (std::stof(input) != numToCheck)
				{
					std::cout << "non-integer number detected, rounding to nearest int value\n";
				}
			}
			else
			{
				if (std::stof(input) == roundDecimalNumber(std::stof(input)))
				{
					numToCheck = std::stof(input);
				}
				else
				{
					std::cout << "Invalid Input: please try again\n";
					continue;
				}
			}
			return numToCheck;
		}
		else
		{
			std::cout << "Invalid Input: please try again\n";
		}
	}
}

void setInputValues(std::vector<int>& inputValues, int maxInputValue)
{
	for (int i = 0; i < maxInputValue; i++)
	{
		inputValues.push_back(i + 1);
	}
	return;
}

displayScreen getReturnValue(int optionSelection, displayScreen displayMode)
{
	switch (displayMode)
	{
	case displayScreen::mainmenu:
	{
		switch (optionSelection)
		{
		case 1: return displayScreen::viewdata;
		case 2: return displayScreen::enternewdata;
		case 3: return displayScreen::reviseestamates;
		case 4: return displayScreen::editold;
		case 5: return displayScreen::savequit;
		case 6: return displayScreen::quitnosave;
		}
	}
	}
}

bool CheckSort(const std::vector<int>& array, int size, bool reverse)
{
	if (size == 1 || size == 0)
	{
		return true;
	}

	switch (reverse)
	{
	case false:
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				return false;
			}
		}
		return true;
	}
	case true:
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i] < array[i + 1])
			{
				return false;
			}
		}
		return true;
	}
	}
}

void selectionSort(std::vector<int>& array, int size, bool reverse)
{
	switch (reverse)
	{
	case false:
	{
		int smallestIndex;
		int buffer;

		for (int index = 0; index < size - 1; index++)
		{
			smallestIndex = index;

			for (int location = index + 1; location < size; location++)
			{
				if (array[location] < array[smallestIndex])
				{
					smallestIndex = location;
				}
			}

			buffer = array[smallestIndex];
			array[smallestIndex] = array[index];
			array[index] = buffer;
		}
		break;
	}
	case true:
	{
		int biggestIndex;
		int buffer;

		for (int index = 0; index < size - 1; index++)
		{
			biggestIndex = index;

			for (int location = index + 1; location < size; location++)
			{
				if (array[location] > array[biggestIndex])
				{
					biggestIndex = location;
				}
			}

			buffer = array[biggestIndex];
			array[biggestIndex] = array[index];
			array[index] = buffer;
		}
		break;
	}
	}

	return;
}

void getYearRange(const std::vector<data>& masterDataList, std::vector<int>& yearRange)
{
	for (int i = 0; i < masterDataList.size(); i++)
	{
		if (!yearRange.empty())
		{
			for (int i2 = 0; i2 < yearRange.size(); i2++)
			{
				if (yearRange[i2] == masterDataList[i].timeStamp.year)
				{
					break;
				}
				if (i2 == yearRange.size() - 1)
				{
					yearRange.push_back(masterDataList[i].timeStamp.year);
					break;
				}
			}
		}
		else 
		{
			yearRange.push_back(masterDataList[i].timeStamp.year);
		}
	}

	if (CheckSort(yearRange, yearRange.size(), true) != true)
	{
		selectionSort(yearRange, yearRange.size(), true);
	}

	return;
}

void displayAll(const std::vector<data>& masterDataList)
{
	std::vector<int> yearRange;

	getYearRange(masterDataList, yearRange);

	//order correctly

	for (int i = 0; i < masterDataList.size(); i++)
	{
		std::cout << masterDataList[i].stringFormat();
	}
	return;
}

void displayYear(const std::vector<data>& masterDataList, const int timeframe)
{
	for (int i = 0; i < masterDataList.size(); i++)
	{
		if (masterDataList[i].timeStamp.year != timeframe)
		{
			continue;
		}
		std::cout << masterDataList[i].stringFormat();
	}
	return;
}