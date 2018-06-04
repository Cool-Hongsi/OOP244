#pragma once
// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name : Sungjun Hong       Date : 2018.03.12       Reason : Complete Milestone 1
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

const int min_year = 2000;
const int max_year = 2030;
const int NO_ERROR = 0;
const int CIN_FAILED = 1;
const int YEAR_ERROR = 2;
const int MON_ERROR = 3; 
const int DAY_ERROR = 4;

namespace AMA {

	class Date {

		int year; // between 2000 ~ 2030
		int month; // between 1 ~ 12
		int day; // Feb -> 29

		int compvalue; // The comparator value
		int errstate; // The error state

		int mdays(int, int)const;
		void errCode(int errorCode);

	public:

		Date();

		Date(int, int, int);

		bool operator== (const Date&) const;
		bool operator!= (const Date&) const;
		bool operator< (const Date&) const;
		bool operator> (const Date&) const;
		bool operator<= (const Date&) const;
		bool operator>= (const Date&) const;
	
		
		int errCode() const;

		bool bad() const;

		std::istream& read (std::istream&);
		std::ostream& write (std::ostream&) const;
		
	};

	std::istream& operator>> (std::istream&, Date&); // helper
	std::ostream& operator<< (std::ostream&, Date&); // helper 
	
	






}
#endif