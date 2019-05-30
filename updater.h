#ifndef UPDATER_H
#define UPDATER_H

#include "mainwindow.h"
#include <QThread>
#include <qdebug.h>
#include <qnetworkaccessmanager.h>
#include <QtNetwork>

class MainWindow;

class Updater : public QThread
{
    Q_OBJECT
public:
    Updater(MainWindow *parent = 0);

    void run();


signals:
    void sig_query();
    void sig_blink();


private:
    MainWindow *a__parent;

};

#endif // UPDATER_H
