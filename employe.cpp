#include "employe.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QObject>
#include <QSqlQueryModel>
#include <QTableWidgetItem>


void employe::ajouter_employe(Ui::MainWindow *ui) {

    id_activite = ui->id_act_emp->currentText();
    QSqlQuery getIdQuery3;
    getIdQuery3.prepare("SELECT ID FROM ACTIVITE WHERE NOM = :nom");
    getIdQuery3.bindValue(":nom", id_activite);

    type = ui->role_emp->currentText();
    QSqlQuery getIdQuery;
    getIdQuery.prepare("SELECT ID FROM ROLE WHERE TYPE = :type");
    getIdQuery.bindValue(":type", type);

    id_local = ui->id_loc_emp->currentText();
    QSqlQuery getIdQuery1;
    getIdQuery1.prepare("SELECT ID FROM LOCAL WHERE NOM = :nom");
    getIdQuery1.bindValue(":nom", id_local);

    if (getIdQuery.exec() && getIdQuery1.exec() && getIdQuery3.exec() ) {
        if (getIdQuery.next() && getIdQuery1.next() && getIdQuery3.next()) {
            int roleId = getIdQuery.value(0).toInt();
            int localId = getIdQuery1.value(0).toInt();
            int activiteId = getIdQuery3.value(0).toInt();
            qDebug() << "Role ID found: " << roleId;

            prenom = ui->prenom_emp->text();
            nom = ui->nom_emp->text();
            mail = ui->mail_emp->text();
            adresse = ui->adresse_emp->text();
            gender = ui->gender_emp->currentText();
            salaire = ui->salaire_emp->text().toInt();
            dob = ui->dob_emp->date();

            QSqlQuery query;
            QString sql = "INSERT INTO EMPLOYE ( NOM, PRENOM, ADRESSE, GENDER, MAIL, SALAIRE, ID_ACT, ID_LOC, DOB, TYPE) "
                          "VALUES (:nom, :prenom, :adresse, :gender, :mail, :salaire, :id_act, :id_loc, :dob, :type)";
            query.prepare(sql);
            query.bindValue(":nom", nom);
            query.bindValue(":prenom", prenom);
            query.bindValue(":adresse", adresse);
            query.bindValue(":mail", mail);
            query.bindValue(":gender", gender);
            query.bindValue(":salaire", salaire);
            query.bindValue(":id_loc", localId);
            query.bindValue(":id_act", activiteId);
            query.bindValue(":dob", dob);
            query.bindValue(":type", roleId);

            if (query.exec()) {
                qDebug() << "Data inserted successfully.";
                ui->nom_emp->clear();
                ui->prenom_emp->clear();
                ui->mail_emp->clear();
                ui->adresse_emp->clear();
                ui->salaire_emp->clear();
                ui->dob_emp->setDate(QDate::currentDate());
                afficher_employe2(ui);
                afficher_employe(ui);
            } else {
                qDebug() << "Error inserting data:" << query.lastError().text() << query.lastError().databaseText();
            }
        } else {
            qDebug() << "No matching record found for type: " << type << " or local ID: " << id_local;
        }
    } else {
        qDebug() << "Error executing query:" << getIdQuery.lastError().text() << getIdQuery.lastError().databaseText();
    }
}



