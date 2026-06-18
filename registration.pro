QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    datamanager.cpp \
    dialog.cpp \
    doctor.cpp \
    form.cpp \
    main.cpp \
    login.cpp \
    nurse.cpp \
    patient.cpp \
    zdialog.cpp

HEADERS += \
    admin.h \
    datamanager.h \
    dialog.h \
    doctor.h \
    form.h \
    login.h \
    nurse.h \
    patient.h \
    zdialog.h

FORMS += \
    admin.ui \
    dialog.ui \
    doctor.ui \
    form.ui \
    login.ui \
    nurse.ui \
    patient.ui \
    zdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
