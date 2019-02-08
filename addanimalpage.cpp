#include "addanimalpage.h"
#include "ui_addanimalpage.h"
#include <QDebug>

addanimalpage::addanimalpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addanimalpage)
{
    ui->setupUi(this);
}

addanimalpage::~addanimalpage()
{
    delete ui;
    delete queryModel;
    delete comm;
}

void addanimalpage::on_buttonBox_accepted()
{
    QString name, type, breed, gender = "", personality = "", diet = "", environment = "", appetite = "";
    qint8 age, lifespan, noise = 0, intelligence = 0, adaptability = 0, pastOwners, reproductability = 0, energyLevel = 0, weight, height, timeDedication, costDedication;
    bool medication = false;

    name = ui->lineName->text();
    type = ui->lineType->text();
    breed = ui->lineBreed->text();
    age = ui->lineAge->text().toInt();
    lifespan = ui->lineLifespan->text().toInt();
    pastOwners = ui->lineOwners->text().toInt();
    timeDedication = ui->lineTime->text().toInt();
    costDedication = ui->lineCost->text().toInt();
    weight = ui->lineWeight->text().toInt();
    height = ui->lineHeight->text().toInt();

    QButtonGroup coll;
    QList<QRadioButton *> buttonColl = ui->Medication->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }
    if (coll.checkedId() == 0){
        medication = true;
    }
    if (coll.checkedId() == 1){
        medication = false;
    }

    buttonColl = ui->Energy->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }
    energyLevel = coll.checkedId()+1;

    buttonColl = ui->Appetite->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }
    if (coll.checkedId() == 0){
        appetite = "High";
    }
    if (coll.checkedId() == 1){
        appetite = "Medium";
    }
    if (coll.checkedId() == 2){
        appetite = "Low";
    }

    buttonColl = ui->Reproductability->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }

    reproductability = coll.checkedId()+1;

    buttonColl = ui->Environment->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }
    if (coll.checkedId() == 0){
        environment = "Indoor";
    }
    if (coll.checkedId() == 1){
        environment = "Outdoor";
    }
    if (coll.checkedId() == 2){
        environment = "Both";
    }

    buttonColl = ui->Diet->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }
    if (coll.checkedId() == 0){
        diet = "Herbivore";
    }
    if (coll.checkedId() == 1){
        diet = "Carnivore";
    }
    if (coll.checkedId() == 2){
        diet = "Omnivore";
    }

    buttonColl = ui->Personality->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }
    if (coll.checkedId() == 0){
        personality = "Introvert";
    }
    if (coll.checkedId() == 1){
        personality = "Extrovert";
    }
    if (coll.checkedId() == 2){
        personality = "Ambivert";
    }

    buttonColl = ui->Adapt->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }

    adaptability = coll.checkedId()+1;

    buttonColl = ui->Noise->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }

    noise = coll.checkedId()+1;

    buttonColl = ui->Intelligence->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }

    intelligence = coll.checkedId()+1;

    buttonColl = ui->Gender->findChildren<QRadioButton *>();

    for(int j = 0; j < buttonColl.size(); j++){
        coll.addButton(buttonColl[j],j);
    }
    if (coll.checkedId() == 0){
        gender = "Male";
    }
    if (coll.checkedId() == 1){
        gender = "Female";
    }
    if (coll.checkedId() == 1){
        gender = "Other";
    }

    QSqlQuery task;

    task.prepare("insert or replace into animals(name, type, breed, gender, age, lifespan, noise, intelligence, adaptability, personality, diet, environment, pastOwners, timeDedication, costDedication, medication, reproductability, appetite, energyLevel, weight, height)"
            "values (:name, :type, :breed, :gender, :age, :lifespan, :noise, :intelligence, :adaptability, :personality, :diet, :environment, :pastOwners, :timeDedication, :costDedication, :medication, :reproductability, :appetite, :energyLevel, :weight, :height)");
    task.bindValue(":name", name);
    task.bindValue(":type", type);
    task.bindValue(":breed", breed);
    task.bindValue(":gender", gender);
    task.bindValue(":age", age);
    task.bindValue(":lifespan", lifespan);
    task.bindValue(":noise", noise);
    task.bindValue(":intelligence", intelligence);
    task.bindValue(":adaptability", adaptability);
    task.bindValue(":personality", personality);
    task.bindValue(":diet", diet);
    task.bindValue(":environment", environment);
    task.bindValue(":pastOwners", pastOwners);
    task.bindValue(":timeDedication", timeDedication);
    task.bindValue(":costDedication", costDedication);
    task.bindValue(":medication", medication);
    task.bindValue(":reproductability", reproductability);
    task.bindValue(":appetite", appetite);
    task.bindValue(":energyLevel", energyLevel);
    task.bindValue(":weight", weight);
    task.bindValue(":height", height);
    task.exec();

    this->hide();
    staffpageanimal staffpageanimal;
    staffpageanimal.setModal(true);
    staffpageanimal.exec();
}

void addanimalpage::on_buttonBox_rejected()
{
    this->hide();
    staffpageanimal staffpageanimal;
    staffpageanimal.setModal(true);
    staffpageanimal.exec();
}
