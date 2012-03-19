#pragma once

#include <vector>

class Filter;
typedef std::vector<Filter*> FilterList;

class Filter
{
public:
	virtual const char* getName(void) const = 0;
};
