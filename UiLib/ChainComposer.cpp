#include "ChainComposer.h"
#include "ChainComposerView.h"
#include "ReverbFilter.h"

ChainComposer::ChainComposer(ChainComposerView& view)
	: m_view(view)
{
}

//virtual
ChainComposer::~ChainComposer()
{
 	for(FilterList::iterator it=filters.begin(); it!=filters.end(); ++it) {
		delete (*it);
	}
}

void ChainComposer::initialize(void)
{
	filters.push_back(new ReverbFilter);
	m_view.setSelectionList(filters);

	chainFilters.clear();
	m_view.setChainList(chainFilters);
}

void ChainComposer::add(int filterIndex)
{
	chainFilters.push_back(filters[filterIndex]);
	m_view.setChainList(chainFilters);
}

