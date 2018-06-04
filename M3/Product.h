#pragma once
// --------------------------------------------------------------
// Name : Sungjun Hong             Date : 2018-03-23               Reason : Complete MileStone 3
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <fstream>
#include "ErrorState.h"

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#define max_sku_length 7
#define max_unit_length 10
#define max_name_length 75
#define TAX 0.13

namespace AMA
{
	class Product
	{
	private:
		char product_type__;
		char sku__[max_sku_length + 1];
		char unit__[max_unit_length + 1];
		char* name__;
		int quantity_hand__;
		int quantity_need__;
		double price__;
		bool taxable__;
		ErrorState ErrorMessage; // An ErrorState object that holds the error state of the Product objects

	protected:
		void name(const char*);
		const char* name() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;

	public:
		// Product();
		Product(const char* checktype = "N"); // Put default value in only declaration
		Product(const char* sku, const char* name, const char* unit, int quantity_hand = 0, bool taxable = true,
			double price = 0.0, int quantity_need = 0); // Put default value in only declaration
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();

		// part 1
		void sku(const char*); // NI
		void unit(const char*); // NI
		// void name(const char*); // NI // declared in protected section
		void price(double); // NI
		void taxed(bool); // NI
		void quantity(int);
		void qtyNeeded(int); // NI

		// part 2
		const char* sku() const; // NI
		const char* unit() const; // NI
		// const char* name()const; // NI // declared in protected section
		double price() const; // NI
		bool taxed() const; // NI
		int quantity() const;
		int qtyNeeded() const; 

		// part 3
		double total_cost() const;
		bool isEmpty() const;
		bool operator==(const char*) const;
		int operator+=(int);
		bool operator> (const char*) const;
		bool operator> (const Product&) const;

		// part 4
		std::fstream& store(std::fstream&, bool) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
	};
	
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);

}
#endif