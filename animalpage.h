#ifndef ANIMALPAGE_H
#define ANIMALPAGE_H

#include <QDialog>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <mainwindow.h>
#include <staffpageanimal.h>

namespace Ui {
class animalpage;
}

class animalpage : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase userDatabase;
    QSqlQueryModel * queryModel = new QSqlQueryModel();
    QSqlQuery* comm = new QSqlQuery(userDatabase);
    explicit animalpage(QWidget *parent = 0);
    ~animalpage();

private slots:
    void on_loadButton_clicked();

    void on_backButton_2_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_buttonBox_2_rejected();

private:
    Ui::animalpage *ui;
};

#endif // ANIMALPAGE_H
