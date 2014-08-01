#include "widget.h"
#include <QApplication>
#include <windows.h>
#include <QDebug>

HHOOK hhook,hcbthook;

LRESULT CALLBACK CallWndProc(int nCode,WPARAM wParam,LPARAM lParam)
{
    if (nCode < 0)  // do not process message
        return CallNextHookEx(hhook, nCode, wParam, lParam);
    CWPSTRUCT *pCwp = NULL;
    if(NULL != lParam)
    {
        pCwp = (CWPSTRUCT *)lParam;
        if(WM_CREATE == pCwp->message)
        {
            HWND hWnd = pCwp->hwnd;
            char strClassName[128] = {0};
            GetClassNameA(hWnd,(char*)&strClassName,128);
            if("Internet Explorer_TridentDlgFrame" == QString(strClassName))
            {
                qDebug() << "window create message." << strClassName;
                PostMessage(hWnd,WM_CLOSE,0,0);
            }
        }
    }
    return CallNextHookEx(hhook, nCode, wParam, lParam);
}

LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)  // do not process message
        return CallNextHookEx(hcbthook, nCode, wParam, lParam);
    if(HCBT_CREATEWND == nCode)
    {
        HWND hWnd = (HWND)wParam;
        char strClassName[128] = {0};
        GetClassNameA(hWnd,(char*)&strClassName,128);
        qDebug() << "CBTProc " << strClassName;
        if("Internet Explorer_TridentDlgFrame" == QString(strClassName))
            return 1;
    }
    return CallNextHookEx(hcbthook, nCode, wParam, lParam);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    hcbthook = SetWindowsHookEx(
                WH_CBT,
                CBTProc,
                (HINSTANCE) NULL, GetCurrentThreadId());
//    hhook = SetWindowsHookEx(
//                WH_CALLWNDPROC,
//                CallWndProc,
//                (HINSTANCE) NULL, GetCurrentThreadId());

    Widget w;
    w.showMaximized();
    int ret = a.exec();
//    UnhookWindowsHookEx(hhook);
    UnhookWindowsHookEx(hcbthook);
    return ret;
}
