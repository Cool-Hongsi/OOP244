#pragma once
// Final Project Milestone 5 - The Perishable class
// Version 3.3
// iProduct.h
// Date	2018-04-09
// Authors	Fardad Soleimanloo, Chris Szalwinski
//
// For your final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Chris              2017-12-02           Streamable -> Product
// Chris              2018-01-25           Product -> iProduct
// Chris              2018-02-07           I/O Alignment
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

#ifndef AMA_IPRODUCT_H__
#define AMA_IPRODUCT_H__

namespace AMA
{
	class iProduct
	{
	public:
		virtual std::fstream& store(std::fstream& file, bool newLine = true)const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear)const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator==(const char*) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iProduct&) const = 0;
	};
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
	iProduct* CreateProduct();
	iProduct* CreatePerishable();
}
#endif