include($$PWD/../qapidoc.pri)

QT += core
QT += network
QT += websockets

Q_APIDOC_TEST=true
QMAKE_CXXFLAGS += -DQ_APIDOC_TEST=\\\"$$Q_APIDOC_TEST\\\"

HEADERS += \
    $$PWD/qapidoc_object_test.h \
    $$PWD/qapidoc_test.h \
    $$PWD/qapidoc-test.pri \
    $$PWD/qapidoc_test_unit.h

SOURCES += \
    $$PWD/qapidoc_unit_test_object.cpp




