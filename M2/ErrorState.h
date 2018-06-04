#pragma once
// Final Project Milestone 2
//
// Version 2.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name : Sungjun Hong       Date : 2018.03.17       Reason : Complete Milestone 2
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>

namespace AMA
{
	class ErrorState
	{

	private:
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

