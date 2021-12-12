include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH+="../../"
INCLUDEPATH+="../../include/"
INCLUDEPATH+="../../src/"

HEADERS += \
        ../../include/classes.h \
        tst_test1.h

SOURCES += \
        ../../src/classes.cpp \
        main.cpp
