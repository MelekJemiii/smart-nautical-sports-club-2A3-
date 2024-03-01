#ifndef HOME_H
#define HOME_H

#include <QDialog>

namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();


private slots:
    void on_modif_clicked();

    void on_ajout_clicked();

    void on_aff_clicked();



    void on_home_2_clicked();

    void on_gestion_employes_clicked();

    void on_gestion_locaux_clicked();

    void on_ajout_loc_clicked();

    void on_modif_loc_clicked();

    void on_aff_loc_clicked();

    void on_gest_emp_clicked();

    void on_gest_loc_clicked();

private:
    Ui::home *ui;
};

#endif // HOME_H
