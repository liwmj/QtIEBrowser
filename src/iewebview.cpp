#include <QDebug>
#include <QVBoxLayout>
#include <windows.h>
#include "iewebview.h"

int IEWebView::s_viewCount = 0;



IEWebView::IEWebView(QWidget *parent) :
    QWidget(parent)
{
    s_viewCount++;
    QVBoxLayout *lyMain = new QVBoxLayout;
    setLayout(lyMain);
    lyMain->setMargin(0);
    lyMain->setContentsMargins(0,0,0,0);
    m_ieAxWidget = new IeAxWidget(this);
    lyMain->addWidget(m_ieAxWidget);
    //connect(m_ieAxWidget,SIGNAL(signal (QString,int,void*)),this,SLOT(slot(QString,int,void*)));
    //connect(m_ieAxWidget,SIGNAL(TitleChange(QString)),this,SLOT(onTitleChanged(QString)));
    connect(m_ieAxWidget,SIGNAL(NewWindow3(IDispatch**,bool&,uint,QString,QString)),
            this,SLOT(onNewWindow3(IDispatch**,bool&,uint,QString,QString)));
}

IEWebView::~IEWebView()
{
    s_viewCount--;
}

void IEWebView::loadUrl(const QString &url, const QString &title)
{
    m_ieAxWidget->dynamicCall("Navigate2(const QString&)",url);
}

void IEWebView::onTitleChanged(const QString &title)
{
    qDebug() << "IEWebView::onTitleChanged" << title;
}

void IEWebView::onNewWindow3(IDispatch **ppDisp, bool &cancel, uint dwFlags, QString urlContext, QString url)
{
    qDebug() << "IEWebView::onNewWindow3" << cancel << dwFlags << urlContext << url;
    cancel = true;
    emit sigOpenInNewTab(url);
}

void IEWebView::slot(const QString &name, int argc, void *argv)
{
//    VARIANTARG *params = (VARIANTARG*)argv;
    qDebug() << "IEWebView::slot" << name << argc;
}
