#ifndef STAFFPAGE_H
#define STAFFPAGE_H

#include <staffpageanimal.h>
#include <staffpageclient.h>
#include <QDialog>

namespace Ui {
class staffpage;
}

class staffpage : public QDialog
{
    Q_OBJECT

public:
    explicit staffpage(QWidget *parent = 0);
    ~staffpage();

private slots:
    void on_animals_clicked();

    void on_client_clicked();

    void on_back_clicked();

private:
    Ui::staffpage *ui;
};

#endif // STAFFPAGE_H
