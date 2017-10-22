
// SharedMemoryTestVCDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "SharedMemoryTestVC.h"
#include "SharedMemoryTestVCDlg.h"
#include "afxdialogex.h"
#include <cstdint>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSharedMemoryTestVCDlg ダイアログ



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


// CSharedMemoryTestVCDlg メッセージ ハンドラー

BOOL CSharedMemoryTestVCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	m_hMap = CreateFileMapping((HANDLE)0xFFFFFFFF, NULL,
		PAGE_READWRITE, 0, sizeof(uint32_t), _T("SharedMemory"));

	m_strAllCmd = (uint32_t*)MapViewOfFile(m_hMap, FILE_MAP_WRITE, 0, 0, 0);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CSharedMemoryTestVCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
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
