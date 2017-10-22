
// SharedMemoryTestVCDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "SharedMemoryTestVC.h"
#include "SharedMemoryTestVCDlg.h"
#include "afxdialogex.h"
#include <cstdint>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSharedMemoryTestVCDlg �_�C�A���O



CSharedMemoryTestVCDlg::CSharedMemoryTestVCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHAREDMEMORYTESTVC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSharedMemoryTestVCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editBox);
}

BEGIN_MESSAGE_MAP(CSharedMemoryTestVCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSharedMemoryTestVCDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSharedMemoryTestVCDlg ���b�Z�[�W �n���h���[

BOOL CSharedMemoryTestVCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	m_hMap = CreateFileMapping((HANDLE)0xFFFFFFFF, NULL,
		PAGE_READWRITE, 0, sizeof(uint32_t), _T("SharedMemory"));

	m_strAllCmd = (uint32_t*)MapViewOfFile(m_hMap, FILE_MAP_WRITE, 0, 0, 0);

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CSharedMemoryTestVCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CSharedMemoryTestVCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSharedMemoryTestVCDlg::OnBnClickedButton1()
{

	int32_t x;
	CString s;
	m_editBox.GetWindowText(s);
	x = _ttoi(s);

	_memccpy(m_strAllCmd, &x, sizeof(uint32_t), sizeof(int32_t));

	//UnmapViewOfFile(m_strAllCmd);
}
