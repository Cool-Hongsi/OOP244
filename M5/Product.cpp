// Final Project Milestone 5 - The Perishable class
// --------------------------------------------------------------
// Name : Sungjun Hong     Date : 2018-04-09    Reason : Complete MileStone 5
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

	void Product::name(const char* name) // insert parameter (char* name) into one of the members in class with allocating dynamic memory.
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

	const char* Product::name() const // return the value of name
	{
		return this->name__;
	}

	double Product::cost() const // according to the value of taxable, return the value which assigned tax or not
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

	void Product::message(const char* message) // insert parameter (char* message) into message method of ErrorMessage object.
	{
		this->ErrorMessage.message(message);
	}

	bool Product::isClear() const // check the status of ErrorMessage and return the value
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

	Product::Product(char checktype) // Do not put default value in definition
	{
		product_type__ = checktype;
	}

	Product::Product(const char* sku, const char* name, const char* unit, int quantity_hand, bool taxable,
		double price, int quantity_need) // Do not put default value in definition
		// insert parameters into members in class (If I did not put the value in paramter, it should be entered by default values.)
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

	Product::~Product() // destructor (deallocate dynamic memory)
	{
		delete[] this->name__;
	}

	// --------------------------------------------------------------------------------------- public (method (part1))

	void Product::sku(const char* sku) // insert parameter (char* sku) into one of the members in class by using strncpy method.
	{
		strncpy(this->sku__, sku, strlen(sku) + 1);
	}

	void Product::unit(const char* unit) // insert parameter (char* unit) into one of the members in class by using strncpy method.
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

	bool Product::isEmpty() const // check the value in members whether they are empty or not
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

	bool Product::operator==(const char* sku) const // compare two of the strings and return the bool value
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

	int Product::operator+= (int addNumber) // add the value of parameter into initial member of quantity_hand.
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
	
	bool Product::operator> (const iProduct& object) const // compare the size of string and return the bool value.
	{
		if (this->name() > object.name())
		{
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}
	

	bool Product::operator> (const Product& anotherobject) const // compare the size of string and return the bool value.
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

	std::fstream& Product::store(std::fstream& file, bool newLine) const
	// Through fstream, below values in object store into txt file with delimeter(,).
	// After then, according to newLine value, it is distinguished as '\n' or no.
	{
		file << product_type__ << ',' << sku() << ',' << name() << ',' << unit() << ',' << (taxed() ? true : false) << ','
		<< price() << ',' << quantity() << ',' << qtyNeeded();

		if (newLine == true)
		{
			file << endl;
		}

		return file;
	}

	std::fstream& Product::load(std::fstream& file)
	{
	// the values which exist in txt file load into some of the new variables by using getline, peek and ignore method.
	// file.getline() (char) -> until showing up delimeter (,), as much as the length, load data and insert into new variables.
    // important point would be automatically passing next data. 
	// file.peek() (int or double) -> by using the command 'file >> variable', load data and put it into new variable
	// until showing up delimeter (',') and ignore it.
	// the values which are loaded from txt insert into current object through constructor.
		char temparray_sku[max_sku_length];
		char temparray_name[max_name_length];
		char temparray_unit[max_unit_length];
		bool temptaxable;
		double tempdouble_price;
		int tempint_hand;
		int tempint_need;

		if (file.is_open() == true)
		{
			file.getline(temparray_sku, max_sku_length, ',');
			file.getline(temparray_name, max_name_length, ',');
			file.getline(temparray_unit, max_unit_length, ',');
			
			file >> temptaxable;
			if (file.peek() == ',')
			{
				file.ignore();
			}

			file >> tempdouble_price;
			if (file.peek() == ',')
			{
				file.ignore();
			}

			file >> tempint_hand;
			if (file.peek() == ',')
			{
				file.ignore();
			}

			file >> tempint_need;

			*this = Product(temparray_sku, temparray_name, temparray_unit, tempint_hand, temptaxable, tempdouble_price, tempint_need);
			// copy new datas into current object.
		}

		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const
	// Through os stream, I can have an opportunity to appoint the style of output.
	// In this write function, depending on the value of linear, I can print data by using width, setf, precision method in os stream.
	{
		if (ErrorMessage.isClear() == true)
		{
			if (linear == true)
			{
				os.width(max_sku_length);
				os.setf(ios::left);
				os << sku() << "|";
				os.width(20);
				os << name() << "|";
				os.width(7);
				os.unsetf(ios::left);
				os.setf(ios::fixed);
				os.precision(2);
				os << cost() << "|";
				os.width(4);
				os << quantity() << "|";
				os.width(10);
				os.setf(ios::left);
				os << unit() << "|";
				os.unsetf(ios::left);
				os.width(4);
				os << qtyNeeded() << "|";
			}
			else
			{
				if (taxed() == true) // According to the value of taxed, it could be different.
				{
					os << " Sku: " << sku() << endl;
					// temp = name();
					os << " Name (no spaces): " << name() << endl;
					os << " Price: " << price() << endl;
					os << " Price after tax: " << cost() << endl;
					os << " Quantity on Hand: " << quantity() << " " << unit() << endl;
					os << " Quantity needed: " << qtyNeeded();
				}

				else // According to the value of taxed, it could be different.
				{
					os << " Sku: " << sku() << endl;
					// temp = name();
					os << " Name (no spaces): " << name() << endl;
					os << " Price: " << price() << endl;
					os << " Price after tax: " << " N/A" << endl;
					os << " Quantity on Hand: " << quantity() << " " << unit() << endl;
					os << " Quantity needed: " << qtyNeeded() << endl;
				}
			}
		}
		else // if there is any message in ErrorMessage object, print the content of errormessage.
		{
			cout << ErrorMessage.message(); // mandatory !!!!!!!!!!!!!!!!!!!
		}

		return os;
	}

	std::istream& Product::read(std::istream& is)
	{
	// About initial values, I can put new values by using read function. In order to do that, I was supposed to create new object temporarily.
	// After getting new values, according to the values, it should be distinguished as errormessages.
	// What if I put wrong number into char -> it is supposed to show proper errormessage.
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
		else if(selection != 'Y' && selection != 'y' && selection != 'N' && selection != 'n')
		{
			ErrorMessage.message("Only (Y)es or (N)o are acceptable");
			is.clear();
			is.setstate(ios::failbit);
		}
		return is;
	}

	// --------------------------------------------------------------------------------------- helper functions

	std::ostream& operator<< (std::ostream& os, const iProduct& anotherobject)
	// << symbol means that call write function with the data of current object and set the output by using write function.
	{
		anotherobject.write(os, true);
		return os;
	}

	std::istream& operator>> (std::istream& is, iProduct& anotherobject)
	// >> symbol means that call read function with the data of current object and set the new values by using read function.
	{
		anotherobject.read(is);
		return is;
	}

	double operator+= (double& number, const iProduct& anotherobject)
	// += symbol means that add total cost of current object and inital number value (parameter) and return the value of number (parameter)
	{
		number += anotherobject.total_cost();
		return number;
	}
}