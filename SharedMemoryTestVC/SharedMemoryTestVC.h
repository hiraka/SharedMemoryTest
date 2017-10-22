
// SharedMemoryTestVC.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CSharedMemoryTestVCApp:
// このクラスの実装については、SharedMemoryTestVC.cpp を参照してください。
//

class CSharedMemoryTestVCApp : public CWinApp
{
public:
	CSharedMemoryTestVCApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CSharedMemoryTestVCApp theApp;