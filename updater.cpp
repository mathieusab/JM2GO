#include "updater.h"
#include "constants.h"
#include <QtNetwork>

Updater::Updater(MainWindow *parent)
{
    qDebug() << "Updater::Updater";
    a__parent = parent;

//    a__api_caller = new API_caller(this, a__parent);
//    a__api_caller->start();z
}

void Updater::run()
{
    qDebug() << "Updater::run";
    int cpt = 0;

    while(1)
    {
        QThread::msleep(500);

        emit sig_blink();

        qDebug() << cpt;
        if(cpt >= 10) //toutes les 5s (10 * 500ms)
        {
            emit sig_query();
            cpt = 0;
        }
        cpt++;
    }
}


