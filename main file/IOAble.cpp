/*
Final Project Milestone 2
Name:                       	Armin Sharifiyan
Student ID:                     130891203
Filename:                       IOAble.cpp
Version                         1.0
Date:                           3/23/2021
Milestone:                      2

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include "IOAble.h"

using namespace std;

namespace sdds {

	IOAble::~IOAble()
	{
	}

	std::ostream& operator<<(std::ostream& ostr, const IOAble& src)
	{
		
		src.write(ostr);

		return ostr;
		// TODO: insert return statement here
	}

	std::istream& operator>>(std::istream& istr, IOAble& src)
	{
		src.read(istr);

		return istr;
		// TODO: insert return statement here
	}

}