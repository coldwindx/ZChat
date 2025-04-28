#include <QApplication>
#include <QFile>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 加载qss文件
    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly)){
        qDebug("open .qss success!");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }else{
        qDebug("open .qss failed!");
    }

    MainWindow w;
    w.show();

    return a.exec();
}
