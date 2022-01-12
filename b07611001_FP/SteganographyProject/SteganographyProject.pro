QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


#CONFIG(debug, debug|release) {
#QMAKE_CXXFLAGS_DEBUG += /MTd

#}

#CONFIG(release, debug|release) {
#    QMAKE_CXXFLAGS_RELEASE += /MT
#}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cvimage.cpp \
    main.cpp \
    steganographyproject.cpp \
    text.cpp

HEADERS += \
    cvimage.h \
    steganographyproject.h \
    text.h

FORMS += \
    steganographyproject.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32{
    CONFIG(release, debug|release): {
#        QMAKE_CXXFLAGS_RELEASE += /MT
        LIBS += -LD:/opencv3411/build/x64/vc15/lib/ -lopencv_world3411
    } else {
#        QMAKE_CXXFLAGS_DEBUG += /MTd
        LIBS += -LD:/opencv3411/build/x64/vc15/lib/ -lopencv_world3411d
    }
}
INCLUDEPATH += D:/opencv3411/build/include
DEPENDPATH += D:/opencv3411/build/include

win32 {
    CONFIG(release, debug|release) {
#        QMAKE_CXXFLAGS_RELEASE += /MT
#        LIBS += -LD:/cryptopp860/x64/DLL_Output/Debug -lcryptopp
        LIBS += -LD:/cryptopp860/x64/Output/Debug -lcryptlib
    } else {
#        QMAKE_CXXFLAGS_DEBUG += /MTd
#        LIBS += -LD:/cryptopp860/x64/DLL_Output/Debug -lcryptopp
        LIBS += -LD:/cryptopp860/x64/Output/Debug -lcryptlib
    }
}

INCLUDEPATH += D:/cryptopp860/lib
DEPENDPATH += D:/cryptopp860/lib

RC_ICONS = Icon.png

