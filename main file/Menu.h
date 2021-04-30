/*
Final Project Milestone 2
Name:                       	Armin Sharifiyan
Student ID:                     130891203
Filename:                       Menu.h
Version                         1.0
Date:                           3/23/2021
Milestone:                      2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#pragma once
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

#include <iostream>
namespace sdds {

class Menu {
    char* m_text = nullptr; // holds the menu content dynamically
    int m_noOfSel = 0;  // holds the number of options displayed in menu content
    void display()const;
public:
    Menu(const char* MenuContent, int NoOfSelections);
    virtual ~Menu();
    int& operator>>(int& Selection);
    // add safe copying logic
    Menu(const Menu& source);

    Menu& operator=(const Menu& source) = delete;
};
 }
#endif // !SDDS_MENU_H_
