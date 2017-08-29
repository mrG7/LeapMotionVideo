/*
 * Record raw IR images captured by Leap Motion
 * Version: 2017-8-29
 * By: Zheyuan Wang @ GT-Bionics Lab
 *
 * Images from both left and right cameras are being recorded
 * 640 x 240 @ 25 PFS
 * 8 bit grayscale
*/

#include "leapmotionvideo.h"
#include "ui_leapmotionvideo.h"

LeapMotionVideo::LeapMotionVideo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LeapMotionVideo)
{
    ui->setupUi(this);

    //ui->sysDisplay->setReadOnly(true);
    ui->BtnRecord->setDisabled(true);

    isRecording = false;

    //Set trial number to 1~1000
    ui->lineEdit->setValidator(new QIntValidator(1, 1000, this));
    ui->lineEdit->setText("1");

    lpTimer = new QTimer();
    connect(lpTimer, SIGNAL(timeout()),this,SLOT(getImageData()));

    /*
        When you first create a Controller object, isConnected() returns false.
        After the controller finishes initializing and connects to the Leap Motion
        software and if the Leap Motion hardware is plugged in, isConnected() returns true.
    */
    lpController = new Controller();

    while (!lpController->isConnected()) {}
    ui->sysInfo->setText("Leap Motion Connected!");
    lpController->setPolicy(Leap::Controller::POLICY_IMAGES);
}

LeapMotionVideo::~LeapMotionVideo()
{
    delete ui;
}

void LeapMotionVideo::on_pushButton_clicked()
{
    if (ui->pushButton->text()==tr("Show")) {
        lpTimer->start(40);
        ui->pushButton->setText("Stop");
        ui->BtnRecord->setEnabled(true);
    } else {
        lpTimer->stop();
        ui->pushButton->setText("Show");
        ui->BtnRecord->setDisabled(true);
    }
}

// Get image data from LeapMotion API for display
void LeapMotionVideo::getImageData()
{
    Frame frame = lpController->frame();

    ImageList images = frame.images();

    //Draw the raw image data as a greyscale bitmap
    if (images.count() >= 2) {
        left = cv::Mat(images[0].height(), images[0].width(), CV_8UC1, (void *)images[0].data());
        right = cv::Mat(images[1].height(), images[1].width(), CV_8UC1, (void *)images[1].data());
    }
    imshow("leftCam", left);
    imshow("rightCam", right);
    //cv::waitKey(1);
    if (isRecording) {
        outputVideoLeft << left;
        outputVideoRight << right;
    }
}

void LeapMotionVideo::on_BtnRecord_clicked()
{
    if (ui->BtnRecord->text()==tr("Record")) {
        //open videowriter
        QDate qdateObj = QDate::currentDate();
        QTime qtimeObj = QTime::currentTime();

        QString timeNow_left = QString("Trial_%1_%2_%3_%4_%5_%6_%7_left.avi")
            .arg(ui->lineEdit->text())
            .arg(qdateObj.year(), 4, 10, QLatin1Char('0'))
            .arg(qdateObj.month(), 2, 10, QLatin1Char('0'))
            .arg(qdateObj.day(), 2, 10, QLatin1Char('0'))
            .arg(qtimeObj.hour(), 2, 10, QLatin1Char('0'))
            .arg(qtimeObj.minute(), 2, 10, QLatin1Char('0'))
            .arg(qtimeObj.second(), 2, 10, QLatin1Char('0'));
        QString timeNow_right = QString("Trial_%1_%2_%3_%4_%5_%6_%7_right.avi")
            .arg(ui->lineEdit->text())
            .arg(qdateObj.year(), 4, 10, QLatin1Char('0'))
            .arg(qdateObj.month(), 2, 10, QLatin1Char('0'))
            .arg(qdateObj.day(), 2, 10, QLatin1Char('0'))
            .arg(qtimeObj.hour(), 2, 10, QLatin1Char('0'))
            .arg(qtimeObj.minute(), 2, 10, QLatin1Char('0'))
            .arg(qtimeObj.second(), 2, 10, QLatin1Char('0'));

        outputVideoLeft.open(timeNow_left.toStdString(), CV_FOURCC('M', 'J', 'P', 'G'), 25, left.size(), false);
        outputVideoRight.open(timeNow_right.toStdString(), CV_FOURCC('M', 'J', 'P', 'G'), 25, right.size(), false);

        isRecording = true;
        ui->BtnRecord->setText("Stop");
        ui->pushButton->setDisabled(true);
    } else {
        isRecording = false;
        //close videowriter
        outputVideoLeft.release();
        outputVideoRight.release();

        ui->BtnRecord->setText("Record");
        ui->pushButton->setEnabled(true);
    }
}
