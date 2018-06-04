#pragma once
// Final Project Milestone 5 - The Perishable class
// --------------------------------------------------------------
// Name : Sungjun Hong     Date : 2018-04-09    Reason : Complete MileStone 5
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "Product.h"
#include "Date.h"
#include "iProduct.h"
// do not need to include "ErrorState.h" since the Product.cpp is dealing with ErrorState

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

namespace AMA
{
	class Perishable : public Product
	{
	private:
		Date perishdate;

	public:
		Perishable(); // No argument Constructor 

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

		const Date& expiry() const;

	};

	std::ostream& operator<< (std::ostream& os, const Date& anotherobject);
}

#endif