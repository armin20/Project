/*
Final Project Milestone 1
Name:								Armin Sharifiyan
Student ID:							130891203
Date:								4/10/2021
Filename:							Utils.cpp
Version								1.0.2
Milestone:							1

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------

-----------------------------------------------------------
Minor Change:

I delete the unecessary comments
-----------------------------------------------------------


*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;
    int getInt(const char* prompt)
    {
      
        bool T = true;
        int c;
        char ch;

        if (prompt != nullptr)
        {
            cout << prompt;
        }
        while (T)
        { 
            if (scanf("%d%c", &c, &ch) == 2)
            {
                if (c > 0 && ch == '\n')
                {
                    T = false;
                }
                else
                {
                    if (c < 0)
                    {
                        cin.ignore(200, '\n');
                        cout << "Bad integer value, try again: ";
                    }
                    else if (ch != '\n')
                    {
                        cin.ignore(200, '\n');
                        cout << "Enter only an integer, try again: ";
                    }
                }
            }
            else
            {
                cin.ignore(200, '\n');
                cout << "Bad integer value, try again: ";
            }
        }        
        return c;
    }

    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
    {
        int value;
        bool done = true;
        char ch;

        if (prompt != nullptr)
        {
            cout << prompt;
        }

        while (done)
        {

            if (scanf("%d%c", &value, &ch) == 2)
            {
                if (value > 0 && ch == '\n')
                {

                    if (value >= min && value <= max)
                    {
                        done = false;
                    }
                    else if(errorMessage != nullptr)
                    {
                        cout << errorMessage;
                        if (showRangeAtError == true)
                        {
                            cout << "[" << min << " <= value <= " << max << "]: ";
                        }
                    }
                    else if(showRangeAtError == true)
                    {
                        cout << "[" << min << " <= value <= " << max << "]: ";
                    }

                }
                else if (value >= min && value <= max)
                {
                    done = false;
                }
                else if (errorMessage != nullptr)
                {
                    cout << errorMessage;
                    if (showRangeAtError == true)
                    {
                        cout << "[" << min << " <= value <= " << max << "]: ";
                    }
                }
                else if (showRangeAtError == true)
                {
                    cout << "[" << min << " <= value <= " << max << "]: ";
                }
                else
                {
                    if (value < 0)
                    {
                        cin.ignore(200, '\n');
                        cout << "Bad integer value, try again: ";
                    }
                    else if (ch != '\n')
                    {
                        cin.ignore(200, '\n');
                        cout << "Enter only an integer, try again: ";
                    }
                }
            }
            else
            {
                cin.ignore(200, '\n');
                cout << "Bad integer value, try again: ";
            }
        }

        return value;
    }
    char* getcstr(const char* prompt, std::istream& istr, char delimiter)
    {
        char* str = nullptr;
        string li;

        if (prompt != nullptr)
        {
            cout << prompt;
        }

        getline(istr, li, delimiter);

        delete[] str;
        str = new char[li.length() + 1];

       strcpy(str, li.c_str()); 

        return str;
    }
   //  made global in utils.h
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
 
}