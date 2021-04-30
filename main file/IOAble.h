/*
Final Project Milestone 2
Name:                       	Armin Sharifiyan
Student ID:                     130891203
Filename:                       IOAble.h
Version                         1.0
Date:                           3/23/2021
Milestone:                      2

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#pragma once

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_

#include <iostream>

namespace sdds {

	class IOAble
	{
	public:

		virtual std::ostream& csvWrite(std::ostream& os)const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble();
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& src);
	std::istream& operator>>(std::istream& istr, IOAble& src);

}
#endif // !SDDS_IOABLE_H_
