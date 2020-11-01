#include "display.h"
#include <stdlib.h>

displayScreen viewMenu(displayScreen displayMode)
{
	system("CLS");
	std::vector<int> inputValues;
	switch (displayMode)
	{
	case displayScreen::mainmenu:
	{
		std::cout << "Main Menu" << std::endl << std::endl
			<< "1: view data" << std::endl
			<< "2: enter new data" << std::endl
			<< "3: revise net worth estamates" << std::endl
			<< "4: edit old data" << std::endl
			<< "5: save and quit" << std::endl
			<< "6: quit without saving" << std::endl << std::endl;

		setInputValues(inputValues, 6);
		break;
	}
	case displayScreen::viewdata:
	{
		std::cout << "View Data" << std::endl << std::endl;
		return displayScreen::viewdata; // return the current position & does nothing & continues into the view data from the main
	}
	case displayScreen::enternewdata:
	{
		int switchValue;
		std::cout << "Enter New Data" << std::endl << std::endl
			<< "1: Enter new Net worth" << std::endl
			<< "2: Enter new Net Worth Estamates" << std::endl;
		setInputValues(inputValues, 2);
		switchValue = getLimitedInt(inputValues, inputValues.size(), true);

		if (switchValue == 1)
		{
			return displayScreen::networthactual;
		}
		else
		{
			return displayScreen::networthestamates;
		}
	}
	case displayScreen::reviseestamates:
	{

	}
	case displayScreen::editold:
	{

	}
	case displayScreen::savequit:
	{
		{
			std::cout << "Save and Quit" << std::endl
				<< "are you sure?" << std::endl << std::endl

				<< "1: yes" << std::endl
				<< "2: no" << std::endl << std::endl;

			setInputValues(inputValues, 2);
			if (getLimitedInt(inputValues, inputValues.size(), true) == 2)
			{
				return displayScreen::mainmenu;
			}
			return displayScreen::savequit;
		}
	}
	case displayScreen::quitnosave: // called when you select save without quit but do not confirm the selection
	{
		std::cout << "Quiting without saving" << std::endl
			<< "are you sure?" << std::endl << std::endl

			<< "1: yes" << std::endl
			<< "2: no" << std::endl << std::endl;

		setInputValues(inputValues, 2);
		if (getLimitedInt(inputValues, inputValues.size(), true) == 2)
		{
			return displayScreen::mainmenu;
		}
		return displayScreen::quitnosave;
	}
	}

	return getReturnValue(getLimitedInt(inputValues, inputValues.size(), true), displayMode);
}

int selectTimeframe(const std::vector<data>& masterDataList)
{
	int userSelection;
	std::vector<int> yearRange;
	getYearRange(masterDataList, yearRange);

	std::vector<int> inputValues;
	setInputValues(inputValues, 1 + yearRange.size());

	std::cout << "1: view all data" << std::endl;
	for (int i = 0; i < yearRange.size(); i++)
	{
		std::cout << i + 2 << ": " << "view " << yearRange[i] << " data" << std::endl;
	}

	userSelection = getLimitedInt(inputValues, inputValues.size(), true);
	if (userSelection == false)
	{
		return -2; // go back to previous menu
	}
	else if (userSelection == 1)
	{
		return -1; // view all data
	}
	else
	{
		return yearRange[userSelection - 2]; // view year range data
	}
}

void displayTimeFrmae(const std::vector<data>& masterDataList, const int timeframe)
{
	system("CLS");

	if (timeframe == -1)
	{
		std::cout << "View All Data" << std::endl << std::endl;
		displayAll(masterDataList);
	}
	else
	{
		std::cout << "View " << timeframe << " Data" << std::endl << std::endl;
		displayYear(masterDataList, timeframe);
	}

	std::cout << "enter \"quit\" to exit" << std::endl;
	std::vector<int> inputValues;
	while (getLimitedInt(inputValues, inputValues.size(), true) != false)
	{
		continue;
	}
}

displayScreen addNetWorthActual(std::vector<data>& masterDataList)
{
	std::vector<int> inputValues;
	data newData;

	std::cout << "Enter the year you want to add new data to" << std::endl;
	newData.timeStamp.year = getAnyInt(true, false);

	std::cout << "Enter the quarter you want to add new data to" << std::endl;
	setInputValues(inputValues, 4);
	newData.timeStamp.quarter = getLimitedInt(inputValues, inputValues.size(), true);

	if (timestampExists(newData.timeStamp, masterDataList))
	{
		std::cout << "data for this period already exists" << std::endl
			<< "as this is a work in progress, the ability to edit old data" << std::endl;
		return displayScreen::reviseestamates;
	}

	std::cout << "Enter the Net Worth for the period ending Q" << newData.timeStamp.quarter << " " << newData.timeStamp.year << std::endl;
	newData.netWorthA = getAnyInt(true, true);

	std::cout << newData.stringFormat()
		<< "are you sure you would like to add this data?" << std::endl;

	std::cout << "1: yes" << std::endl
		<< "2: no" << std::endl;
	inputValues.clear();
	setInputValues(inputValues, 2);
	if (getLimitedInt(inputValues, inputValues.size(), true) == 1)
	{
		masterDataList.push_back(newData);
	}
	return displayScreen::mainmenu;
}

displayScreen editOldData(std::vector<data>& masterDataList)
{
	return displayScreen::mainmenu;
}

displayScreen editOldData(std::vector<data>& masterDataList, timeStamp& dataToEdit)
{
	return displayScreen::mainmenu;
}

displayScreen addNetWorthEstamates(std::vector<data>& masterDataList)
{
	return displayScreen::mainmenu;
}