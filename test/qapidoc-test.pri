include($$PWD/../qapidoc.pri)

#INCLUDEPATH+=$$PWD

CONFIG += console
CONFIG -= debug_and_release
CONFIG += testcase
LIBS += -L/usr/local/lib -lgmock
LIBS += -L/usr/local/lib -lgtest

Q_APIDOC_TEST=true
QMAKE_CXXFLAGS += -DQ_APIDOC_TEST=\\\"$$Q_APIDOC_TEST\\\"

HEADERS += \
    $$PWD/qapidoc_test.h \
    $$PWD/qapidoc-test.pri \
    $$PWD/qapidoc_test_unit.h

SOURCES += \
    $$PWD/qapidoc_unit_test_object.cpp




