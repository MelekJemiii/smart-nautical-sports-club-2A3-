#include "mainwindow.h"
#include "menu.h"
#include "home.h"
#include "mdp.h"
#include "login.h"
#include <QMessageBox>
#include <QApplication>
#include "connection.h"
#include "employe.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    mdp pass;
    home h;
    menu m;
    MainWindow w;
    Connection c;
    employe e;
    bool test=c.createconnect();
    if (test)
    {
         w.show();
//         QMessageBox::critical(nullptr,QObject::tr("database is open"),
//                               QObject::tr("connection successful\n"
//                                           "click Cancel to exit"),QMessageBox::Cancel);
    }else{
//        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
//                              QObject::tr("connection failed.\n"
//                                          "click Cancel to exit"),QMessageBox::Cancel);
    }
    return a.exec();
}
