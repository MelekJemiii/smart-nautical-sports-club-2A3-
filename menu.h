#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_gestion_employes_clicked();

    void on_gestion_locaux_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
