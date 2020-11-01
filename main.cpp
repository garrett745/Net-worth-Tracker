// Net Worth Project
// Created Aug 15, 2020
// last updated Sept 26, 2020
// version 0.2.1

#include <vector>

#include "display.h"
#include "data.h"
#include "Save function.h"
#include "initialization.h"

#include "gstd header file/gstdmathVect.h"

#define saveLoc "C:\\ProgramData\\test.txt"

int main()
{
	displayScreen selectedMenu = displayScreen::mainmenu;
	std::vector<data> masterDataList; // vector used to store all the data gathered from save file and added onto when user creats new data point

	startupInit(masterDataList, saveLoc);

	while (true)
	{
		switch (selectedMenu)
		{
		case displayScreen::mainmenu:
		{
			selectedMenu = viewMenu(displayScreen::mainmenu);
			continue; // goes back to switch(selectedMenu) to go into new menu
		}
		case displayScreen::viewdata:
		{
			int timeframe;
			viewMenu(displayScreen::viewdata); // just adds "View Data" to top of page 
			timeframe = selectTimeframe(masterDataList); // allowes the user to select a particular year or all data
			if (timeframe == -2) // go back to main menu
			{
				selectedMenu = displayScreen::mainmenu;
				continue;
			}
			displayTimeFrmae(masterDataList, timeframe);
			continue;
		}
		case displayScreen::enternewdata:
		{
			selectedMenu = viewMenu(displayScreen::enternewdata); // allows the user to select either add new Net Worth or add new estimates
			switch (selectedMenu)
			{
			case displayScreen::networthactual:
			{
				selectedMenu = addNetWorthActual(masterDataList);
				continue;
			}
			case displayScreen::networthestamates:
			{
				selectedMenu = addNetWorthEstamates(masterDataList);
				continue;
			}
			}

			continue;
		}
		case displayScreen::reviseestamates:
		{
			continue;
		}
		case displayScreen::editold:
		{
			continue;
		}
		case displayScreen::savequit:
		{
			if (viewMenu(displayScreen::savequit) == displayScreen::savequit)
			{
				saveToFile();
				return 0;
			}
			else
			{
				selectedMenu = displayScreen::mainmenu;
				continue;
			}
		}
		case displayScreen::quitnosave:
		{
			if (viewMenu(displayScreen::quitnosave) == displayScreen::quitnosave)
			{
				return 0;
			}
			else
			{
				selectedMenu = displayScreen::mainmenu;
				continue;
			}
		}
		}
	}
	return 0;
}