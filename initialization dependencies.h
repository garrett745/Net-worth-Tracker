#pragma once

#include <vector>
#include <fstream>
#include <iostream> // debugg

#include "data.h"
#include "initialization dependencies.h"

void fileSkipLine(std::ifstream& file, int numOfLinesToSkip = 1)
{
	for (int i = 0; i < numOfLinesToSkip; i++)
	{
		file.ignore(2000000000, '\n');
	}
	return;
}