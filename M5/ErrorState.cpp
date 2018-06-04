// Final Project Milestone 5 - The Perishable class
// --------------------------------------------------------------
// Name : Sungjun Hong     Date : 2018-04-09    Reason : Complete MileStone 5
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "ErrorState.h"
using namespace std;

namespace AMA
{
	ErrorState::ErrorState()
	{
		this->ErrorMessage = nullptr;
	}

	ErrorState::ErrorState(const char* GetErrorMessage = nullptr)
	{
		if (GetErrorMessage != nullptr)
		{
			this->ErrorMessage = new char[strlen(GetErrorMessage) + 1];
			strncpy(this->ErrorMessage, GetErrorMessage, strlen(GetErrorMessage) + 1);
		}
		else
		{
			this->ErrorMessage = nullptr;
		}
	}

	ErrorState::~ErrorState()
	{
		delete[] ErrorMessage;
	}

	void ErrorState::clear()
	{
		this->ErrorMessage = nullptr;
	}

	bool ErrorState::isClear() const
	{
		if (this->ErrorMessage == nullptr)
		{
			return true;
		}

		return false;
	}

	void ErrorState::message(const char* str)
	{
		delete[] this->ErrorMessage;

		this->ErrorMessage = new char[strlen(str) + 1];
		strncpy(this->ErrorMessage, str, strlen(str) + 1);
	}

	const char* ErrorState::message() const
	{
		return this->ErrorMessage;
	}

	std::ostream& operator<< (std::ostream& ostr, ErrorState& object)
	{
		if (object.isClear() == true) // nullptr
		{
			return ostr;
		}
		else // not nullptr
		{
			return ostr << object.message();
		}
	}
}