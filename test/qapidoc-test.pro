TARGET = QApiDoc
TEMPLATE = app

CONFIG += console
CONFIG -= debug_and_release
CONFIG += testcase
LIBS += -L/usr/local/lib -lgmock
LIBS += -L/usr/local/lib -lgtest

include($$PWD/qapidoc-test.pri)
