#-------------------------------------------------
#
# Project created by QtCreator 2017-08-27T17:23:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LeapMotionVideo
TEMPLATE = app


SOURCES += main.cpp \
        leapmotionvideo.cpp

HEADERS  += leapmotionvideo.h

FORMS    += leapmotionvideo.ui

win32: LIBS += -LC:\LeapSDK\lib\x86\ -lLeap
INCLUDEPATH += C:\LeapSDK\include \
            C:\opencv\build\include
DEPENDPATH += C:\LeapSDK\include
CONFIG(release,debug|release){
    LIBS += C:\opencv\build\x86\vc12\lib\opencv_calib3d2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_contrib2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_core2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_features2d2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_flann2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_gpu2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_highgui2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_imgproc2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_legacy2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_ml2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_nonfree2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_objdetect2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_photo2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_stitching2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_video2410.lib \
            C:\opencv\build\x86\vc10\lib\opencv_videostab2410.lib \
}
CONFIG(debug,debug|release){
    LIBS += C:\opencv\build\x86\vc10\lib\opencv_calib3d2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_contrib2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_core2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_features2d2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_flann2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_gpu2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_highgui2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_imgproc2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_legacy2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_ml2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_nonfree2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_objdetect2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_photo2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_stitching2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_ts2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_video2410d.lib \
            C:\opencv\build\x86\vc10\lib\opencv_videostab2410d.lib \
}
