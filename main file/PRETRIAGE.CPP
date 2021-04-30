/*
Final Project Milestone 5
Name:								Armin Sharifiyan
Student ID:							130891203
Date:								4/11/2021
Filename:							PreTriage.cpp
Version								1.0
Milestone:							5

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "PreTriage.h"
#include "Time.h"
#include "utils.h"
#include "Patient.h"
#include "Menu.h"
#include "IOAble.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

using namespace std;
namespace sdds {

	PreTriage::PreTriage(const char* dataFilename) : m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{

		delete[] m_dataFilename;
		m_dataFilename = nullptr;
		m_dataFilename = new char[strlen(dataFilename) + 1];

		strcpy(m_dataFilename, dataFilename);

		m_averCovidWait = 15;
		m_averTriageWait = 5;
		load();
	}

	PreTriage::~PreTriage()
	{
		ofstream file(m_dataFilename);
		if (file.is_open())
		{
			file << m_averCovidWait << ',';
			file << m_averTriageWait << endl;

			cout << "Saving Average Wait Times," << endl;
			cout << "   COVID Test: ";
			cout << m_averCovidWait;
			cout << endl;
			cout << "   Triage: ";
			cout << m_averTriageWait;
			cout << endl;
			cout << "Saving m_lineup..." << endl;

			for (int i = 0; i < m_lineupSize; i++)
			{
				m_lineup[i]->csvWrite(file);
				file << endl;

				cout << i + 1 << "- ";
				m_lineup[i]->csvWrite(cout);
				cout << endl;
			}
		}
		file.close();

		for (int i = 0; i < m_lineupSize; i++)
		{
			delete m_lineup[i];
			m_lineup[i] = nullptr;
		}

		delete[] m_dataFilename;
		m_dataFilename = nullptr;

		cout << "done!" << endl;
	}

	void PreTriage::run(void)
	{
		int select;
		bool T = true;
		do
		{
			m_appMenu.operator>>(select);

			switch (select)
			{
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			case 0:

				T = false;
				break;
			}
		} while (T);
	}

	void PreTriage::reg()
	{
		int number;

		if (m_lineupSize == maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			m_pMenu.operator>>(number);

			if (number != 0)
			{
				if (number == 1)
				{
					m_lineup[m_lineupSize] = new CovidPatient;
				}
				else if (number == 2)
				{
					m_lineup[m_lineupSize] = new TriagePatient;
				}

				m_lineup[m_lineupSize]->setArrivalTime();

				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->fileIO(false);

				m_lineup[m_lineupSize]->read(cin);

				cout << endl;
				cout << "******************************************" << endl;

				m_lineup[m_lineupSize]->write(cout);

				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]);

				cout << endl;
				cout << "******************************************" << endl << endl;
				m_lineupSize++;
			}
		}
	}

	void PreTriage::admit()
	{
		int select;
		int i;

		m_pMenu.operator>>(select);

		if (select != 0)
		{
			char selectedType;

			(select == 1) ? selectedType = 'C' : selectedType = 'T';

			i = indexOfFirstInLine(selectedType);

			cout << endl;
			cout << "******************************************" << endl;

			m_lineup[i]->fileIO(false);

			cout << "Calling for ";

			m_lineup[i]->write(cout);

			cout << "******************************************" << endl << endl;

			setAverageWaitTime(*m_lineup[i]);
			removePatientFromLineup(i);
		}
	}

	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		auto counter = 0;
		auto value = 0;

		for (int i = 0; i < m_lineupSize; i++) {

			if (p.type() == m_lineup[i]->type()) {

				counter++;
			}
		}
		if (p.type() == 'C')
		{
			value = m_averCovidWait.operator*(counter);
		}

		else if (p.type() == 'T') {

			value = m_averTriageWait.operator*(counter);
		}
		return value;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		auto CT = 0;
		auto PT = 0;
		auto awt = 0;
		auto PTT = 0;

		if (p.type() == 'C')
		{
			CT = getTime();
			PT = p.operator Time();
			awt = m_averCovidWait;
			PTT = p.number();

			m_averCovidWait = ((CT - PT) + (awt * (PTT - 1))) / PTT;
		}
		else if (p.type() == 'T')
		{
			CT = getTime();
			PT = p.operator Time();
			awt = m_averTriageWait;
			PTT = p.number();

			m_averTriageWait = ((CT - PT) + (awt * (PTT - 1))) / PTT;
		}
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		for (int i = 0; i < m_lineupSize; i++) {

			if (m_lineup[i]->type() == type)
			{
				return i;
			}
		}
		return -1;
	}

	void PreTriage::load()
	{
		Patient* patient{};
		string line;

		cout << "Loading data..." << endl;

		ifstream file(m_dataFilename);
		if (file.is_open())
		{

			if (file.peek() != ifstream::traits_type::eof())		//This line checks if the file which opened by ifstream is empty of not. If it is not empty it enters to the																condition.
			{
				m_averCovidWait.read(file);
				file.ignore();
				m_averTriageWait.read(file);
				file.ignore();

				for (int i = 0; i < maxNoOfPatients; i++) {

					getline(file, line, ',');

					if (line != "")
					{
						if (line == "C")
						{
							patient = new CovidPatient;
						}
						else if (line == "T") {
							patient = new TriagePatient;
						}
						if (patient)
						{
							patient->fileIO(true);
							patient->csvRead(file);
							patient->fileIO(false);

							m_lineup[i] = patient;

							m_lineupSize++;
						}
					}
				}

				if (file.eof() == 0)	//It checks if the it reached the end of the file or not.
				{
					cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
				}
			}
		}
		file.close();

		if (m_lineupSize == 0)
		{
			cout << "No data or bad data file!" << endl << endl;
		}
		else
		{
			cout << m_lineupSize << " Records imported..." << endl << endl;
		}
	}
}