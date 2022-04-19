#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/mat.hpp>
#include <opencv2/videoio.hpp>
#include <QTimer>

#include "cameracalibrator.h"

using namespace cv;
using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startCameraButton_clicked();
    void on_takeSnaphotButton_clicked();
    void cameraTimerTimeout();

    void findAndDrawPoints();
    void startCalibration();

private:
    Ui::MainWindow *ui;
    cv::Mat image, imageSaved;
    cv::VideoCapture capture;
    bool isCameraRunning, isCalibrate;
    QTimer cameraTimer;
    Size boardSize;
    int numSeq, numRequiredSnapshot, successes;
    CameraCalibrator cameraCalib;
    vector<Mat> imageList;
};

#endif // MAINWINDOW_H
