#include "mdp.h"
#include "ui_mdp.h"
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QTableWidgetItem>
#include <QMessageBox>

mdp::mdp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mdp)
{
    ui->setupUi(this);
}

mdp::~mdp()
{
    delete ui;
}


int mdp::verif_mdp(QString role){

    QString pass=ui->pass->text();
       QSqlQuery getIdQuery1;
      if (role == "emp")
       getIdQuery1.prepare("SELECT TYPE FROM ROLE WHERE CODE = :pass");
       getIdQuery1.bindValue(":pass", pass);
       if (getIdQuery1.exec() && getIdQuery1.next()) {
           if(getIdQuery1.value(0).toString() == "admin" || getIdQuery1.value(0).toString() == "RH"){
               accept();
               return 1;
           }else{
               return -1;
           }
       }else{
          return 0;
       }
}





