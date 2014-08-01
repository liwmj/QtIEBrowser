#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "iewebview.h"

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void loadUrlInNewTab(const QString &url);
    void openInternetOption();

private:
    IEWebView *m_ieWebView;
};

#endif // WIDGET_H
