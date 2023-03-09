QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    books.cpp \
    delegat_readers.cpp \
    delegate.cpp \
    given.cpp \
    info_give.cpp \
    main.cpp \
    mainwindow.cpp \
    readers.cpp

HEADERS += \
    books.h \
    delegat_readers.h \
    delegate.h \
    given.h \
    info_give.h \
    mainwindow.h \
    readers.h \
    variables.h

FORMS += \
    books.ui \
    given.ui \
    info_give.ui \
    mainwindow.ui \
    readers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
