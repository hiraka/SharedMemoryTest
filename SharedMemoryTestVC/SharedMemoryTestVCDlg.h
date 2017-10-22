
// SharedMemoryTestVCDlg.h : ヘッダー ファイル
//

#pragma once
#include "afxwin.h"
#include <cstdint>


// CSharedMemoryTestVCDlg ダイアログ
class CSharedMemoryTestVCDlg : public CDialogEx
{
// コンストラクション
public:
	CSharedMemoryTestVCDlg(CWnd* pParent = NULL);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAREDMEMORYTESTVC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HANDLE m_hMap;
	uint32_t* m_strAllCmd;
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_editBox;
};
