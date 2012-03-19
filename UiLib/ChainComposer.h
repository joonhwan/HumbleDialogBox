#pragma

#include "Filter.h"

class ChainComposerView;

class ChainComposer
{
public:
    ChainComposer(ChainComposerView& view);
    virtual ~ChainComposer();
	void initialize(void);
	// "add" button click command
	void add(int filterIndex);
protected:
	ChainComposerView& m_view;
	FilterList filters;
	FilterList chainFilters;
};
