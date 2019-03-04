QT += core gui widgets

TARGET = Editor
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        MainWindow.cpp \
        QCanvas.cpp

HEADERS += \
        MainWindow.hpp \
        QCanvas.hpp

FORMS += \
        MainWindow.ui

INCLUDEPATH += \
	../include

win32: {

	CONFIG += \
		c++11

	CONFIG(debug, debug|release): LIBS += \
		-L../../lib/ -lImageLibd

	CONFIG(release, debug|release): LIBS += \
		-L../../lib/ -lImageLib

}

linux: {

	LIBS += \
		-L../../lib/ -lImageLib

}

clang {

    CONFIG += \
		c++11

}

gcc:!clang {

    CONFIG += \
		c++11

}
