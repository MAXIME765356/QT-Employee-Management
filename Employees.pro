QT       += core sql gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


DISTFILES += \
    Corporate Management.png \
    EmployeeModule.pro.user \
    Employees.pro.user \
    cal.png \
    company_card.png \
    database.db \
    database.sqbpro \
    deployment.pri \
    icons8_Add_User_Male_50px.png \
    icons8_Find_User_Male_50px.png \
    icons8_Money_50px_1.png \
    icons8_Registration_50px.png \
    icons8_Remove_User_Male_50px.png \
    icons8_Request_Money_50px.png \
    id_card.png \
    mainmenu.jpg \
    personal_card.png \
    top_bar.png \
    top_left.png

RESOURCES += \
    images.qrc

FORMS += \
    delete.ui \
    employeeinfo.ui \
    mainwindow.ui \
    secdialog.ui \
    update.ui

HEADERS += \
    delete.h \
    employeeinfo.h \
    mainwindow.h \
    secdialog.h \
    update.h

SOURCES += \
    delete.cpp \
    employeedbutils.cpp \
    employeeinfo.cpp \
    main.cpp \
    mainwindow.cpp \
    secdialog.cpp \
    update.cpp
