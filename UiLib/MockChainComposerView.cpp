#include "MockChainComposerView.h"

//virtual
void MockChainComposerView::setSelectionList(FilterList& filters)
{
	selectionList = filters;
}

//virtual
int MockChainComposerView::selectionListCount(void) const
{
	return (int)selectionList.size();
}

//virtual
void MockChainComposerView::setChainList(FilterList& filters)
{
	chainList = filters;
}

//virtual
int MockChainComposerView::chainListCount(void) const
{
	return (int)chainList.size();
}
