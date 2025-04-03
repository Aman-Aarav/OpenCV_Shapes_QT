#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Create a blank black canvas
    cv::Mat canvas = cv::Mat::zeros(500, 500, CV_8UC3);

    // Draw shapes
    cv::line(canvas, cv::Point(50, 50), cv::Point(450, 50), cv::Scalar(0, 255, 0), 2); //Draws a green line from (50,50) to (450,50),
    //Thickness is 2 pixels.

    cv::rectangle(canvas, cv::Point(150, 100), cv::Point(400, 300), cv::Scalar(255, 0, 0), 3);  //Draws a blue rectangle, if want filled use -1 as thickness
    cv::rectangle(canvas, cv::Point(150, 420), cv::Point(400, 480), cv::Scalar(0, 0, 255), -1);  //Draws a red filled rectangle

    cv::circle(canvas, cv::Point(250, 250), 100, cv::Scalar(0, 0, 255), 2); // Draws a red circle at (250,250) with a radius of 100 pixels,
    //if want filled use -1 as thickness

    cv::ellipse(canvas, cv::Point(250, 250), cv::Size(150, 100), 45, 0, 360, cv::Scalar(255, 0, 255), 2);// -1 to fill

    std::vector<cv::Point> points = {cv::Point(100, 400), cv::Point(200, 300), cv::Point(300, 400)}; //vector of type cv::Point
    cv::polylines(canvas, points, true, cv::Scalar(0, 255, 255), 2); // in  this -1 will not work
  //  cv::fillPoly(canvas, std::vector<std::vector<cv::Point>>{points}, cv::Scalar(255, 165, 0)); //use this for fill polygon


    // Display the image
    cv::imshow("Shapes", canvas);
    cv::waitKey(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
