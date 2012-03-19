#ifndef _MOCKCHAINCOMPOSERVIEW_H_
#define _MOCKCHAINCOMPOSERVIEW_H_

#include "ChainComposerView.h"

class MockChainComposerView : public ChainComposerView
{
public:
	virtual void setSelectionList(FilterList& filters);
	virtual void setChainList(FilterList& filters);
	virtual int selectionListCount(void) const;
	virtual int chainListCount(void) const;
protected:
	FilterList selectionList;
	FilterList chainList;
};

#endif /* _MOCKCHAINCOMPOSERVIEW_H_ */
