#include "ieaxwidget.h"
#include <QDebug>
#include <QThread>

IeAxWidget::IeAxWidget(QWidget *parent, Qt::WindowFlags f) :
    QAxWidget(parent,f)
{
    setControl("{8856F961-340A-11D0-A96B-00C04FD705A2}");
    qDebug() << "IeAxWidget::IeAxWidget" << GetCurrentThreadId();
}
