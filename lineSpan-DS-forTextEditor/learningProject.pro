#-------------------------------------------------
#
# Project created by QtCreator 2015-08-08T04:25:35
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = learningProject
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    ../TextEditor/buffer.cpp \
    ../TextEditor/SimpleTextEditor.cpp
QMAKE_CXXFLAGS += -std=c++0x

HEADERS += \
    ../TextEditor/buffer.h \
    ../TextEditor/bufferpriv.h
