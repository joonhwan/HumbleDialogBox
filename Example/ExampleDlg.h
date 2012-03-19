#pragma once

#include "ChainComposer.h" // smart class
#include "ChainComposerView.h" // mock interface

class CExampleDlg : public CDialog
				  , public ChainComposerView
{
// Construction
public:
	CExampleDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CExampleDlg();

	// ChainComposerView interfaces
	virtual void setSelectionList(FilterList& filters);
	virtual void setChainList(FilterList& filters);
	virtual int selectionListCount(void) const;
	virtual int chainListCount(void) const;

// Dialog Data
	enum { IDD = IDD_EXAMPLE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	ChainComposer* composer;

	CListBox* getListBox(UINT id);
	const CListBox* getListBox(UINT id) const;
	void setListBox(UINT id, FilterList& filters);

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedBtnAdd();
	DECLARE_MESSAGE_MAP()
};
