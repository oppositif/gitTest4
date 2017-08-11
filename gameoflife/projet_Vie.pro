QT       += core gui widgets qml quick

CONFIG += c++11

TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
# CONFIG -= qt


SOURCES += cpp/main.cpp \
    cpp/wmanager.cpp \
    cpp/gamelife.cpp

HEADERS += \
    cpp/wmanager.h \
    cpp/gamelife.h

DISTFILES += \
    qml/ZButton.qml \
    qml/ZButton.qml \
    qml/Case.qml \
    qml/qml2.qml \
    qml/qml.qml \
    qml/LigneCase.qml \
    qml/PlateauVie.qml
