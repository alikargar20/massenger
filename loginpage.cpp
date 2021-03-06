#include "loginpage.h"
#include "ui_loginpage.h"
#include "main_b.h"
#include"register.h"

LoginPage::LoginPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginPage)
{
    url=new SetQuery();
    setGeometry(300,40,795,715);
    this->setFixedSize(795,715);
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(:13.jpeg);");
    log = new QNetworkAccessManager(this);
    connect(ui -> login , &QPushButton::clicked , this , &LoginPage :: login );
    connect(log,&QNetworkAccessManager::finished,this,&LoginPage::replyLog);
    /////////////auto login
   QFile file("/home/siavash/git messanger/messenger_L/save.txt");
       if(!file.open(QFile::ReadOnly |
                     QFile::Text))
       {
           qDebug() << " Could not open the file for reading";
           return;
       }

       QTextStream in(&file);
       QString user = in.readLine();
       QString pass = in.readLine();
       QString token = in.readLine();
       qDebug() << user<<endl<<pass<<token<<endl;


       if(user == "00"){
           ui->textEdit->setText("Enter user & pass");
       }

      else{

           Main_b *w = new Main_b(token , user , pass ,this);
           w->show();
           setCentralWidget(w);
           w->setGeometry(300,0,802,606);
           this->hide();
 }
       file.close();

    //////////////////////
    //ui->image->setBackgroundRole();
    //ui->image->setPixmap(QPixmap(":/model/image/ggg_3.png"));
    //ui->image->setAutoFillBackground(false);

}

void LoginPage::replyLog(QNetworkReply * reply){

    ui->progressBar->setValue(70);
    ui->progressBar->setValue(100);
    QString rep_str = reply->readAll();
    QJsonDocument jdoc=QJsonDocument::fromJson(rep_str.toUtf8());
    QJsonObject rep_obj=jdoc.object();
    token=rep_obj["token"].toString();
    ui->textEdit->setText(rep_obj["message"].toString());

    //save user & pass to login
    QString filename="/home/siavash/git messanger/messenger_L/save.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << user << endl;
        stream << pass << endl;
        stream << token << endl;
    }
    ////////////
    //qDebug()<<rep_obj["code"].toString();
    if(rep_obj["code"].toString() == "200" ){
        Main_b *w = new Main_b(token , user , pass ,this);
        w->show();
        setCentralWidget(w);
        w->setGeometry(300,0,802,606);
        this->hide();




    }



}




void LoginPage::login(){

    user = ui -> user ->text();
    pass = ui -> pass ->text();
    req.setUrl(url->setLoginQuery(user,pass));
    log->get(req);
    ui->progressBar->setValue(20);
    ui->progressBar->setValue(50);

}

LoginPage::~LoginPage()
{
    delete ui;
}


void LoginPage::on_signup_clicked()
{
    regist = new Register(this);
    regist -> show();
    regist->setGeometry(500,140,750,560);
  //  regist->setFixedSize(750,560);
}
