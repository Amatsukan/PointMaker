TARGET = Mark
CONFIG += qt debug widget c++14
SOURCES += main.cpp pointer.cpp
HEADERS += window.h pointer.h
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

!exists( main.cpp ) {
    error( "No cpp file found" )
}
win32:debug {
    CONFIG += console
}