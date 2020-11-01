#pragma once
#include "initialization dependencies.h"

void startupInit(std::vector<data>& masterDataList, std::string saveLoc)
{
	std::ifstream saveFile(saveLoc);
	std::string Sbuffer;
	std::string Sbuffer2;
	data Dbuffer;

	while (!saveFile.eof())
	{
		//file text size verrables
		static const int startFirstNum = 11; // changes MANUALY depending on text leading up to first number
		int startSecondNum = 0; // changes AUTOMATICALLY depending on size of first number
		static const int disatnceToSecondNum = 21; // changes MANUALY depending on text leading between end of first number to start of second


		std::getline(saveFile, Sbuffer); // gets time data
		Dbuffer.timeStamp = Sbuffer;
		
		std::getline(saveFile, Sbuffer); // gets net worth data

		int endingLocIterator = 0; // moves to find end of the number in text file
		do
		{
			Sbuffer2.push_back(Sbuffer[startFirstNum + endingLocIterator]);
		} while (Sbuffer[startFirstNum + ++endingLocIterator] != ' ');

		Dbuffer.netWorthA = std::stoi(Sbuffer2);

		startSecondNum = startFirstNum + endingLocIterator + disatnceToSecondNum;  //find start of net worth estimate
		endingLocIterator = 0; // reset iterator
		Sbuffer2.erase();
		do
		{
			Sbuffer2.push_back(Sbuffer[startSecondNum + endingLocIterator]);
		} while (startSecondNum + ++endingLocIterator <= Sbuffer.size()); // reads untill the end of the line of text

		Dbuffer.netWorthE= std::stoi(Sbuffer2);


		masterDataList.push_back(Dbuffer); // adds finished data to master data list
		fileSkipLine(saveFile);
	}

	saveFile.close();
	return;
}