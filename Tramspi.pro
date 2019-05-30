#-------------------------------------------------
#
# Project created by QtCreator 2018-03-18T23:32:52
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tramspi
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#pour openssl : dl le dernier zip https://indy.fulgan.com/SSL/ et copier les .dll dans le dossier debug ou release

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        logo.cpp \
    bottom.cpp \
    updater.cpp

HEADERS += \
        mainwindow.h \
    logo.h \
    bottom.h \
    updater.h \
    constants.h

FORMS += \
        mainwindow.ui \
    logo.ui \
    bottom.ui

DISTFILES +=

RESOURCES += \
    images.qrc
