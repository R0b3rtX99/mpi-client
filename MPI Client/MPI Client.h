#ifndef _MPI_H
#define _MPI_H

#include <Windows.h>
#include <WindowsX.h>
#include <stdio.h>
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")
#include <CommCtrl.h>
#pragma comment(lib, "comctl32.lib")
#include <Uxtheme.h>
#pragma comment(lib, "UxTheme.lib")
#include <TlHelp32.h>
#include "resource.h"

#pragma comment(linker, "/manifestdependency:\"type='win32' \
    name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
    processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#define REGPATH_SUBKEY  L"Software\\MPI"
#define REGVAL_LOCATION L"Payload Location"

#define WM_NEWPACKET      WM_APP + 100 // wParam = lpPacketInfo, lParam = lpData
#define WM_IMAGELISTREADY WM_APP + 101 // wParam = hImageList

#define IMAGELIST_TIMER   1

typedef struct {
  DWORD cbData;
  DWORD dwData;
} PACKET_INFO;

INT_PTR CALLBACK InjectorProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam );
INT_PTR CALLBACK MPIProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam );
INT_PTR CALLBACK PlainDialogProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam );
INT_PTR CALLBACK FormattedDialogProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam );

void InitPacketList( HWND hwndDlg, int nIDDlgItem );

#endif