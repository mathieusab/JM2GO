#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include "logo.h"
#include "constants.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    a__Logo = new Logo(this);
    ui->vL_Logo->addWidget(a__Logo);
    a__Logo->show();

    a__bottom = new Bottom(this);
    ui->vL_Bottom->addWidget(a__bottom);
    a__bottom->show();

    QDateTime current = QDateTime::currentDateTime();
    QTime currentTime = current.time();
    QString str = currentTime.toString("HH:mm");

    QStringList heures_minutes = str.split(":");
    QString heures = heures_minutes[0];
    QString minutes = heures_minutes[1];

    ui->lcdHH->display(heures);
    ui->lcdMM->display(minutes);

    arretList << false << false << false << false;

    a__updater = new Updater(this);
    connect(a__updater, SIGNAL(sig_query()), this, SLOT(slot_query()));
    connect(a__updater, SIGNAL(sig_blink()), this, SLOT(slot_blink()));
    a__updater->start();

    queryAPI(TRAM_URL);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshValues(QString V1, QString V2, QString G1, QString G2)
{
    qDebug() << "refreshValues";
    ui->lcdVincennes1->display(V1);
    ui->lcdVincennes2->display(V2);
    ui->lcdGarigliano1->display(G1);
    ui->lcdGarigliano2->display(G2);
}

void MainWindow::queryAPI(QString query)
{
    manager = new QNetworkAccessManager();
    QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(managerFinished(QNetworkReply*)));

    request.setUrl(QUrl(query));

    QSslConfiguration conf = request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(conf);

    manager->get(request);
}

void MainWindow::managerFinished(QNetworkReply *reply)
{
    if (reply->error())
    {
        qDebug() << reply->errorString();
        return;
    }

    a__answer = reply->readAll();

    qDebug() << a__answer;

    reply->deleteLater();
    parseRegex();
}

void MainWindow::slot_query()
{
    queryAPI(TRAM_URL);
}

void MainWindow::slot_blink()
{
    a__blink = !a__blink;

    QPalette orange;
    QPalette black;

    QColor redColor(Qt::black);
    QColor orangeColor(255,170,0);

    black.setColor(QPalette::WindowText, redColor);
    orange.setColor(QPalette::WindowText, orangeColor);

    ui->lcdVincennes1->setPalette(orange);
    ui->lcdVincennes2->setPalette(orange);
    ui->lcdGarigliano1->setPalette(orange);
    ui->lcdGarigliano2->setPalette(orange);

    if (false)
    {
        if (arretList.at(0) == true)
        {
            ui->lcdVincennes1->setPalette(black);
        }
        if (arretList.at(1) == true)
        {
            ui->lcdVincennes2->setPalette(black);
        }
        if (arretList.at(2) == true)
        {
            ui->lcdGarigliano1->setPalette(black);
        }
        if (arretList.at(3) == true)
        {
            ui->lcdGarigliano2->setPalette(black);
        }
    }
}

void MainWindow::parseRegex()
{
    QString tabTemps[4] = {"99","99","99","99"};

    QDomNodeList entries;
    QDomNodeList sub_entries;
    QString entryString;

    arretList.clear();
    arretList << false << false << false << false;

    a__Doc = new QDomDocument();

    a__Doc->setContent(a__answer);
    entries = a__Doc->elementsByTagName("entry");

    for (int entryIndex = 0; entryIndex < entries.count(); entryIndex++)
    {
        sub_entries = entries.at(entryIndex).childNodes();
        entryString = sub_entries.at(0).toElement().text();

        if (entryString.contains("A l'arret"))
        {
            entryString = "0";
            arretList.replace(entryIndex, true);
        }
        else if (entryString.contains("A l'approche"))
        {
            entryString = "0";
            arretList.replace(entryIndex, false);
        }
        else
        {
            entryString = entryString.split(" mn").at(0);
            arretList.replace(entryIndex, false);
        }

        tabTemps[entryIndex] = entryString;
    }

    qDebug() << "0 =" << tabTemps[0];
    qDebug() << "1 =" << tabTemps[1];
    qDebug() << "2 =" << tabTemps[2];
    qDebug() << "3 =" << tabTemps[3];


    refreshValues(tabTemps[0],tabTemps[1],tabTemps[2],tabTemps[3]);
}
