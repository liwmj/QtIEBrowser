#include "widget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QProcess>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(640,480);
    QVBoxLayout *lyMain = new QVBoxLayout;
    setLayout(lyMain);

    QPushButton *btn = new QPushButton("internet option",this);
    lyMain->addWidget(btn);
    connect(btn,SIGNAL(clicked()),this,SLOT(openInternetOption()));

    m_ieWebView = new IEWebView(this);
    lyMain->addWidget(m_ieWebView);

    connect(m_ieWebView,SIGNAL(sigOpenInNewTab(QString)),this,SLOT(loadUrlInNewTab(QString)));
//    m_ieWebView->loadUrl("E:\\PowerFull\\MyProjects\\TestProject\\IEWebBrowser\\IEWebBrowser\\test.html");
    m_ieWebView->loadUrl("http://132.147.160.199:8095/inhis/");
}

Widget::~Widget()
{
    
}

void Widget::loadUrlInNewTab(const QString &url)
{
    IEWebView *ie = new IEWebView;
    ie->loadUrl(url);
    ie->show();
}

void Widget::openInternetOption()
{
    qDebug() << "Widget::openInternetOption()";
    //QProcess::startDetached("cmd.exe /C Inetcpl.cpl");
    ::ShellExecuteA(NULL,"open","cmd.exe","/C Inetcpl.cpl",NULL,SW_HIDE);
}
