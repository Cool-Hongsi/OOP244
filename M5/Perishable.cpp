// Final Project Milestone 5 - The Perishable class
// --------------------------------------------------------------
// Name : Sungjun Hong     Date : 2018-04-09    Reason : Complete MileStone 5
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "Product.h"
#include "iProduct.h"
#include "ErrorState.h"
#include "Perishable.h"
#include "Date.h"

using namespace std;

namespace AMA
{
	Perishable::Perishable() // Product default constructor (get rid of const)
	// This constructor passes the file record tag for a perishable product (¡®P¡¯) to the base class constructor
	// and sets the current object to a safe empty state.
	{
		this->product_type__ = 'P';
		this->sku__[0] = '\0';
		this->unit__[0] = '\0';
		this->name__ = nullptr;
		this->quantity_hand__ = 0;
		this->quantity_need__ = 0;
		this->price__ = 0;
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	// add year, month, day data into txt file with Product::store method.
	{
		Product::store(file, false);
		file << ',' << perishdate.year << '/' << '0' << perishdate.month << '/' << perishdate.day;

		if (newLine == true)
		{
			file << endl;
		}

		return file;
	}

	std::fstream& Perishable::load(std::fstream& file)
	// the value of year, month and day which are added in store method loads.
	{
		Product::load(file);

		file.ignore(); // ignore , mark in front of year in txt file

		perishdate.read(file);

		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const
	// input more data which is expiry date (year, month, day)
	{
		Product::write(os, linear);

			if (ErrorMessage.isClear() == true)
			{
				if (!linear)
				{
					os << " Expiry date: ";
				}
				
				perishdate.write(os);
			}
		return os;
	}

	std::istream& Perishable::read(std::istream& is)
	// judge the error messages depending on the value of expiry date.
	{
		Product::read(is);

		if (ErrorMessage.isClear() == true)
		{
			cout << " Expiry date (YYYY/MM/DD): ";
			perishdate.read(is);
		
			if (perishdate.year < min_year || perishdate.year > max_year)
			{
				ErrorMessage.clear();
				ErrorMessage.message("Invalid Year in Date Entry");
				is.setstate(std::ios::failbit);
			}

			else if (perishdate.month < 1 || perishdate.month > 12)
			{
				ErrorMessage.clear();
				ErrorMessage.message("Invalid Month in Date Entry");
				is.setstate(std::ios::failbit);
			}

			else if (perishdate.day > 31 || perishdate.day < 1)
			{
				ErrorMessage.clear();
				ErrorMessage.message("Invalid Day in Date Entry");
				is.setstate(std::ios::failbit);
			}
		}

		return is;
	}
		
	const Date& Perishable::expiry() const
	{
		return perishdate;
	}

	std::ostream& operator<< (std::ostream& os, const Date& anotherobject)
	{
		return os;
	}

}
