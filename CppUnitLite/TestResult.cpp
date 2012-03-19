
#include "TestResult.h"
#include "Failure.h"

#include <stdio.h>


TestResult::TestResult ()
	: failureCount (0)
{
}


void TestResult::testsStarted () 
{
}


void TestResult::addFailure (const Failure& failure) 
{
#ifdef _MSC_VER
	fprintf (stdout, "%s(%d) : TestFailed: %s\n",
			 failure.fileName.asCharString (),
			 failure.lineNumber,
			 failure.message.asCharString ()
		);
#else
	fprintf (stdout, "%s%s%s%s%ld%s%s\n",
		"Failure: \"",
		failure.message.asCharString (),
		"\" " ,
		"line ",
		failure.lineNumber,
		" in ",
		failure.fileName.asCharString ());
#endif

	failureCount++;
}


void TestResult::testsEnded () 
{
	if (failureCount > 0)
		fprintf (stdout, "There were %ld failures\n", failureCount);
	else
		fprintf (stdout, "There were no test failures\n");
}

int TestResult::getFailureCount(void) const
{
	return failureCount;
}
