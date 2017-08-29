#include "leapmotionvideo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LeapMotionVideo w;
    w.show();

    return a.exec();
}
