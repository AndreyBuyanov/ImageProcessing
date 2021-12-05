QT += core gui widgets

TARGET = Editor
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        MainWindow.cpp \
        QCanvas.cpp \
    Filters/filterConvultion.cpp \
    Filters/filterGamma.cpp \
    Filters/filterGrayscale.cpp \
    Filters/filterInvert.cpp \
    Filters/filterMedian.cpp \
    Filters/filterSobel.cpp

HEADERS += \
        MainWindow.hpp \
        QCanvas.hpp \
    Filters/filterConvultion.hpp \
    Filters/filterGamma.hpp \
    Filters/filterGrayscale.hpp \
    Filters/filterInvert.hpp \
    Filters/filterMedian.hpp \
    Filters/filterSobel.hpp

FORMS += \
        MainWindow.ui \
    Filters/filterConvultion.ui \
    Filters/filterGamma.ui \
    Filters/filterGrayscale.ui \
    Filters/filterInvert.ui \
    Filters/filterMedian.ui \
    Filters/filterSobel.ui

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
