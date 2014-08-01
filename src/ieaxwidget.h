#ifndef IEAXWIDGET_H
#define IEAXWIDGET_H

#include <QAxWidget>
#include <windows.h>

class IeAxWidget : public QAxWidget
{
public:
    IeAxWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);
protected:
    virtual bool translateKeyEvent(int message, int keycode) const
    {
        if (message >= WM_KEYFIRST && message <= WM_KEYLAST)
            return true;
        else
            return QAxWidget::translateKeyEvent(message, keycode);
    }
};

#endif // IEAXWIDGET_H
