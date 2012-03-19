#include "stdafx.h"
#include "TestHarness.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWinApp theApp;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: MFC initialization failed\n"));
		nRetCode = 1;
	}
	else
	{
		TestResult tr;
		TestRegistry::runAllTests(tr);
		nRetCode = tr.getFailureCount();
	}

	return nRetCode;
}
