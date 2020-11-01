#pragma once
//inLine

#include "data.h"
#include "Save function dependencies.h"


void saveToFile()
{

	data test(1, 2020);

	std::fstream put("C:\\ProgramData\\test.txt");
	timeStamp compairData;
	std::string buffer;

	std::getline(put, buffer);

	if (buffer.empty())
	{
		//sort output
		//output
		put << test.stringFormat();
	}
	else
	{
		compairData = buffer;

		if (compairData == test.timeStamp)
		{
			test.timeStamp.revisedDataIttoratior++;
		}

		int pos = put.tellp();

		put.seekp(pos);
		fileSkipLine(put);

		put << test.stringFormat();
	}

	put.close();
	return;
}