#pragma once

#include "Filter.h"

class ReverbFilter : public Filter
{
public:
	virtual const char* getName(void) const
	{
		return "Reverb";
	}
};
