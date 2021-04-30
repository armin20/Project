/*
Final Project Milestone 1
Name:                       	Armin Sharifiyan
Student ID:                     130891203
Filename:                       utils.h
Version                         1.2
Date:                           4/10/2021
Milestone:                      1

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------

//----------------------------------------------------
New function added for Milestone 5

New Template function added 
//----------------------------------------------------
*/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
    extern bool debug; // making sdds::debug variable global to all the files
                       // which include: "utils.h"
    int getInt(const char* prompt = nullptr);
    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError = true);
    char* getcstr(const char* prompt, std::istream& istr = std::cin, char delimiter = '\n');
    int getTime(); // returns the time of day in 


    template <typename type>
    void removeDynamicElement(type* array[], int index, int& size) {
        delete array[index];
        for (int j = index; j < size; j++) {
            array[j] = array[j + 1];
        }
        size--;
    }

}
#endif // !SDDS_UTILS_H_

