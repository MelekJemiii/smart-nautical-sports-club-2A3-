#include "login.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QObject>
#include <QSqlQueryModel>
#include <QTableWidgetItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"

int login::connec(Ui::MainWindow *ui){
    QString username = ui->username->text();
    QString password = ui->password->text();
    QSqlQuery query;

    QString sql = "SELECT * FROM EMPLOYE WHERE NOM=:username AND PRENOM=:password";
    query.prepare(sql);
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        return 1;
    } else {
        return 0;
    }
}

