#pragma once

#include "Filter.h"

class ChainComposerView
{
public:
	ChainComposerView() {
	}
	virtual ~ChainComposerView() {
	}
	virtual void setSelectionList(FilterList& filters) = 0;
	virtual void setChainList(FilterList& filters) = 0;
	virtual int selectionListCount(void) const = 0;
	virtual int chainListCount(void) const = 0;
};

