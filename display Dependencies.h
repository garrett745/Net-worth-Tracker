#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "data.h"

enum class displayScreen { mainmenu, viewdata, enternewdata, reviseestamates, editold, savequit, quitnosave, networthactual, networthestamates};

bool checkIfValidNum(std::string input);

float roundDecimalNumber(float numToRound, int numOfPlaces = 0);

int getLimitedInt(std::vector<int> possableValues, size_t numOfPossableAns, bool allowRounding);

int getAnyInt(bool allowRounding = true, bool allowNegatives = true);

void setInputValues(std::vector<int>& inputValues, int maxInputValue);

displayScreen getReturnValue(int optionSelection, displayScreen displayMode);

bool CheckSort(const std::vector<int>& array, int size, bool reverse = false);

void selectionSort(std::vector<int>& array, int size, bool reverse = false);

void getYearRange(const std::vector<data>& masterDataList, std::vector<int>& yearRange);

void displayAll(const std::vector<data>& masterDataList);

void displayYear(const std::vector<data>& masterDataList, const int timeframe);