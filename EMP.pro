QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/addemp.cpp \
    sources/database.cpp \
    sources/database.cpp \
    sources/delete.cpp \
    sources/exp.cpp \
    sources/experience.cpp \
    main.cpp \
    sources/mainwindow.cpp \
    sources/search.cpp \
    sources/searchdetails.cpp \
    sources/showexp.cpp \
    sources/update.cpp

HEADERS += \
    headers/addemp.h \
    headers/delete.h \
    headers/exp.h \
    headers/experience.h \
    headers/mainwindow.h \
    headers/search.h \
    headers/searchdetails.h \
    headers/showexp.h \
    headers/update.h \
    headers/update.h

FORMS += \
    forms/addemp.ui \
    forms/delete.ui \
    forms/exp.ui \
    forms/experience.ui \
    forms/mainwindow.ui \
    forms/search.ui \
    forms/searchdetails.ui \
    forms/showexp.ui \
    forms/update.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

android:
    {
DISTFILES += \
    android/AndroidManifest.xml \
    android/assets/Employ.db \
    android/assets/db/Employ.db \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/libs/jcifs-1.3.19.jar \
    android/res/values/libs.xml \
    assets/db/Employ.db \
    assets/db/Employ.sqbpro
android: include(C:/Users/pc/AppData/Local/Android/Sdk/android_openssl/openssl.pri)
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

   android
{
my_files.path = /assets
my_files.files = $$PWD/android/*
INSTALLS += my_files
}

}

!android:
   {
       # copie la base de données dans le dossier build
       CONFIG += file_copies
       COPIES += bd
       bd.files = Employ.db
       bd.path = $$OUT_PWD/
       bd.base = $$PWD/
   }
