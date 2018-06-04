#pragma once
// Final Project Milestone 5 - The Perishable class
// --------------------------------------------------------------
// Name : Sungjun Hong     Date : 2018-04-09    Reason : Complete MileStone 5
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>

namespace AMA
{
	class ErrorState
	{

	public:
		char* ErrorMessage;

	public:
		ErrorState();
		explicit ErrorState(const char*);

		ErrorState(const ErrorState&) = delete; // prohibit copy
		ErrorState& operator= (const ErrorState&) = delete; // prohibit copy

		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char*);
		const char* message() const;

	};

	std::ostream& operator<< (std::ostream&, ErrorState&);
}

