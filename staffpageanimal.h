#ifndef STAFFPAGEANIMAL_H
#define STAFFPAGEANIMAL_H

#include <QMainWindow>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <animalpage.h>
#include <addanimalpage.h>
#include <mainwindow.h>

namespace Ui {
class staffpageanimal;
}

class staffpageanimal : public QDialog
{
    Q_OBJECT

public:
    explicit staffpageanimal(QWidget *parent = 0);
    ~staffpageanimal();

private slots:
    void on_viewAnimals_clicked();

    void on_backButton_1_clicked();

    void on_addNewAnimal_clicked();
    
private:
    Ui::staffpageanimal *ui;
};

#endif // STAFFPAGEANIMAL_H
