QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += C:/Users/amans/opencv/opencv/build/include/

CONFIG -= debug_and_release debug_and_release_target
CONFIG(debug, debug|release) {
    LIBS += -LC:/Users/amans/opencv/opencv/build/x64/vc14/lib \
            -lopencv_world340d

} else {
    LIBS += -LC:/Users/amans/opencv/opencv/build/x64/vc14/lib \
            -lopencv_world340
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
