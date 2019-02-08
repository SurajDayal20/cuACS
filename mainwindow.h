#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <staffpageanimal.h>
#include <staffpage.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase userDatabase;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
