#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "display Dependencies.h"

displayScreen viewMenu(displayScreen displayMode);

int selectTimeframe(const std::vector<data>& masterDataList);

void displayTimeFrmae(const std::vector<data>& masterDataList, const int timeframe);

displayScreen addNetWorthActual(std::vector<data>& masterDataList);

displayScreen editOldData(std::vector<data>& masterDataList);

displayScreen editOldData(std::vector<data>& masterDataList, timeStamp& dataToEdit);

displayScreen addNetWorthEstamates(std::vector<data>& masterDataList);