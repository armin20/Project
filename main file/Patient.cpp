/*
Final Project Milestone 3
Name:								Armin Sharifiyan
Student ID:							130891203
Date:								3/30/2021
Filename:							Patient.cpp
Version								1.0.1
Milestone:							3

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------

----------------------------------------
Minor bug:
OHIP fixed for Milestone 4
----------------------------------------

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "Time.h"
#include "Patient.h"
#include "Ticket.h"
#include "utils.h"
using namespace std;

namespace sdds {

	Patient::Patient(int ticketnum, bool ioflag) : ticket(ticketnum)
	{
		ioflag = fileIO_flag;
		patient_name = nullptr;
		OHIP = 0;

	}

	Patient::~Patient()
	{
		delete[] patient_name;
		patient_name = nullptr;
	}


	bool Patient::fileIO() const
	{
		return fileIO_flag;
	}

	void Patient::fileIO(bool value)
	{
		fileIO_flag = value;
	}

	bool Patient::operator==(char src) const
	{

		return (src == type()) ? true : false;
	}

	bool Patient::operator==(const Patient& src) const
	{
		return (type() == src.type()) ? true : false;
	}

	void Patient::setArrivalTime()
	{
		ticket.resetTime();
	}

	Patient::operator Time() const
	{
		return Time(ticket);
	}

	int Patient::number() const
	{
		return ticket.number();
	}

	ostream& Patient::csvWrite(std::ostream& os) const
	{

		os << type();
		os << ',';
		os << patient_name;
		os << ',';
		os << OHIP;
		os << ',';

		ticket.csvWrite(os);

		return os;

		// TODO: insert return statement here
	}


	istream& Patient::csvRead(std::istream& istr)
	{
		string line;

		getline(istr, line, ',');

		delete[] patient_name;
		patient_name = nullptr;
		patient_name = new char[line.length() + 1];

		strcpy(patient_name, line.c_str());
		istr >> OHIP;
		istr.ignore();

		ticket.csvRead(istr);

		return istr;
		// TODO: insert return statement here
	}

	ostream& Patient::write(std::ostream& ostr) const
	{

		string name(patient_name);

		ticket.write(ostr);

		ostr << endl;

		if (name.length() > 25)
		{
			ostr << name.substr(0, 25);
		}
		else
		{
			ostr << patient_name;
		}

		ostr << ", OHIP: ";
		ostr << OHIP;

		return ostr;
		// TODO: insert return statement here
	}

	std::istream& Patient::read(std::istream& istr)
	{
		string line;

		cout << "Name: ";
		getline(istr, line, '\n');

		delete[] patient_name;
		patient_name = nullptr;
		patient_name = new char[strlen(line.c_str()) + 1];

		strcpy(patient_name, line.c_str());

		OHIP = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);


		return istr;
		// TODO: insert return statement here
	}
}