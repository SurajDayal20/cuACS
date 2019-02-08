#include "staffpageanimal.h"
#include "ui_staffpageanimal.h"

staffpageanimal::staffpageanimal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staffpageanimal)
{
    ui->setupUi(this);
}

staffpageanimal::~staffpageanimal()
{
    delete ui;
}

void staffpageanimal::on_viewAnimals_clicked()
{
    this->hide();
    animalpage animalpage;
    animalpage.setModal(true);
    animalpage.exec();
}

void staffpageanimal::on_backButton_1_clicked()
{
    this->hide();
    staffpage staffpage;
    staffpage.setModal(true);
    staffpage.exec();
}

void staffpageanimal::on_addNewAnimal_clicked()
{
    this->hide();
    addanimalpage addanimalpage;
    addanimalpage.setModal(true);
    addanimalpage.exec();
}

