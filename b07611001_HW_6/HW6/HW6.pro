QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cvimage.cpp \
    main.cpp \
    hw6.cpp

HEADERS += \
    cvimage.h \
    hw6.h

FORMS += \
    hw6.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
win32:CONFIG(release, debug|release): LIBS += -LD:/opencv3411/build/x64/vc15/lib/ -lopencv_world3411
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/opencv3411/build/x64/vc15/lib/ -lopencv_world3411d
INCLUDEPATH += D:/opencv3411/build/include
DEPENDPATH += D:/opencv3411/build/include
