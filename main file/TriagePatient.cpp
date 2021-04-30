/*
Final Project Milestone 4
Name:								Armin Sharifiyan
Student ID:							130891203
Date:								3/30/2021
Filename:							TriagePatient.cpp
Version								1.0
Milestone:							4

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "TriagePatient.h"
#include "Patient.h"
#include "utils.h"

using namespace std;
int nextTriageTicket = 1;

namespace sdds {

	TriagePatient::TriagePatient() : Patient(nextTriageTicket)
	{
		m_symptoms = nullptr;
		nextTriageTicket++;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
		m_symptoms = nullptr;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	ostream& TriagePatient::csvWrite(std::ostream& os) const
	{

		Patient::csvWrite(os);
		os << ',' << m_symptoms;

		return os;
	}

	istream& TriagePatient::csvRead(std::istream& istr)
	{

		string line;

		delete[] m_symptoms;
		m_symptoms = nullptr;

		Patient::csvRead(istr);
		istr.ignore();

		getline(istr, line, '\n');

		m_symptoms = new char[line.length() + 1];

		strcpy(m_symptoms, line.c_str());

		nextTriageTicket = Patient::number() + 1;

		return istr;
	}

	ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (fileIO() == true)
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << endl;
			ostr << "Symptoms: ";
			ostr << m_symptoms << endl;
		}
		return ostr;
		// TODO: insert return statement here
	}

	istream& TriagePatient::read(std::istream& istr)
	{
		char* line;

		if (fileIO() == true)
		{
			csvRead(istr);
		}
		else
		{
			delete[] m_symptoms;
			m_symptoms = nullptr;
			Patient::read(istr);

			line = getcstr("Symptoms: ", istr, '\n');

			m_symptoms = new char[strlen(line) + 1];

			strcpy(m_symptoms, line);

			delete[] line;
			line = nullptr;
		}
		return istr;
	}
}