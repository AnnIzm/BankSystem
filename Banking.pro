QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    credit.cpp \
    creditform.cpp \
    creditthread.cpp \
    deposit.cpp \
    depositform.cpp \
    depositthread.cpp \
    main.cpp \
    authorisewindow.cpp \
    menuwindow.cpp

HEADERS += \
    account.h \
    authorisewindow.h \
    credit.h \
    creditform.h \
    creditthread.h \
    deposit.h \
    depositform.h \
    depositthread.h \
    file.h \
    menuwindow.h

FORMS += \
    authorisewindow.ui \
    creditform.ui \
    depositform.ui \
    menuwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
