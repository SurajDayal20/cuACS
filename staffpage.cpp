#include "staffpage.h"
#include "ui_staffpage.h"

staffpage::staffpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staffpage)
{
    ui->setupUi(this);
}

staffpage::~staffpage()
{
    delete ui;
}

void staffpage::on_animals_clicked()
{
    this->hide();
    staffpageanimal staffpageanimal;
    staffpageanimal.setModal(true);
    staffpageanimal.exec();
}

void staffpage::on_client_clicked()
{
    this->hide();
    staffpageclient staffpageclient;
    staffpageclient.setModal(true);
    staffpageclient.exec();
}

void staffpage::on_back_clicked()
{
    this->hide();
}
