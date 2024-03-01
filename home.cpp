#include "home.h"
#include "menu.h"
#include "connection.h"
#include "ui_home.h"
#include "employe.h"

employe e;
Connection c;

home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    ui->menuhome->setCurrentIndex(1);
//    ui->gest_emp->setCheckable(true);
//    ui->gest_emp->setChecked(true);

    if(c.createconnect()){
//        e.afficher_employe(ui);
//        e.afficher_employe2(ui);
    }
}

home::~home()
{
    delete ui;
}


void home::on_modif_clicked()
{
    ui->main_emp->setCurrentIndex(0);
    ui->ajoutmodif->setCurrentIndex(0);
}

void home::on_ajout_clicked()
{
    ui->main_emp->setCurrentIndex(0);
    ui->ajoutmodif->setCurrentIndex(1);
}

void home::on_aff_clicked()
{
    ui->main_emp->setCurrentIndex(1);

}

void home::on_home_2_clicked()
{
    ui->menuhome->setCurrentIndex(1);
}

void home::on_gestion_employes_clicked()
{
     ui->menuhome->setCurrentIndex(0);
     ui->main_page->setCurrentIndex(1);

}

void home::on_gestion_locaux_clicked()
{
    ui->menuhome->setCurrentIndex(0);
    ui->main_page->setCurrentIndex(0);
    ui->main_loc->setCurrentIndex(1);


}

void home::on_ajout_loc_clicked()
{
    ui->main_loc->setCurrentIndex(0);
    ui->ajoutmodif_loc->setCurrentIndex(1);
}

void home::on_modif_loc_clicked()
{
    ui->main_loc->setCurrentIndex(0);
    ui->ajoutmodif_loc->setCurrentIndex(0);
}

void home::on_aff_loc_clicked()
{
    ui->main_loc->setCurrentIndex(1);
}

void home::on_gest_emp_clicked()
{
    on_gestion_employes_clicked();
}

void home::on_gest_loc_clicked()
{
    on_gestion_locaux_clicked();
}
