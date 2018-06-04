// --------------------------------------------------------------
// Name : Sungjun Hong             Date : 2018-03-23               Reason : Complete MileStone 3
// Chris              2018-02-08           Removed polymorphism
// Chris              2018-03-02           Final Draft 20181
// Chris              2018-03-03           ErrorMessage -> ErrorState
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include "Product.h"
using namespace std;

namespace AMA
{
	// --------------------------------------------------------------------------------------- protected

	void Product::name(const char* name)
	{
		if (name == nullptr)
		{
			this->name__ = nullptr;
			delete[] this->name__;
		}
		else
		{
			// delete[] this->name__; // Memory Problem
			this->name__ = new char[strlen(name) + 1];
			strncpy(this->name__, name, strlen(name) + 1);
		}
	}

	const char* Product::name() const
	{
		return this->name__;
	}

	double Product::cost() const
	{
		if (this->taxable__ == true)
		{
			return (this->price__ * TAX) + this->price__;
		}

		else if (this->taxable__ == false)
		{
			return this->price__;
		}
		return this->price__;

	}

	void Product::message(const char* message)
	{
		this->ErrorMessage.message(message);
	}

	bool Product::isClear() const
	{
		if (this->ErrorMessage.isClear() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}

	// --------------------------------------------------------------------------------------- public (constructor)

	/*
	Product::Product()
	{
		this->product_type__ = '\0';
		this->sku__[0] = '\0';
		this->unit__[0] = '\0';
		this->name__ = nullptr;
		this->quantity_hand__ = 0;
		this->quantity_need__ = 0;
		this->price__ = 0;
	}
	*/

	Product::Product(const char* checktype) // Do not put default value in definition
	{
		product_type__ = checktype[0];
	}

	Product::Product(const char* sku, const char* name, const char* unit, int quantity_hand, bool taxable,
		double price, int quantity_need) // Do not put default value in definition
	{
		// There is a problem when I declare sku[0]!= '\0' as condition.
		// There is a problem when I declare the range of integer as condition.
		/*
		ex) if (quantity_hand > 0)
		When I look into MyProduct.cpp, one of the object is declared as 'Product("", "", "")'
		There is no mention about integer. In order to put default value into integer values,
		I'm not supposed to put condition in integer value. Otherwise, It will show the garbage values in matrix.
		*/

		strncpy(this->sku__, sku, strlen(sku) + 1);

		this->name__ = new char[strlen(name) + 1];
		strncpy(this->name__, name, strlen(name) + 1);

		strncpy(this->unit__, unit, strlen(unit) + 1);

		this->quantity_hand__ = quantity_hand;

		this->taxable__ = taxable;

		this->price__ = price;

		this->quantity_need__ = quantity_need;
	}

	Product::Product(const Product& copyobject) // copy constructor
	{
		if (isEmpty() == false)
		{
			strncpy(this->sku__, copyobject.sku__, strlen(copyobject.sku__) + 1);

			this->name__ = new char[strlen(copyobject.name__) + 1];
			strncpy(this->name__, copyobject.name__, strlen(copyobject.name__) + 1);

			strncpy(this->unit__, copyobject.unit__, strlen(copyobject.unit__) + 1);

			this->quantity_hand__ = copyobject.quantity_hand__;

			this->taxable__ = copyobject.taxable__;

			this->price__ = copyobject.price__;

			this->quantity_need__ = copyobject.quantity_need__;
		}
	}

	Product& Product::operator=(const Product& operatorcopyobject) // copy assignment operator
	{
		if (isEmpty() == false)
		{
			strncpy(this->sku__, operatorcopyobject.sku__, strlen(operatorcopyobject.sku__) + 1);

			this->name__ = new char[strlen(operatorcopyobject.name__) + 1];
			strncpy(this->name__, operatorcopyobject.name__, strlen(operatorcopyobject.name__) + 1);

			strncpy(this->unit__, operatorcopyobject.unit__, strlen(operatorcopyobject.unit__) + 1);

			this->quantity_hand__ = operatorcopyobject.quantity_hand__;

			this->taxable__ = operatorcopyobject.taxable__;

			this->price__ = operatorcopyobject.price__;

			this->quantity_need__ = operatorcopyobject.quantity_need__;

			return *this;
		}
		return *this;
	}

	Product::~Product()
	{
		delete[] this->name__;
	}

	// --------------------------------------------------------------------------------------- public (method (part1))

	void Product::sku(const char* sku) // NI
	{
		strncpy(this->sku__, sku, strlen(sku) + 1);
	}

	void Product::unit(const char* unit) // NI
	{
		strncpy(this->unit__, unit, strlen(unit) + 1);
	}

	/*
	void Product::name(const char* name) // NI
	{
		strncpy(this->name__, name, strlen(name) + 1);
	}
	*/

	void Product::price(double price) // NI
	{
		this->price__ = price;
	}

	void Product::taxed(bool tax) // NI
	{
		this->taxable__ = tax;
	}

	void Product::quantity(int quantity_hand)
	{
		this->quantity_hand__ = quantity_hand;
	}

	void Product::qtyNeeded(int quantity_need) // NI
	{
		this->quantity_need__ = quantity_need;
	}

	// --------------------------------------------------------------------------------------- public (method (part2))

	const char* Product::sku() const // NI
	{
		return this->sku__;
	}

	const char* Product::unit() const // NI
	{
		return this->unit__;
	}

	/*
	char* Product::name() const // NI
	{
		return this->name__;
	}
	*/

	double Product::price() const // NI
	{
		return this->price__;
	}

	bool Product::taxed() const // NI
	{
		return this->taxable__;
	}

	int Product::quantity() const
	{
		return this->quantity_hand__;
	}

	int Product::qtyNeeded() const
	{
		return this->quantity_need__;
	}

	// --------------------------------------------------------------------------------------- public (method (part3))

	double Product::total_cost() const
	{
		double totalcost = 0;

		totalcost = this->quantity() * this->cost();

		return totalcost;
	}

	bool Product::isEmpty() const
	{
		if (this->sku__ == nullptr && this->name__ == nullptr && this->unit__ == nullptr && this->price__ == 0
			&& this->quantity_hand__ == 0 && this->quantity_need__ == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}

	bool Product::operator==(const char* sku) const
	{
		if (strcmp(this->sku__, sku) == 1) // 1 true , 0 false
		{
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}

	int Product::operator+= (int addNumber)
	{
		if (addNumber > 0)
		{
			this->quantity_hand__ += addNumber;
			return this->quantity_hand__;
		}
		else if (addNumber <= 0)
		{
			return this->quantity_hand__;
		}
		return this->quantity_hand__;
	}

	bool Product::operator> (const char* sku) const
	{
		if (this->sku__ > sku)
		{
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}

	bool Product::operator> (const Product& anotherobject) const
	{
		if (this->name__ > anotherobject.name__)
		{
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}

	// --------------------------------------------------------------------------------------- public (method (part4))

	std::fstream& Product::store(std::fstream& file, bool newLine = true) const
	{
		file << this->product_type__ << ',' << sku() << ',' << name() << ',' << price() << ',' << (taxed() ? true : false)
			<< ',' << quantity() << ',' << unit() << ',' << qtyNeeded();

		if (newLine == true)
		{
			file << endl;
		}

		return file;
	}

	std::fstream& Product::load(std::fstream& file)
	{
		Product tempload;

		char temparray_sku[max_sku_length]; // sku
		char temparray_unit[max_unit_length]; // unit
		char temparray_name[max_name_length]; // name
		int tempint_hand; // quantity_hand
		int tempint_need; // quantity_need
		double tempdouble_price; // price

		if (file.is_open())
		{
			file.width(max_sku_length); // assign the width
			file.setf(std::ios::left); // set the sentence left
			file >> temparray_sku; // put temparray_sku value
			tempload.sku(temparray_sku); // put temparray_sku value into tempload object's sku value

			file.setf(std::ios::left);
			file.width(20);
			file.ignore(9);
			file >> temparray_name;
			tempload.name(temparray_name);

			file.setf(std::ios::right);
			file.setf(std::ios::fixed); // fix the standard to put decimal point
			file.width(7);
			file.precision(2); // represent the decimal point until second position such as 0.00 
			file.ignore(30);
			file >> tempdouble_price;
			tempload.price(tempdouble_price);

			file.setf(std::ios::right);
			file.width(4);
			file.ignore(10, ',');
			file >> tempint_hand;
			tempload.quantity(tempint_hand); // quantity_hand

			file.unsetf(std::ios::right);
			file.width(10);
			file.ignore(16, ',');
			file >> temparray_unit;
			tempload.unit(temparray_unit);

			file.setf(std::ios::right);
			file.width(4);
			file.ignore(17, ',');
			file >> tempint_need;
			tempload.qtyNeeded(tempint_need); // quantity_need
		}

		*this = tempload; // call Copy Assignment Operator to copy the temporary object (tempload) to the current object. 

		file.close();

		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const
	{
		// const char* temp = 0; // I declared it to receive string (name)

		if (linear == true)
		{
			// sku
			os.width(max_sku_length);
			os.unsetf(std::ios::right); // unset printting right postion (I'm supposed to set again later)
			os << sku() << '|';

			// name
			os.width(20);
			// temp = name();
			os << name() << '|';
			os.setf(std::ios::right); // set printting right position (I'm supposed to unset again later)
			os.setf(std::ios::fixed); // fix the standard to put decimal point

			// cost
			os.width(7);
			os.precision(2); // represent the decimal point until second position such as 0.00 
			os << cost() << '|';
			os.setf(std::ios::right);

			// quantity_hand
			os.width(4);
			os << quantity() << '|';
			os.unsetf(std::ios::right);

			// unit
			os.width(10);
			os << unit() << '|';
			os.setf(std::ios::left);

			// quantity_need
			os.width(4);
			os.setf(std::ios::right);
			os << qtyNeeded() << '|';
		}

		else
		{
			if (taxed() == true)
			{
				os << "Sku: " << sku() << endl;
				// temp = name();
				os << "Name: " << name() << endl;
				os << "Price: " << price() << endl;
				os << "Price after tax: " << cost() << endl;
				os << "Quantity On Hand: " << quantity() << " " << unit() << endl;
				os << "Quantity Needed: " << qtyNeeded() << endl;
			}

			else
			{
				os << "Sku: " << sku() << endl;
				// temp = name();
				os << "Name: " << name() << endl;
				os << "Price: " << price() << endl;
				os << "Price after tax: " << "N/A" << endl;
				os << "Quantity On Hand: " << quantity() << " " << unit() << endl;
				os << "Quantity Needed:" << qtyNeeded() << endl;
			}
		}
		return os;
	}

	std::istream& Product::read(std::istream& is)
	{
		Product tempread;
		bool check; // use it for checking 'y' or 'n'

		char temparray_sku[max_sku_length]; // sku
		char temparray_name[max_name_length]; // name
		char temparray_unit[max_unit_length]; // unit
		char selection; // taxable or no
		double tempdouble_price; // price
		int tempint_hand; // quantity_hand
		int tempint_need; // quantity_need

		cout << " Sku: ";
		is >> temparray_sku;
		tempread.sku(temparray_sku);

		cout << " Name (no spaces): ";
		is >> temparray_name;
		tempread.name(temparray_name);

		cout << " Unit: ";
		is >> temparray_unit;
		tempread.unit(temparray_unit);

		cout << " Taxed? (y/n): ";
		is >> selection;

		if (selection == 'Y' || selection == 'y' || selection == 'N' || selection == 'n')
		{
			if (selection == 'Y' || selection == 'y') // taxable
			{
				check = true;
				tempread.taxed(check);
				cout << " Price: ";
				is >> tempdouble_price;
				tempread.price(tempdouble_price);
			}

			else if (selection == 'N' || selection == 'n') // untaxable
			{
				check = false;
				tempread.taxed(check);
				cout << " Price: ";
				is >> tempdouble_price;
				tempread.price(tempdouble_price);
			}
			
			if (is.fail() == false)
			{
				cout << " Quantity on hand: ";
				is >> tempint_hand;
				tempread.quantity(tempint_hand);

				if (is.fail() == false)
				{
					cout << " Quantity needed: ";
					is >> tempint_need;
					tempread.qtyNeeded(tempint_need);

					if (is.fail() == false)
					{
						ErrorMessage.clear(); // nullptr (no error)

						*this = tempread; // call Copy Assignment Operator
						return is;
					}
					else
					{
						ErrorMessage.message("Invalid Quantity Needed Entry");
						is.clear();
						is.setstate(ios::failbit);
					}
				}
				else
				{
					ErrorMessage.message("Invalid Quantity Entry");
					is.clear();
					is.setstate(ios::failbit);
				}
			}
			else
			{
				ErrorMessage.message("Invalid Price Entry");
				is.clear();
				is.setstate(ios::failbit);
			}
		}
		else
		{
			ErrorMessage.message("Only (Y)es or (N)o are acceptable");
			is.clear();
			is.setstate(ios::failbit);
		}
		return is;
	}

	// --------------------------------------------------------------------------------------- helper functions

	std::ostream& operator<< (std::ostream& os, const Product& anotherobject)
	{
		anotherobject.write(os, true);
		return os;
	}

	std::istream& operator>> (std::istream& is, Product& anotherobject)
	{
		anotherobject.read(is);
		return is;
	}

	double operator+= (double& number, const Product& anotherobject)
	{
		number += anotherobject.total_cost();
		return number;
	}
}