void employe::afficher_employe(Ui::MainWindow *ui) {

    QSqlQuery query;

    query.prepare("SELECT * FROM EMPLOYE");

    if (query.exec()) {
        ui->tab_employe_2->clearContents();
        ui->tab_employe_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_employe_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_employe_2->setHorizontalHeaderItem(col, headerItem);
        }


        int row = 0;
        while (query.next()) {
            ui->tab_employe_2->insertRow(row);
            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_employe_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}



void employe::init_employe(Ui::MainWindow *ui) {

    QSqlQuery query;
    query.prepare("SELECT NOM FROM ACTIVITE");
    query.exec();
    if (query.isActive()) {
        while (query.next()) {
            int columnCount = query.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query.value(i).toString();
                ui->id_act_emp->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query.lastError().text() << query.lastError().databaseText();
    }


    QSqlQuery query1;
    query1.prepare("SELECT TYPE FROM ROLE");
    query1.exec();

    if (query1.isActive()) {
        while (query1.next()) {
            int columnCount = query1.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query1.value(i).toString();
                ui->role_emp->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query1.lastError().text() << query1.lastError().databaseText();
    }


    QSqlQuery query2;
    query2.prepare("SELECT NOM FROM LOCAL");
    query2.exec();

    if (query2.isActive()) {
        while (query2.next()) {
            int columnCount = query2.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query2.value(i).toString();
                ui->id_loc_emp->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query2.lastError().text() << query2.lastError().databaseText();
    }
}


void employe::supprimer_employe(Ui::MainWindow *ui) {
    QString id;
    id = ui->emp_a_supp->text();
    QSqlQuery query;
    QString sql = "DELETE FROM EMPLOYE WHERE ID=:id";

    qDebug() << "Executing SQL query:" << sql;
    qDebug() << "Binding value for :id:" << id;

    query.prepare(sql);
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Delete operation successful. Rows affected:" << query.numRowsAffected();
        afficher_employe(ui);
        afficher_employe2(ui);
        ui->emp_a_supp->clear();
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}

void employe::modifier_employe(Ui::MainWindow *ui){

    QString id_activite = ui->idact_emp_modif->currentText();
    QSqlQuery getIdQuery3;
    getIdQuery3.prepare("SELECT ID FROM ACTIVITE WHERE NOM = :nom");
    getIdQuery3.bindValue(":nom", id_activite);

    QString type = ui->role_emp_modif->currentText();
    QSqlQuery getIdQuery;
    getIdQuery.prepare("SELECT ID FROM ROLE WHERE TYPE = :type");
    getIdQuery.bindValue(":type", type);

    QString id_local = ui->idloc_emp_modif->currentText();
    QSqlQuery getIdQuery1;
    getIdQuery1.prepare("SELECT ID FROM LOCAL WHERE NOM = :nom");
    getIdQuery1.bindValue(":nom", id_local);

    if (getIdQuery3.exec() && getIdQuery3.next() &&
        getIdQuery.exec() && getIdQuery.next() &&
        getIdQuery1.exec() && getIdQuery1.next()) {

        QSqlQuery query;
        query.prepare("UPDATE EMPLOYE SET NOM=:nom, PRENOM=:prenom, ADRESSE=:adresse, GENDER=:gender, MAIL=:mail, SALAIRE=:salaire, ID_ACT=:id_act, ID_LOC=:id_loc, DOB=:dob, TYPE=:type WHERE ID=:id");
        query.bindValue(":id", ui->id_emp_modif->text());
        query.bindValue(":nom", ui->nom_emp_modif->text());
        query.bindValue(":prenom", ui->prenom_emp_modif->text());
        query.bindValue(":adresse", ui->adresse_emp_modif->text());
        query.bindValue(":gender", ui->gender_emp_modif->currentText());
        query.bindValue(":mail", ui->mail_emp_modif->text());
        query.bindValue(":salaire", ui->salaire_emp_modif->text().toInt());
        query.bindValue(":id_act", getIdQuery3.value(0).toInt());
        query.bindValue(":id_loc", getIdQuery1.value(0).toInt());
        query.bindValue(":dob", ui->dob_emp_modif->date());
        query.bindValue(":type", getIdQuery.value(0).toInt());

        if (query.exec()) {
            qDebug() << "Data updated successfully.";
            afficher_employe2(ui);
            afficher_employe(ui);
             ui->emp_a_supp->clear();
            ui->nom_emp_modif->clear();
            ui->prenom_emp_modif->clear();
            ui->mail_emp_modif->clear();
            ui->adresse_emp_modif->clear();
            ui->salaire_emp_modif->clear();
            ui->dob_emp_modif->setDate(QDate::currentDate());
        } else {
            qDebug() << "Error updating data:" << query.lastError().text() << query.lastError().databaseText();
        }
    } else {
        qDebug() << "Error executing query to get IDs:" << getIdQuery.lastError().text() << getIdQuery.lastError().databaseText();
    }
}


void employe::init_employe2(Ui::MainWindow *ui) {

    QSqlQuery query;
    query.prepare("SELECT NOM FROM ACTIVITE");
    query.exec();

    if (query.isActive()) {
        while (query.next()) {
            int columnCount = query.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query.value(i).toString();
                ui->idact_emp_modif->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query.lastError().text() << query.lastError().databaseText();
    }


    QSqlQuery query1;
    query1.prepare("SELECT TYPE FROM ROLE");
    query1.exec();

    if (query1.isActive()) {
        while (query1.next()) {
            int columnCount = query1.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query1.value(i).toString();
                ui->role_emp_modif->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query1.lastError().text() << query1.lastError().databaseText();
    }


    QSqlQuery query2;
    query2.prepare("SELECT NOM FROM LOCAL");
    query2.exec();

    if (query2.isActive()) {
        while (query2.next()) {
            int columnCount = query2.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query2.value(i).toString();
                ui->idloc_emp_modif->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query2.lastError().text() << query2.lastError().databaseText();
    }
}



void employe::afficher_employe2(Ui::MainWindow *ui) {

    QSqlQuery query;

    query.prepare("SELECT * FROM EMPLOYE");


    if (query.exec()) {
        ui->tab_employe_modif_2->clearContents();
        ui->tab_employe_modif_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_employe_modif_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_employe_modif_2->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_employe_modif_2->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_employe_modif_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void employe::tri_emp(Ui::MainWindow *ui,QString choix) {

    int columnIndex=-1;

    if (choix == "DOB")
        columnIndex=10;
    else if (choix == "Salaire")
        columnIndex=7;
    else if (choix == "Nom")
        columnIndex=1;

    if (columnIndex != -1) {
        ui->tab_employe_2->setSortingEnabled(false);

        ui->tab_employe_2->sortByColumn(columnIndex, Qt::AscendingOrder);

        ui->tab_employe_2->setSortingEnabled(true);

        ui->tab_employe_modif_2->setSortingEnabled(false);

        ui->tab_employe_modif_2->sortByColumn(columnIndex, Qt::AscendingOrder);

        ui->tab_employe_modif_2->setSortingEnabled(true);

        //afficher_employe2(ui);

        //qDebug() << "Table sorted by " << choix << " successfully.";
    } else {
        //qDebug() << choix << " column not found.";
    }
}

int employe::getColumnIndex(QTableWidget *table, const QString &columnName) {
    for (int col = 0; col < table->columnCount(); ++col) {
        QTableWidgetItem *headerItem = table->horizontalHeaderItem(col);
        if (headerItem->text() == columnName) {
            return col;
        }
    }
    return -1;
}





