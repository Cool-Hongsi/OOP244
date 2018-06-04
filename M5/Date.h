#pragma once
// Final Project Milestone 5 - The Perishable class
// -----------------------------------------------------------
// Name : Sungjun Hong     Date : 2018-04-09    Reason : Complete MileStone 5
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
	public:
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

		std::istream& read(std::istream&);
		std::ostream& write(std::ostream&) const;

		friend std::istream& operator>> (std::istream&, Date&); // helper
		friend std::ostream& operator<< (std::ostream&, Date&); // helper 

	};
	std::istream& operator>> (std::istream&, Date&); // helper
	std::ostream& operator<< (std::ostream&, Date&); // helper 
}
#endif