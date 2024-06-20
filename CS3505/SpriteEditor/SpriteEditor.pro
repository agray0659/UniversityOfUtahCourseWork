QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    frame.cpp \
    json_parser.cpp \
    main.cpp \
    main_window.cpp \
    pixel.cpp \
    pixel_editor.cpp \
    preview_displayer.cpp \
    sprite.cpp \
    sprite_editor_model.cpp \
    spritepreview.cpp

HEADERS += \
    frame.h \
    json_parser.h \
    main_window.h \
    pixel.h \
    pixel_editor.h \
    preview_displayer.h \
    sprite.h \
    sprite_editor_model.h \
    spritepreview.h

FORMS += \
    main_window.ui \
    spritepreview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
