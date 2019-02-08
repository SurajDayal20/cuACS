#include "staffpageclient.h"
#include "ui_staffpageclient.h"

staffpageclient::staffpageclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staffpageclient)
{
    ui->setupUi(this);
}

staffpageclient::~staffpageclient()
{
    delete ui;
}

void staffpageclient::on_backButton_1_clicked()
{
    this->hide();
    staffpage staffpage;
    staffpage.setModal(true);
    staffpage.exec();
}
