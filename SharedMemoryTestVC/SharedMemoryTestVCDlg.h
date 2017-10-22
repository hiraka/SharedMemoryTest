
// SharedMemoryTestVCDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once
#include "afxwin.h"
#include <cstdint>


// CSharedMemoryTestVCDlg �_�C�A���O
class CSharedMemoryTestVCDlg : public CDialogEx
{
// �R���X�g���N�V����
public:
	CSharedMemoryTestVCDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^�[

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAREDMEMORYTESTVC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g


// ����
protected:
	HANDLE m_hMap;
	uint32_t* m_strAllCmd;
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_editBox;
};