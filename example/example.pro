QT -= gui

CONFIG += c++17
CONFIG += console
CONFIG += silent
CONFIG -= debug_and_release
CONFIG -= app_bundle

TEMPLATE = app
TARGET = demo

include($$PWD/../qapidoc.pri)


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    $$PWD/example_object.h

SOURCES += \
    $$PWD/example_object.cpp \
    $$PWD/main.cpp
