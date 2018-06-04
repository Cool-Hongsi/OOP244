// Final Project Milestone 5 - The Perishable class
// Version 3.3
// Allocator.cpp
// 2018-04-09
// Authors	Fardad Soleimanloo, Chris Szalwinski
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// -----------------------------------------------------------
// Name : Sungjun Hong     Date : 2018-04-09    Reason : Complete MileStone 5
/////////////////////////////////////////////////////////////////
#include "Product.h"
#include "Perishable.h"

namespace AMA {

	// creates an empty product
	//
	iProduct* CreateProduct() {
		return new Product();
	}

	// creates an empty perishable product
	//
	
	iProduct* CreatePerishable() {
		return new Perishable();
	}
	
}