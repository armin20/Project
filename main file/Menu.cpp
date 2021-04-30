/*
Final Project Milestone 2
Name:                       	Armin Sharifiyan
Student ID:                     130891203
Filename:                       Menu.cpp
Version                         1.0.1
Date:                           4/10/2021
Milestone:                      2

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------

-----------------------------------------------------------
Minor bug fixed:

The cstring header was missing.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"

using namespace std;
namespace sdds {
	void Menu::display() const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;

	}
	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_noOfSel = NoOfSelections;

		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	int& Menu::operator>>(int& Selection)
	{
		display();

		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);

		return Selection;
		// TODO: insert return statement here
	}

	Menu::Menu(const Menu& source)
	{
		delete[] m_text;
		m_text = nullptr;

		m_text = new char[strlen(source.m_text) + 1];
		strcpy(m_text, source.m_text);

		m_noOfSel = source.m_noOfSel;
	}
}