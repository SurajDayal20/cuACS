#ifndef STAFFPAGECLIENT_H
#define STAFFPAGECLIENT_H

#include <QDialog>
#include <staffpage.h>

namespace Ui {
class staffpageclient;
}

class staffpageclient : public QDialog
{
    Q_OBJECT

public:
    explicit staffpageclient(QWidget *parent = 0);
    ~staffpageclient();

private slots:
    void on_backButton_1_clicked();

private:
    Ui::staffpageclient *ui;
};

#endif // STAFFPAGECLIENT_H
