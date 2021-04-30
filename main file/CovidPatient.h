/*
Final Project Milestone 4
Name:								Armin Sharifiyan
Student ID:							130891203
Date:								3/30/2021
Filename:							CovidPatient.h
Version								1.0
Milestone:							4

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include <iostream>
#include "Patient.h"

namespace sdds {

	class CovidPatient :public Patient {

	public:
		CovidPatient();

		virtual char type()const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

	};
}
#endif // !SDDS_COVIDPATIENT_H_



