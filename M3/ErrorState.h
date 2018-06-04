#pragma once
// --------------------------------------------------------------
// Name : Sungjun Hong             Date : 2018-03-23               Reason : Complete MileStone 3
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

