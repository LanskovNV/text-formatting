TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ./src/main.cpp \
    ./src/text_al.cpp

HEADERS += \
    ./src/text_al.h

DISTFILES += \
    ./src/input.txt \
    ./src/output.txt
