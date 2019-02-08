#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase userDatabase = QSqlDatabase::addDatabase("QSQLITE");
    userDatabase.setDatabaseName("animalDatabase.db");

    if (!userDatabase.open())
        ui->label->setText("Could not open database.");
    else
        ui->label->setText("Connected...");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString user = ui->lineEditUsername->text();
    QString pass = ui->lineEditPassword->text();

    QSqlQuery comm;

    if (comm.exec("select * from staff where username='"+user+"' and password = '"+pass+"'")){
        int tally = 0;
        while (comm.next()){
            tally++;
        }
        if (tally == 1){
            ui->label->setText("Username and Password are correct.");
            this->hide();
            staffpage staffpage;
            staffpage.setModal(true);
            staffpage.exec();
        }
        if (tally > 1){
            ui->label->setText("Duplicate Username and Password.");
        }
        if (tally < 1){
            ui->label->setText("Username or Password incorrect.");
        }
   }



}
