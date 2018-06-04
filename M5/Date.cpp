// Final Project Milestone 5 - The Perishable class
// -----------------------------------------------------------
// Name : Sungjun Hong     Date : 2018-04-09    Reason : Complete MileStone 5
/////////////////////////////////////////////////////////////////
#include "Date.h"

namespace AMA {

	Date::Date()
	{
		year = 0;
		month = 0;
		day = 0;

		compvalue = 0;
		errstate = NO_ERROR;
	}


	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int eCode)
	{
		errstate = eCode;
	}

	Date::Date(int Getyear, int Getmonth, int Getday)
	{
		if (Getyear > max_year && Getyear < min_year) // invalid
		{
			*this = Date();
			this->errstate = YEAR_ERROR;
		}
		else // pass year
		{
			if (Getmonth < 1 && Getmonth > 12) // invalid
			{
				*this = Date();
				this->errstate = MON_ERROR;
			}
			else // pass year and month
			{
				if (mdays(Getmonth, Getyear) > 31 && mdays(Getmonth, Getyear) < 28) // invalid
				{
					*this = Date();
					this->errstate = DAY_ERROR;
				}
				else // pass year and month and day
				{
					this->year = Getyear;
					this->month = Getmonth;
					this->day = Getday;
					this->errstate = NO_ERROR;
					this->compvalue = year * 372 + month * 13 + day;
				}
			}
		}
	}

	bool Date::operator== (const Date& rhs) const
	{
		if (this->compvalue != 0 && rhs.compvalue != 0)
		{
			if (this->compvalue == rhs.compvalue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (this->compvalue != 0 || rhs.compvalue != 0)
		{
			return false;
		}
		return false;
	}


	bool Date::operator!= (const Date& rhs) const
	{
		if (this->compvalue != 0 && rhs.compvalue != 0)
		{
			if (this->compvalue != rhs.compvalue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (this->compvalue != 0 || rhs.compvalue != 0)
		{
			return false;
		}
		return false;
	}


	bool Date::operator< (const Date& rhs) const
	{
		if (this->compvalue != 0 && rhs.compvalue != 0)
		{
			if (this->compvalue < rhs.compvalue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (this->compvalue != 0 || rhs.compvalue != 0)
		{
			return false;
		}
		return false;
	}


	bool Date::operator> (const Date& rhs) const
	{
		if (this->compvalue != 0 && rhs.compvalue != 0)
		{
			if (this->compvalue > rhs.compvalue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (this->compvalue != 0 || rhs.compvalue != 0)
		{
			return false;
		}
		return false;
	}


	bool Date::operator<= (const Date& rhs) const
	{
		if (this->compvalue != 0 && rhs.compvalue != 0)
		{
			if (this->compvalue <= rhs.compvalue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (this->compvalue != 0 || rhs.compvalue != 0)
		{
			return false;
		}
		return false;
	}


	bool Date::operator>= (const Date& rhs) const
	{
		if (this->compvalue != 0 && rhs.compvalue != 0)
		{
			if (this->compvalue >= rhs.compvalue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (this->compvalue != 0 || rhs.compvalue != 0)
		{
			return false;
		}
		return false;

	}

	int Date::errCode() const
	{
		return this->errstate;
	}

	bool Date::bad() const
	{
		if (this->errstate != NO_ERROR)
		{
			return true;
		}
		return false;
	}

	std::istream& Date::read(std::istream& istr)
	{
		int y, m, d;

		istr >> y;
		istr.ignore(1, '/');
		istr >> m;
		istr.ignore(1, '/');
		istr >> d;

		Date temp(y, m, d);

		if (temp.year == 0 || temp.month == 0 || temp.day == 0)
		{
			*this = Date();
			errCode(temp.errstate);
		}
		else
		{
			this->year = temp.year;
			this->month = temp.month;
			this->day = temp.day;
		}

		if (istr.fail() == true)
		{
			this->errstate = CIN_FAILED;
		}

		return istr;

	}

	std::ostream& Date::write(std::ostream& ostr) const
	{
		char RemoveChar = '/';

		ostr.width(4);
		ostr << this->year;
		ostr << RemoveChar;

		ostr.width(1);
		ostr << '0' << this->month;
		ostr << RemoveChar;

		ostr.width(2);
		ostr << this->day;

		return ostr;
	}

	std::istream& operator>> (std::istream& istr, Date& object)
	{
		object.read(istr);
		return istr;
	}

	std::ostream& operator<< (std::ostream& ostr, Date& object)
	{
		object.write(ostr);
		return ostr;
	}




}
