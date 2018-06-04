#ifndef MAIN_B_H
#define MAIN_B_H

#include "loginpage.h"
#include <QMainWindow>

namespace Ui {
class Main_b;
}

class Main_b : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_b(QString token,QWidget *parent = 0);
    ~Main_b();





protected:
    Ui::Main_b *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest  req;
    QString token;
private slots:


    void on_searchBut_clicked();
};

#endif // MAIN_B_H
