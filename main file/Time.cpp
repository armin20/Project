/*
Final Project Milestone 1
Name:								Armin Sharifiyan
Student ID:							130891203
Date:								4/10/2021
Filename:							Time.cpp
Version								1.2
Milestone:							1

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------

-----------------------------------------------------------
Minor Bug fixed and a few change on comments

In function write there is single change in the condition
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		m_min = sdds::getTime();


		return *this;

		// TODO: insert return statement here
	}
	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{

		if (((m_min / 60) > 9))
		{

			ostr << (m_min / 60);
			ostr << ":";

			if ((m_min % 60) < 10)
			{
				ostr << "0" << (m_min % 60);
			}
			else
			{
				ostr << (m_min % 60);
			}

		}
		else if ((m_min / 60) < 10)
		{

			ostr << '0';
			ostr << (m_min / 60);
			ostr << ":";
			if ((m_min % 60) < 10)
			{
				ostr << '0';
				ostr << (m_min % 60);
			}
			else
			{
				ostr << (m_min % 60);
			}
		}
		return ostr;
		// TODO: insert return statement here
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hour = 0;
		int min = 0;
		char character = { '\0' };


		istr >> hour >> character >> min;

			if (hour >= 0 && character == ':' && min >= 0) 
			{
				m_min = (hour * 60) + min;
			}
			else
			{
				istr.setstate(ios::failbit);
			}

		return istr;
		// TODO: insert return statement here
	}

	Time& Time::operator-=(const Time& D)
	{
		int val = 0;
		
		bool t = true;

		val = m_min - D.m_min;

		if (val < 0)
		{
			while (t)
			{

				val = m_min - D.m_min;

				if (val > 0)
				{
					m_min = val;
					t = false;
				}
				else
				{
					m_min += 1440;
					
				}
			}
		}
		else
		{
			m_min = val;
		}

		return *this;
		// TODO: insert return statement here
	}

	Time Time::operator-(const Time& D) const
	{
		Time cpy(this->m_min);
		cpy -= D;
		return cpy;

	}

	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;

		return *this;
		// TODO: insert return statement here
	}

	Time Time::operator+(const Time& D) const
	{
		int m;

		m = m_min + D.m_min;

		return Time(m);
	}

	Time& Time::operator=(unsigned int val)
	{
		m_min = val;

		return *this;
		// TODO: insert return statement here
	}

	Time& Time::operator*=(unsigned int val)
	{
		int value;
		value = m_min * val;

		m_min = value;

		return *this;
		// TODO: insert return statement here
	}

	Time& Time::operator/=(unsigned int val)
	{
		m_min /= val;

		return *this;
		// TODO: insert return statement here
	}

	Time Time::operator*(unsigned int val) const
	{
		int value;

		value = m_min * val;

		return Time(value);
	}

	Time Time::operator/(unsigned int val) const
	{

		int value;

		value = m_min / val;

		return Time(value);
	}

	Time::operator unsigned int() const
	{
		return m_min;
	}

	Time::operator int() const
	{
		return (int)m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);

		return ostr;
		// TODO: insert return statement here
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);

		return istr;
		// TODO: insert return statement here
	}
}