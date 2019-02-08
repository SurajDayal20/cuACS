#include "animalpage.h"
#include "ui_animalpage.h"

animalpage::animalpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::animalpage)
{
    ui->setupUi(this);
}

animalpage::~animalpage()
{
    delete ui;
    delete queryModel;
    delete comm;
}

void animalpage::on_loadButton_clicked()
{
    //QSqlQueryModel * queryModel = new QSqlQueryModel();

    //QSqlQuery* comm = new QSqlQuery(userDatabase);

    comm->prepare("select * from animals");

    comm->exec();
    queryModel->setQuery(*comm);
    ui->tableView->setModel(queryModel);
}

void animalpage::on_backButton_2_clicked()
{
    this->hide();
    staffpageanimal staffpageanimal;
    staffpageanimal.setModal(true);
    staffpageanimal.exec();
}

void animalpage::on_buttonBox_accepted()
{
    QString id;
    QSqlQuery task;
    id = ui->lineDeleteAnimal->text();
    task.prepare("delete from animals where id='"+id+"'");
    task.exec();
    this->hide();
    staffpageanimal staffpageanimal;
    staffpageanimal.setModal(true);
    staffpageanimal.exec();
}

void animalpage::on_buttonBox_rejected()
{
    this->hide();
    staffpageanimal staffpageanimal;
    staffpageanimal.setModal(true);
    staffpageanimal.exec();
}

void animalpage::on_buttonBox_2_rejected()
{
    this->hide();
    staffpageanimal staffpageanimal;
    staffpageanimal.setModal(true);
    staffpageanimal.exec();
}
