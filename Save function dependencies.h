#pragma once
#include <fstream>

//debug
#include <iostream>

void fileSkipLine(std::fstream& file)
{
	file.ignore(2000000000, '\n');
	return;
}