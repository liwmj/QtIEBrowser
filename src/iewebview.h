#ifndef IEWEBVIEW_H
#define IEWEBVIEW_H

#include <QWidget>
#include <QUrl>
#include "ieaxwidget.h"

class IEWebView : public QWidget{
    Q_OBJECT

public:
    IEWebView(QWidget *parent = 0);
    ~IEWebView();
    void loadUrl(const QString &url, const QString &title = QString());

signals:
    void sigOpenInNewTab(const QString&);

public slots:
    void onTitleChanged(const QString& title);
    void onNewWindow3(IDispatch** ppDisp,bool& cancel,uint dwFlags,QString urlContext ,QString url);
    void slot(const QString &name, int argc, void *argv);
private:
    static int s_viewCount;
    IeAxWidget *m_ieAxWidget;

};

#endif // IEWEBVIEW_H
