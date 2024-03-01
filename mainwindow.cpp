#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "home.h"
#include "menu.h"
#include "employe.h"
#include "client.h"
#include"local.h"
#include"moyen.h"
#include"activite.h"
#include"event.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>


client cli;
login l;
employe emp;
activite act;
event ev;
moyen moy;
local loc;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->loginhome->setCurrentIndex(0);
    cli.afficher_client(ui);
    cli.afficher_client2(ui);
    cli.init_client(ui);
    cli.init_client2(ui);


    emp.afficher_employe(ui);
    emp.afficher_employe2(ui);
    emp.init_employe(ui);
    emp.init_employe2(ui);

    loc.afficher_local2(ui);
    loc.afficher_local(ui);
    loc.init_local(ui);
    loc.init_local2(ui);


    ev.afficher_event(ui);
    ev.afficher_event2(ui);
    ev.init_event(ui);
    ev.init_event2(ui);

    act.afficher_activite(ui);
    act.afficher_activite2(ui);
    act.init_activite(ui);
    act.init_activite2(ui);

    moy.afficher_moyen(ui);
    moy.afficher_moyen2(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_log_clicked()
{
    home h;
    menu m;

    if (l.connec(ui)){
        ui->loginhome->setCurrentIndex(1);
        ui->menuhome->setCurrentIndex(2);
    }
}

void MainWindow::on_gestion_employes_menu_clicked()
{
    ui->menuhome->setCurrentIndex(0);
    ui->main_page_->setCurrentIndex(2);
}

void MainWindow::on_home_clicked()
{
    ui->menuhome->setCurrentIndex(2);
}

void MainWindow::on_ajout_2_clicked()
{
    ui->main_emp_2->setCurrentIndex(0);
    ui->ajoutmodif_2->setCurrentIndex(1);
}

void MainWindow::on_modif_2_clicked()
{
    ui->main_emp_2->setCurrentIndex(0);
    ui->ajoutmodif_2->setCurrentIndex(0);
}

void MainWindow::on_aff_2_clicked()
{
    ui->main_emp_2->setCurrentIndex(1);
}

void MainWindow::on_ajout_loc_2_clicked()
{
    ui->main_loc_2->setCurrentIndex(0);
    ui->ajoutmodif_loc_2->setCurrentIndex(1);
}

void MainWindow::on_modif_loc_2_clicked()
{
    ui->main_loc_2->setCurrentIndex(0);
    ui->ajoutmodif_loc_2->setCurrentIndex(0);
}

void MainWindow::on_aff_loc_2_clicked()
{
    ui->main_loc_2->setCurrentIndex(1);
}

void MainWindow::on_gestion_locaux_menu_clicked()
{
    ui->menuhome->setCurrentIndex(0);
    ui->main_page_->setCurrentIndex(0);
    ui->main_loc_2->setCurrentIndex(1);
}

void MainWindow::on_gest_emp_2_clicked()
{
    on_gestion_employes_menu_clicked();
}

void MainWindow::on_gest_loc_2_clicked(){

    on_gestion_locaux_menu_clicked();
}

void MainWindow::on_gestion_sponsor_menu_clicked()
{
    ui->menuhome->setCurrentIndex(0);
    ui->main_page_->setCurrentIndex(1);
}

void MainWindow::on_gestion_client_menu_clicked()
{
    ui->menuhome->setCurrentIndex(0);
    ui->main_page_->setCurrentIndex(3);
}

void MainWindow::on_aff_cl_clicked()
{
    ui->main_cl->setCurrentIndex(1);
}

void MainWindow::on_ajout_cl_clicked()
{
    ui->main_cl->setCurrentIndex(0);
    ui->ajoutmodif_cl->setCurrentIndex(1);
}

void MainWindow::on_modif_cl_clicked()
{
    ui->main_cl->setCurrentIndex(0);
    ui->ajoutmodif_cl->setCurrentIndex(0);
}

void MainWindow::on_gest_client_2_clicked()
{
    on_gestion_client_menu_clicked();
}

void MainWindow::on_gest_sponsors_2_clicked()
{
    on_gestion_sponsor_menu_clicked();
}

void MainWindow::on_aff_moyen_clicked()
{
    ui->main_moyen->setCurrentIndex(1);

}

void MainWindow::on_ajout_moyen_clicked()
{
    ui->main_moyen->setCurrentIndex(0);
    ui->ajoutmodif_moyen->setCurrentIndex(1);
}

void MainWindow::on_modif_moyen_clicked()
{
    ui->main_moyen->setCurrentIndex(0);
    ui->ajoutmodif_moyen->setCurrentIndex(0);
}

void MainWindow::on_aff_sponsor_clicked()
{
    ui->main_sponsor->setCurrentIndex(1);

}

void MainWindow::on_ajout_sponsor_clicked()
{
    ui->main_sponsor->setCurrentIndex(0);
    ui->ajoutmodif_sponsor->setCurrentIndex(1);
}

void MainWindow::on_modif_sponsor_clicked()
{
    ui->main_sponsor->setCurrentIndex(0);
    ui->ajoutmodif_sponsor->setCurrentIndex(0);
}

void MainWindow::on_gestion_evenements_menu_clicked()
{
    ui->menuhome->setCurrentIndex(0);
    ui->main_page_->setCurrentIndex(4);
}

void MainWindow::on_aff_participant_clicked()
{
     ui->main_participant->setCurrentIndex(1);
}

void MainWindow::on_ajout_participant_clicked()
{
    ui->main_participant->setCurrentIndex(0);
    ui->ajoutmodif_participant->setCurrentIndex(1);
}

void MainWindow::on_modif_participant_clicked()
{
    ui->main_participant->setCurrentIndex(0);
    ui->ajoutmodif_participant->setCurrentIndex(0);
}

void MainWindow::on_aff_event_clicked()
{
    ui->main_event->setCurrentIndex(1);
}

void MainWindow::on_ajout_event_clicked()
{
    ui->main_event->setCurrentIndex(0);
    ui->ajoutmodif_event->setCurrentIndex(1);
}

void MainWindow::on_modif_event_clicked()
{
    ui->main_event->setCurrentIndex(0);
    ui->ajoutmodif_event->setCurrentIndex(0);
}

void MainWindow::on_gest_event_2_clicked()
{
    on_gestion_evenements_menu_clicked();
}

void MainWindow::on_logout_clicked()
{
    ui->loginhome->setCurrentIndex(0);
    //ui->username->clear();
}

void MainWindow::on_logout_2_clicked()
{
    ui->loginhome->setCurrentIndex(0);
    //ui->password->close();
}

void MainWindow::on_aff_act_clicked()
{
    ui->main_act->setCurrentIndex(1);
}

void MainWindow::on_ajout_act_clicked()
{
    ui->main_act->setCurrentIndex(0);
    ui->ajoutmodif_act->setCurrentIndex(1);
}

void MainWindow::on_modif_act_clicked()
{
    ui->main_act->setCurrentIndex(0);
    ui->ajoutmodif_act->setCurrentIndex(0);
}

void MainWindow::on_gestion_activites_menu_clicked()
{
    ui->menuhome->setCurrentIndex(0);
    ui->main_page_->setCurrentIndex(5);
}

void MainWindow::on_gest_act_2_clicked()
{
    on_gestion_activites_menu_clicked();
}

void MainWindow::on_ajouter_employes_clicked()
{
    if (ui->nom_emp->text().isEmpty() ||
        ui->prenom_emp->text().isEmpty() ||
        ui->mail_emp->text().isEmpty() ||
        ui->adresse_emp->text().isEmpty() ||
        ui->salaire_emp->text().isEmpty() ||
        ui->id_loc_emp->currentText().isEmpty() ||
        ui->id_act_emp->currentText().isEmpty() ||
        ui->dob_emp->date().isNull() ||
        ui->role_emp->currentText().isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please fill in all required fields.");
        return;
    }

    emp.ajouter_employe(ui);
}

void MainWindow::on_supprimer_emp_clicked()
{
    emp.supprimer_employe(ui);
}

void MainWindow::on_ajout_client_clicked()
{
    cli.ajouter_client(ui);
}

void MainWindow::on_tab_employe_modif_2_itemClicked(QTableWidgetItem *item)
{
    if (item != nullptr) {
        int row = item->row();
        QVariant data = ui->tab_employe_modif_2->item(row, 0)->data(Qt::DisplayRole);

        QString id = data.toString();
        QSqlQuery query;

        query.prepare("SELECT * FROM EMPLOYE WHERE ID=:id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            QString nom = query.value("NOM").toString();
            QString prenom = query.value("PRENOM").toString();
            QString adresse = query.value("ADRESSE").toString();
            QString mail = query.value("MAIL").toString();
            QString salaire = query.value("SALAIRE").toString();
            int id_role = query.value("TYPE").toInt();
            int id_loc = query.value("ID_LOC").toInt();
            int id_act = query.value("ID_ACT").toInt();
            QString id = query.value("ID").toString();
            QString gender = query.value("GENDER").toString();
            QDate dateOfBirth = query.value("DOB").toDate();

            QSqlQuery query_role;
            query_role.prepare("SELECT TYPE FROM ROLE WHERE ID=:id");
            query_role.bindValue(":id", id_role);

            QSqlQuery query_loc;
            query_loc.prepare("SELECT NOM FROM LOCAL WHERE ID=:id");
            query_loc.bindValue(":id", id_loc);

            QSqlQuery query_act;
            query_act.prepare("SELECT NOM FROM ACTIVITE WHERE ID=:id");
            query_act.bindValue(":id", id_act);

            if (query_role.exec() && query_role.next()) {
                ui->role_emp_modif->setCurrentText(query_role.value(0).toString());
            }

            if (query_loc.exec() && query_loc.next()) {
                ui->idloc_emp_modif->setCurrentText(query_loc.value(0).toString());
            }

            if (query_act.exec() && query_act.next()) {
                ui->idact_emp_modif->setCurrentText(query_act.value(0).toString());
            }

        ui->emp_a_supp->setText(id);

        ui->id_emp_modif->setText(id);
            ui->nom_emp_modif->setText(nom);
            ui->prenom_emp_modif->setText(prenom);
            ui->salaire_emp_modif->setText(salaire);
            ui->adresse_emp_modif->setText(adresse);
            ui->mail_emp_modif->setText(mail);
            ui->gender_emp_modif->setCurrentText(gender);
            ui->dob_emp_modif->setDate(dateOfBirth);
            //on_modif_2_clicked();

        } else {
            qDebug() << "No records found for ID:" << id;
        }
    }
}


void MainWindow::on_modifier_emp_clicked()
{
    emp.modifier_employe(ui);
}

void MainWindow::on_recherche_emp_textChanged(const QString &arg1)
{
    QString searchText = arg1.toLower();

    for (int row = 0; row < ui->tab_employe_2->rowCount(); ++row) {
        bool matchFound = false;

        for (int col : {1, 2, 3, 8, 9}) {
            QTableWidgetItem *item = ui->tab_employe_2->item(row, col);
            if (item && item->text().toLower().contains(searchText)) {
                matchFound = true;
                break;
            }
        }

        ui->tab_employe_2->setRowHidden(row, !matchFound);
    }
}


void MainWindow::on_tri_emp_activated(const QString &arg1)
{
    emp.tri_emp(ui,arg1);
}

void MainWindow::on_supp_client_clicked()
{
    cli.supprimer_client(ui);

}

void MainWindow::on_lineEdit_59_textChanged(const QString &arg1)
{
    QString searchText = arg1.toLower();

    for (int row = 0; row < ui->tab_client_2->rowCount(); ++row) {
        bool matchFound = false;

        for (int col : {0, 1, 2, 3, 9}) {
            QTableWidgetItem *item = ui->tab_client_2->item(row, col);
            if (item && item->text().toLower().contains(searchText)) {
                matchFound = true;
                break;
            }
        }

        ui->tab_client_2->setRowHidden(row, !matchFound);
        ui->tab_client->setRowHidden(row, !matchFound);

    }
}

void MainWindow::on_tab_client_itemClicked(QTableWidgetItem *item)
{
    if (item != nullptr) {
        int row = item->row();
        QVariant data = ui->tab_client->item(row, 7)->data(Qt::DisplayRole);

        QString id = data.toString();
        QSqlQuery query;

        query.prepare("SELECT * FROM CLIENT WHERE ID=:id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            QString nom = query.value("NOM").toString();
            QString prenom = query.value("PRENOM").toString();
            QString adresse = query.value("ADRESSE").toString();
            QString mail = query.value("MAIL").toString();
            QString type = query.value("TYPE").toString();
            QString niveau = query.value("NIVEAU").toString();
            QString tel = query.value("TEL").toString();
            QString id = query.value("ID").toString();
            QString gender = query.value("GENDER").toString();
            QDate dateOfBirth = query.value("DOB").toDate();


        ui->client_supp->setText(id);
ui->id_cli_modif->setText(id);

            ui->type_cli_modif->setCurrentText(type);
            ui->niveau_cli_modif->setCurrentText(niveau);

            ui->tel_cli_modif->setText(tel);
            ui->nom_cli_modif->setText(nom);
            ui->prenom_cli_modif->setText(prenom);
            ui->adresse_cli_modif->setText(adresse);
            ui->mail_cli_modif->setText(mail);
            ui->gender_cli_modif->setCurrentText(gender);
            ui->dob_cli_modif->setDate(dateOfBirth);
            //on_modif_2_clicked();

        } else {
            qDebug() << "No records found for ID:" << id;
        }
    }
}

void MainWindow::on_modif_cli_clicked()
{
    cli.modifier_client(ui);
}

void MainWindow::on_tri_client_activated(const QString &arg1)
{
    cli.tri_cli(ui,arg1);
}

void MainWindow::on_ajouter_loc_clicked()
{
    loc.ajouter_local(ui);
}

void MainWindow::on_tab_loc_modif_2_itemClicked(QTableWidgetItem *item)
{ if (item == nullptr) {
        return; // Exit if no valid item is selected
    }

    int row = item->row();
    QVariant data = ui->tab_loc_modif_2->item(row, 0)->data(Qt::DisplayRole);
    QString id = data.toString();

    QSqlQuery query, query_res;
    query.prepare("SELECT * FROM LOCAL WHERE ID=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString nom = query.value("NOM").toString();
        QString description = query.value("DESCRIPTION").toString();
        QString adresse = query.value("ADRESSE").toString();
        int id_res = query.value("ID_RESPON").toInt();
        QString type = query.value("TYPE").toString();

        QString sql1 = "SELECT NOM FROM EMPLOYE WHERE ID=:id_res";
        query_res.prepare(sql1);
        query_res.bindValue(":id_res", id_res);

        if (query_res.exec() && query_res.next()) {
            ui->loc_supp->setText(id);
            ui->id_loc_modif->setText(id);
            ui->nom_loc_mof->setText(nom);
            ui->adresse_loc_mof->setText(adresse);
            ui->res_loc_mof->setCurrentText(query_res.value(0).toString());
            ui->type_loc_mof->setCurrentText(type);
            ui->description_loc_mof->setText(description);

            // Call a function related to the modification (uncomment if needed)
            // on_modif_2_clicked();
        } else {
            qDebug() << "Failed to fetch employee name for ID:" << id_res;
        }
    } else {
        qDebug() << "No records found for ID:" << id;
    }

}

void MainWindow::on_tab_loc_2_itemClicked(QTableWidgetItem *item)
{
    if (item == nullptr) {
           return; // Exit if no valid item is selected
       }

       int row = item->row();
       QVariant data = ui->tab_loc_2->item(row, 0)->data(Qt::DisplayRole);
       QString id = data.toString();

       QSqlQuery query, query_res;
       query.prepare("SELECT * FROM LOCAL WHERE ID=:id");
       query.bindValue(":id", id);

       if (query.exec() && query.next()) {
           QString nom = query.value("NOM").toString();
           QString description = query.value("DESCRIPTION").toString();
           QString adresse = query.value("ADRESSE").toString();
           int id_res = query.value("ID_RESPON").toInt();
           QString type = query.value("TYPE").toString();

           QString sql1 = "SELECT NOM FROM EMPLOYE WHERE ID=:id_res";
           query_res.prepare(sql1);
           query_res.bindValue(":id_res", id_res);

           if (query_res.exec() && query_res.next()) {
               ui->loc_supp->setText(id);
               ui->id_loc_modif->setText(id);
               ui->nom_loc_mof->setText(nom);
               ui->adresse_loc_mof->setText(adresse);
               ui->res_loc_mof->setCurrentText(query_res.value(0).toString());
               ui->type_loc_mof->setCurrentText(type);
               ui->description_loc_mof->setText(description);

               // Call a function related to the modification (uncomment if needed)
               // on_modif_2_clicked();
           } else {
               qDebug() << "Failed to fetch employee name for ID:" << id_res;
           }
       } else {
           qDebug() << "No records found for ID:" << id;
       }
}

void MainWindow::on_modif_loc_clicked()
{
    loc.modifier_local(ui);
}

void MainWindow::on_pushButton_15_clicked()
{
    loc.supprimer_local(ui);
}

void MainWindow::on_ajout_event_2_clicked()
{
ev.ajouter_event(ui);
}



void MainWindow::on_event_supprimer_clicked()
{
    ev.supprimer_event(ui);
}

void MainWindow::on_tab_event_modif_2_itemClicked(QTableWidgetItem *item)
{

    if (item == nullptr) {
        return; // Exit if no valid item is selected
    }

    int row = item->row();
    QVariant data = ui->tab_event_modif_2->item(row, 0)->data(Qt::DisplayRole);
    QString id = data.toString();

    QSqlQuery query, query_local, query_res;
    query.prepare("SELECT * FROM EVENT WHERE ID=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString nom = query.value("NOM").toString();
        QString description = query.value("DESCRIPTION").toString();
        QString type = query.value("TYPE").toString();
        QDate date_event = query.value("DATE_EVENT").toDate();
        int id_local = query.value("ID_LOCAL").toInt();
        int id_res = query.value("ID_RES").toInt();
        int nbr_par = query.value("NBR_PARTICIPANTS").toInt();

        query_local.prepare("SELECT NOM FROM LOCAL WHERE ID=:id_local");
        query_local.bindValue(":id_local", id_local);

        if (query_local.exec() && query_local.next()) {
            QString nom_local = query_local.value(0).toString();

            query_res.prepare("SELECT NOM FROM EMPLOYE WHERE ID=:id_res");
            query_res.bindValue(":id_res", id_res);

            if (query_res.exec() && query_res.next()) {
                QString nom_res = query_res.value(0).toString();

                ui->event_supp->setText(id);
                ui->id_local_event_modif->setCurrentText(nom_local);
                ui->id_responsable_event_modif->setCurrentText(nom_res);
                ui->id_local_event_modif->setCurrentText(nom_local);
                ui->nom_event_modif->setText(nom);
                ui->description_event_modif->setText(description);
                ui->type_event_modif->setCurrentText(type);
                ui->date_event_modif->setDate(date_event);
                ui->nbr_participants_event_modif->setText(QString::number(nbr_par));

                // Call a function related to the modification (uncomment if needed)
                // on_modif_event_clicked();
            } else {
                qDebug() << "Failed to fetch employee name for ID:" << id_res;
            }
        } else {
            qDebug() << "Failed to fetch local name for ID:" << id_local;
        }
    } else {
        qDebug() << "No records found for ID:" << id;
    }
}

void MainWindow::on_tab_event_2_itemClicked(QTableWidgetItem *item)
{
    if (item == nullptr) {
        return; // Exit if no valid item is selected
    }

    int row = item->row();
    QVariant data = ui->tab_event_2->item(row, 0)->data(Qt::DisplayRole);
    QString id = data.toString();

    QSqlQuery query, query_local, query_res;
    query.prepare("SELECT * FROM EVENT WHERE ID=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString nom = query.value("NOM").toString();
        QString description = query.value("DESCRIPTION").toString();
        QString type = query.value("TYPE").toString();
        QDate date_event = query.value("DATE_EVENT").toDate();
        int id_local = query.value("ID_LOCAL").toInt();
        int id_res = query.value("ID_RES").toInt();
        int nbr_par = query.value("NBR_PARTICIPANTS").toInt();

        query_local.prepare("SELECT NOM FROM LOCAL WHERE ID=:id_local");
        query_local.bindValue(":id_local", id_local);

        if (query_local.exec() && query_local.next()) {
            QString nom_local = query_local.value(0).toString();

            query_res.prepare("SELECT NOM FROM EMPLOYE WHERE ID=:id_res");
            query_res.bindValue(":id_res", id_res);

            if (query_res.exec() && query_res.next()) {
                QString nom_res = query_res.value(0).toString();

                ui->event_supp->setText(id);
                ui->id_local_event_modif->setCurrentText(nom_local);
                ui->id_responsable_event_modif->setCurrentText(nom_res);
                ui->id_local_event_modif->setCurrentText(nom_local);
                ui->nom_event_modif->setText(nom);
                ui->description_event_modif->setText(description);
                ui->type_event_modif->setCurrentText(type);
                ui->date_event_modif->setDate(date_event);
                ui->nbr_participants_event_modif->setText(QString::number(nbr_par));

                // Call a function related to the modification (uncomment if needed)
                // on_modif_event_clicked();
            } else {
                qDebug() << "Failed to fetch employee name for ID:" << id_res;
            }
        } else {
            qDebug() << "Failed to fetch local name for ID:" << id_local;
        }
    } else {
        qDebug() << "No records found for ID:" << id;
    }
}

void MainWindow::on_tab_activite_modif_2_itemClicked(QTableWidgetItem *item)
{
    if (item == nullptr) {
        return; // Exit if no valid item is selected
    }

    int row = item->row();
    QVariant data = ui->tab_activite_modif_2->item(row, 0)->data(Qt::DisplayRole);
    QString id = data.toString();

    QSqlQuery query, query_local, query_res;
    query.prepare("SELECT * FROM ACTIVITE WHERE ID=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString nom = query.value("NOM").toString();
        QString description = query.value("DESCRIPTION").toString();
        QString type = query.value("TYPE").toString();
        QDate date_act = query.value("DATE_ACT").toDate();
        int id_local = query.value("ID_LOCAL").toInt();
        int id_coach = query.value("ID_COACH").toInt();
        QString materiel = query.value("MATERIEL").toString();
        query_local.prepare("SELECT NOM FROM LOCAL WHERE ID=:id_local");
        query_local.bindValue(":id_local", id_local);

        if (query_local.exec() && query_local.next()) {
            QString nom_local = query_local.value(0).toString();

            query_res.prepare("SELECT NOM FROM EMPLOYE WHERE ID=:id_coach");
            query_res.bindValue(":id_coach", id_coach);

            if (query_res.exec() && query_res.next()) {
                QString nom_coach = query_res.value(0).toString();

                ui->activite_supp->setText(id);
                ui->id_local_activite_modif->setCurrentText(nom_local);
                ui->id_coach_activite_modif->setCurrentText(nom_coach);
                ui->nom_activite_modif->setText(nom);
                ui->description_activite_modif->setText(description);
                ui->type_activite_modif->setCurrentText(type);
                ui->materiel_activite_modif->setCurrentText(materiel);
                ui->date_activite_modif->setDate(date_act);

                // Call a function related to the modification (uncomment if needed)
                // on_modif_activite_clicked();
            } else {
                qDebug() << "Failed to fetch coach name for ID:" << id_coach;
            }
        } else {
            qDebug() << "Failed to fetch local name for ID:" << id_local;
        }
    } else {
        qDebug() << "No records found for ID:" << id;
    }
}


void MainWindow::on_ajouter_act_clicked()
{
    act.ajouter_activite(ui);
}

void MainWindow::on_supp_act_clicked()
{
    act.supprimer_activite(ui);
}

void MainWindow::on_modifier_act_clicked()
{
    act.modifier_activite(ui);
}

void MainWindow::on_tab_activite_2_itemClicked(QTableWidgetItem *item)
{
    if (item == nullptr) {
        return; // Exit if no valid item is selected
    }

    int row = item->row();
    QVariant data = ui->tab_activite_2->item(row, 0)->data(Qt::DisplayRole);
    QString id = data.toString();

    QSqlQuery query, query_local, query_res;
    query.prepare("SELECT * FROM ACTIVITE WHERE ID=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString nom = query.value("NOM").toString();
        QString description = query.value("DESCRIPTION").toString();
        QString type = query.value("TYPE").toString();
        QDate date_act = query.value("DATE_ACT").toDate();
        int id_local = query.value("ID_LOCAL").toInt();
        int id_coach = query.value("ID_COACH").toInt();
        QString materiel = query.value("MATERIEL").toString();
        query_local.prepare("SELECT NOM FROM LOCAL WHERE ID=:id_local");
        query_local.bindValue(":id_local", id_local);

        if (query_local.exec() && query_local.next()) {
            QString nom_local = query_local.value(0).toString();

            query_res.prepare("SELECT NOM FROM EMPLOYE WHERE ID=:id_coach");
            query_res.bindValue(":id_coach", id_coach);

            if (query_res.exec() && query_res.next()) {
                QString nom_coach = query_res.value(0).toString();

                ui->activite_supp->setText(id);
                ui->id_local_activite_modif->setCurrentText(nom_local);
                ui->id_coach_activite_modif->setCurrentText(nom_coach);
                ui->nom_activite_modif->setText(nom);
                ui->description_activite_modif->setText(description);
                ui->type_activite_modif->setCurrentText(type);
                ui->materiel_activite_modif->setCurrentText(materiel);
                ui->date_activite_modif->setDate(date_act);

                // Call a function related to the modification (uncomment if needed)
                // on_modif_activite_clicked();
            } else {
                qDebug() << "Failed to fetch coach name for ID:" << id_coach;
            }
        } else {
            qDebug() << "Failed to fetch local name for ID:" << id_local;
        }
    } else {
        qDebug() << "No records found for ID:" << id;
    }
}

void MainWindow::on_ajouter_moyen_clicked()
{
    moy.ajouter_moyen(ui);
}

void MainWindow::on_supprimer_moyen_clicked()
{
    moy.supprimer_moyen(ui);
}

void MainWindow::on_modifier_moyen_clicked()
{
    moy.modifier_moyen(ui);
}

void MainWindow::on_tab_moyen_modif_2_itemClicked(QTableWidgetItem *item)
{
    if (item == nullptr) {
        return; // Exit if no valid item is selected
    }

    int row = item->row();
    QVariant data = ui->tab_moyen_modif_2->item(row, 0)->data(Qt::DisplayRole);
    QString id = data.toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM MOYEN WHERE ID=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString nom = query.value("NOM").toString();
        QString description = query.value("DESCRIPTION").toString();
        int qte = query.value("QTE").toInt();
        int prix = query.value("PRIX_UNIT").toInt();

        ui->moyen_supp->setText(id);
        ui->nom_moyen_modif->setText(nom);
        ui->description_moyen_modif->setText(description);
        ui->qte_moyen_modif->setText(QString::number(qte));
        ui->prix_moyen_modif->setText(QString::number(prix));

        // Call a function related to the modification (uncomment if needed)
        // on_modif_moyen_clicked();
    } else {
        qDebug() << "No records found for ID:" << id;
    }

}

void MainWindow::on_tab_moyen_2_itemClicked(QTableWidgetItem *item)
{
    if (item == nullptr) {
        return; // Exit if no valid item is selected
    }

    int row = item->row();
    QVariant data = ui->tab_moyen_2->item(row, 0)->data(Qt::DisplayRole);
    QString id = data.toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM MOYEN WHERE ID=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString nom = query.value("NOM").toString();
        QString description = query.value("DESCRIPTION").toString();
        int qte = query.value("QTE").toInt();
        int prix = query.value("PRIX_UNIT").toInt();

        ui->moyen_supp->setText(id);
        ui->nom_moyen_modif->setText(nom);
        ui->description_moyen_modif->setText(description);
        ui->qte_moyen_modif->setText(QString::number(qte));
        ui->prix_moyen_modif->setText(QString::number(prix));

        // Call a function related to the modification (uncomment if needed)
        // on_modif_moyen_clicked();
    } else {
        qDebug() << "No records found for ID:" << id;
    }
}

