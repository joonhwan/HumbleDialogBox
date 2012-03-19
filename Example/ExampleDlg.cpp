
// ExampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Example.h"
#include "ExampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CExampleDlg dialog

CExampleDlg::CExampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	composer = new ChainComposer(*this);
}

//virtual
CExampleDlg::~CExampleDlg()
{
	delete composer;
}

//virtual
void CExampleDlg::setSelectionList(FilterList& filters)
{
	setListBox(IDC_SELECTIONLIST, filters);
}

//virtual
void CExampleDlg::setChainList(FilterList& filters)
{
	setListBox(IDC_CHAINLIST, filters);
}

//virtual
int CExampleDlg::selectionListCount(void) const
{
	return getListBox(IDC_SELECTIONLIST)->GetCount();
}

//virtual
int CExampleDlg::chainListCount(void) const
{
	return getListBox(IDC_CHAINLIST)->GetCount();
}

void CExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

CListBox* CExampleDlg::getListBox(UINT id)
{
	CListBox* listBox = (CListBox*)GetDlgItem(id);
	return listBox;
}

const CListBox* CExampleDlg::getListBox(UINT id) const
{
	CListBox* listBox = (CListBox*)GetDlgItem(id);
	return listBox;
}

void CExampleDlg::setListBox(UINT id, FilterList& filters)
{
	CListBox* listBox = getListBox(id);
	listBox->ResetContent();

	for(FilterList::iterator it=filters.begin(); it!=filters.end(); ++it) {
		listBox->AddString(CString((*it)->getName()));
	}
}

BEGIN_MESSAGE_MAP(CExampleDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_ADD, &CExampleDlg::OnBnClickedBtnAdd)
END_MESSAGE_MAP()


// CExampleDlg message handlers

BOOL CExampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	composer->initialize();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CExampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CExampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CExampleDlg::OnBnClickedBtnAdd()
{
	CListBox* listBox = (CListBox*)GetDlgItem(IDC_SELECTIONLIST);
	composer->add(	listBox->GetCurSel() );
}
