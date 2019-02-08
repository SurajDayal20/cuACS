#ifndef ADDANIMALPAGE_H
#define ADDANIMALPAGE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <staffpageanimal.h>

namespace Ui {
class addanimalpage;
}

class addanimalpage : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase userDatabase;
    QSqlQueryModel * queryModel = new QSqlQueryModel();
    QSqlQuery* comm = new QSqlQuery(userDatabase);
    explicit addanimalpage(QWidget *parent = 0);
    ~addanimalpage();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::addanimalpage *ui;
};

#endif // ADDANIMALPAGE_H
