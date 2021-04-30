/*
Final Project Milestone 3
Name:								Armin Sharifiyan
Student ID:							130891203
Date:								3/28/2021
Filename:							Patient.h
Version								1.0
Milestone:							3

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#pragma once

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#include "Time.h"
namespace sdds {

	class Patient : public IOAble {

		char* patient_name;
		int OHIP;
		Ticket ticket;

		bool fileIO_flag = false;

	public:

		Patient(int ticketnum = 0, bool ioflag = false);
		~Patient();
		Patient(const Patient& source) = delete;
		Patient& operator=(const Patient& source) = delete;
		virtual char type()const = 0;
		
		bool fileIO()const;

		void fileIO(bool value);

		bool operator==(char src)const;
		bool operator==(const Patient& src)const;

		void setArrivalTime();

		operator Time()const;
		int number()const;

		std::ostream& csvWrite(std::ostream& os)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

	};
}
#endif // !SDDS_PATIENT_H_
