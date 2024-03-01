#ifndef MDP_H
#define MDP_H

#include <QDialog>
#include <QString>


namespace Ui {
class mdp;
}

class mdp : public QDialog
{
    Q_OBJECT

public:
    explicit mdp(QWidget *parent = nullptr);
    ~mdp();
    int verif_mdp(QString role);


private:
    Ui::mdp *ui;
};

#endif // MDP_H
