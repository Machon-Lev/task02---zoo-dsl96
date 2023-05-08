#pragma once

#include<iostream>
using  std::ostream;


struct Location
{
	int col;
	int row;

	Location operator +=(const Location& other)
	{
		return Location{ row = this->row + other.row , col = this->col + other.col };
	}

	bool operator == (const Location& other)
	{
		return this->row == other.row && this->col == other.col;
	}

	bool operator != (const Location& other)
	{
		return !(*this == other);
	}

	friend ostream& operator<<(ostream& os, const Location& l)
	{
		os << "col:" << l.col << "  row:" << l.row << std::endl;
		return os;
	}
};


