#ifndef LEAPMOTIONVIDEO_H
#define LEAPMOTIONVIDEO_H

#include <QMainWindow>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QFile>
#include <QTextStream>

#include "Leap.h"
using namespace Leap;

// OpenCV Header
#include <opencv2/opencv.hpp>

namespace Ui {
class LeapMotionVideo;
}

class LeapMotionVideo : public QMainWindow
{
    Q_OBJECT

public:
    explicit LeapMotionVideo(QWidget *parent = 0);
    ~LeapMotionVideo();

private slots:
    void on_pushButton_clicked();
    void getImageData();

    void on_BtnRecord_clicked();

private:
    Ui::LeapMotionVideo *ui;

    QTimer *lpTimer;

    Controller *lpController;
    Frame frame;

    QFile *dataFile;
    QTextStream textStream;

    cv::Mat left;
    cv::Mat right;

    cv::VideoWriter outputVideoLeft;
    cv::VideoWriter outputVideoRight;
    bool isRecording;
};

#endif // LEAPMOTIONVIDEO_H
