#include "menu.h"
#include "home.h"
#include "ui_menu.h"
#include "ui_home.h"
#include "ui_mdp.h"
#include "mdp.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_gestion_employes_clicked()
{
    Ui_home h;
    mdp m;
    home ho;
   // m.exec();
    hide();
    ho.exec();
    h.main_page->setCurrentIndex(1);

}

void menu::on_gestion_locaux_clicked()
{
    Ui_home h;
    mdp m;
    home ho;
    //m.exec();
    hide();
    ho.exec();
    h.main_page->setCurrentIndex(1);
}
