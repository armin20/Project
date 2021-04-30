/*
Final Project Milestone 4
Name:								Armin Sharifiyan
Student ID:							130891203
Date:								3/30/2021
Filename:							CovidPatient.cpp
Version								1.0
Milestone:							4

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CovidPatient.h"
#include "Patient.h"

int nextCovidTicket = 1;

using namespace std;
namespace sdds {
	CovidPatient::CovidPatient() : Patient(nextCovidTicket)
	{
		nextCovidTicket = Patient::number();
		nextCovidTicket++;
	}

	char CovidPatient::type() const
	{
		return 'C';
	}

	istream& CovidPatient::csvRead(std::istream& istr)
	{
		Patient::csvRead(istr);
		nextCovidTicket = Patient::number() + 1;
		istr.ignore();

		return istr;
		// TODO: insert return statement here
	}

	ostream& CovidPatient::write(std::ostream& ostr) const
	{
		if (fileIO() == true)
		{
			Patient::csvWrite(ostr);
		}
		else
		{
			ostr << "COVID TEST" << endl;
			Patient::write(ostr);
			ostr << endl;
		}
		return ostr;
		// TODO: insert return statement here
	}

	istream& CovidPatient::read(std::istream& istr)
	{
		if (fileIO() == true)
		{
			csvRead(istr);
		}
		else
		{
			Patient::read(istr);
		}
		return istr;
		// TODO: insert return statement here
	}
}