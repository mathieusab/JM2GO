#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qfile.h>
#include <QDomDocument>
#include "logo.h"
#include "bottom.h"
#include "updater.h"
#include <QNetworkAccessManager>

class Updater;
class API_caller;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void refreshValues(QString V1, QString V2, QString G1, QString G2);
    void queryAPI(QString query);
    void parseRegex();
private slots:
    void managerFinished(QNetworkReply *reply);
    void slot_query();
    void slot_blink();

private:
    Ui::MainWindow *ui;

    Logo *a__Logo;
    Bottom *a__bottom;
    Updater *a__updater;

    bool a__blink = false;

    QNetworkAccessManager *manager;
    QNetworkRequest request;

    QDomDocument *a__Doc;
    QFile *a__File;
    QDomElement e__Root;
    QByteArray a__answer;

    QList<bool> arretList;
};

#endif // MAINWINDOW_H
