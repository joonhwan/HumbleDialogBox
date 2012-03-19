#include "stdafx.h"
#include "MockChainComposerView.h"
#include "ChainComposer.h"
#include "TestHarness.h"

TEST(initialize, ChainComposer)
{
	MockChainComposerView view;
	ChainComposer composer(view);

	LONGS_EQUAL(0, view.selectionListCount());
	composer.initialize();
	LONGS_EQUAL(1, view.selectionListCount());
}

TEST(selectFilter, ChainComposer)
{
	MockChainComposerView view;
	ChainComposer composer(view);

	composer.initialize();

	composer.add(0);
	LONGS_EQUAL(1, view.chainListCount());
}
