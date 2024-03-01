#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_log_clicked();

    void on_gestion_employes_menu_clicked();

    void on_home_clicked();

    void on_ajout_2_clicked();

    void on_modif_2_clicked();

    void on_aff_2_clicked();

    void on_ajout_loc_2_clicked();

    void on_modif_loc_2_clicked();

    void on_aff_loc_2_clicked();

    void on_gestion_locaux_menu_clicked();

    void on_gest_emp_2_clicked();

    void on_gest_loc_2_clicked();

    void on_gestion_sponsor_menu_clicked();

    void on_gestion_client_menu_clicked();

    void on_aff_cl_clicked();

    void on_ajout_cl_clicked();

    void on_modif_cl_clicked();

    void on_gest_client_2_clicked();

    void on_gest_sponsors_2_clicked();

    void on_aff_moyen_clicked();

    void on_ajout_moyen_clicked();

    void on_modif_moyen_clicked();

    void on_aff_sponsor_clicked();

    void on_ajout_sponsor_clicked();

    void on_modif_sponsor_clicked();

    void on_gestion_evenements_menu_clicked();

    void on_aff_participant_clicked();

    void on_ajout_participant_clicked();

    void on_modif_participant_clicked();

    void on_gest_event_2_clicked();

    void on_logout_clicked();

    void on_logout_2_clicked();

    void on_aff_act_clicked();

    void on_ajout_act_clicked();

    void on_modif_act_clicked();

    void on_gestion_activites_menu_clicked();

    void on_gest_act_2_clicked();

    void on_ajouter_employes_clicked();

    void on_supprimer_emp_clicked();

    void on_ajout_client_clicked();

    void on_tab_employe_modif_2_itemClicked(QTableWidgetItem *item);

    void on_modifier_emp_clicked();


    void on_recherche_emp_textChanged(const QString &arg1);


    void on_tri_emp_activated(const QString &arg1);

    void on_supp_client_clicked();

    void on_lineEdit_59_textChanged(const QString &arg1);

    void on_tab_client_itemClicked(QTableWidgetItem *item);

    void on_modif_cli_clicked();

    void on_tri_client_activated(const QString &arg1);

    void on_ajouter_loc_clicked();

    void on_tab_loc_modif_2_itemClicked(QTableWidgetItem *item);

    void on_tab_loc_2_itemClicked(QTableWidgetItem *item);

    void on_modif_loc_clicked();

    void on_pushButton_15_clicked();

    void on_ajout_event_2_clicked();

    void on_aff_event_clicked();

    void on_ajout_event_clicked();

    void on_modif_event_clicked();

    void on_event_supprimer_clicked();

    void on_tab_event_modif_2_itemClicked(QTableWidgetItem *item);

    void on_tab_event_2_itemClicked(QTableWidgetItem *item);

    void on_tab_activite_modif_2_itemClicked(QTableWidgetItem *item);

    void on_ajouter_act_clicked();

    void on_supp_act_clicked();

    void on_modifier_act_clicked();

    void on_tab_activite_2_itemClicked(QTableWidgetItem *item);

    void on_ajouter_moyen_clicked();

    void on_supprimer_moyen_clicked();

    void on_modifier_moyen_clicked();

    void on_tab_moyen_modif_2_itemClicked(QTableWidgetItem *item);

    void on_tab_moyen_2_itemClicked(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
