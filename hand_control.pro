TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += C:/openCV/include
LIBS += -L"C:/openCV/mingw/bin"
LIBS += -lopencv_core2410 -lopencv_highgui2410 -lopencv_imgproc2410 -lopencv_video2410
include(deployment.pri)
qtcAddDeployment()

