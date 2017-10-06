#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/video/tracking.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cv.h>
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
/*float camera_matrix_l[3][3]={{733.129018, 0, 638.574825}, {0, 716.4517059999999, 409.731346}, {0, 0, 1}};  //Projection Matrix Ps3 camera
float distortion_coefficients_l[5][1]={{-0.193503}, {0.043996}, {0.002621}, {-0.003301}, {0}};            //Camera Matrix o


float camera_matrix_r[3][3]={{731.947084, 0, 629.517635}, {0, 720.0689609999999, 373.897345}, {0, 0, 1}};  //Projection Matrix Ps3 camera
float distortion_coefficients_r[5][1]={{-0.167758}, {0.015563}, {0.001688}, {-0.002448}, {0}};            //Camera Matrix o


float r1[3][3]={{0.9998309999999999, 0.0009149999999999999, -0.018385},{-0.0007289999999999999, 0.9999479999999999, 0.010134},{0.018393, -0.010119, 0.99978}};
float t1[3][4]={{714.348091, 0, 645.484322, 0},{0, 714.348091, 400.624165, 0},{0, 0, 1, 0}};

float r2[3][3]={{0.9996619999999999, 0.001344, -0.02595},{-0.001606, 0.9999479999999999, -0.010107},{0.025935, 0.010145, 0.9996119999999999}};
float t2[3][4]={{714.348091, 0, 645.484322, -84.129108},{0, 714.348091, 400.624165, 0},{0, 0, 1, 0}};
*/
Size imageSize;

/*
Mat matrix_l = Mat(3, 3, CV_32FC1,  camera_matrix_l);
Mat distortion_l = Mat(5, 1, CV_32FC1, distortion_coefficients_l);

Mat matrix_r = Mat(3, 3, CV_32FC1,  camera_matrix_r);
Mat distortion_r = Mat(5, 1, CV_32FC1, distortion_coefficients_r);

Mat R1=Mat(3, 3, CV_32FC1,  r1);
Mat T1=Mat(3, 4, CV_32FC1,  t1);
Mat R2=Mat(3, 3, CV_32FC1,  r2);
Mat T2=Mat(3, 4, CV_32FC1,  t2);



Mat map1_l,map2_l,map1_r,map2_r;
*/
cv::Rect myROI(0, 0, 1280, 720);
cv::Rect myROI1(1280, 0, 1280, 720);
ros::init(argc, argv, "image_publisher");
ros::NodeHandle nh;
image_transport::ImageTransport it(nh);
image_transport::Publisher right_msg = it.advertise("zed/rectified_images", 1);
image_transport::Publisher current_msg = it.advertise("current/image", 1);
namedWindow("Original",CV_WINDOW_AUTOSIZE);
namedWindow("Calibrated",CV_WINDOW_AUTOSIZE);

VideoCapture cap(1);
if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the video file" << endl;
         return -1;
    }
Mat image,left_im,right_im,left_im_undist,right_im_undist,frame;
bool bSuccess1 = cap.read(frame);
// cvtColor(frame, frame, COLOR_BGR2GRAY);
cv::Mat img_l =frame(myROI);
imageSize=img_l.size();
initUndistortRectifyMap(matrix_l,distortion_l, R1,T1,imageSize, CV_16SC2, map1_l, map2_l);

initUndistortRectifyMap(matrix_r,distortion_r, R2,T2,imageSize, CV_16SC2, map1_r, map2_r);



  while (nh.ok()) {

   bool bSuccess1 = cap.read(image);
   Mat currentimage=image;
   /*left_im =image(myROI);
   right_im =image(myROI1);


   remap(left_im,left_im_undist , map1_l, map2_l, 2);
   remap(right_im, right_im_undist, map1_r, map2_r, 2);

    Mat left = left_im_undist.clone();
    Mat right = right_im_undist.clone();

   remap(left_im,left , map1_l, map2_l, 2);
   remap(right_im, right, map1_r, map2_r, 2);

   Mat combine(left.size().height, left.size().width + left.size().width, CV_8UC3);
   Mat left_roi(combine, Rect(0, 0, left.size().width, left.size().height));
   left.copyTo(left_roi);
   Mat right_roi(combine, Rect(left.size().width, 0, left.size().width, left.size().height));
   right.copyTo(right_roi);
   sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", combine).toImageMsg();
   sensor_msgs::ImagePtr curr_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", currentimage).toImageMsg();
   imshow("Original", currentimage); //show image coming from a left camera*/
   imshow("Calibrated", currentimage); //show image coming from a right camera
   sensor_msgs::ImagePtr curr_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", currentimage).toImageMsg();
   msg->header.stamp=ros::Time::now();

   //right_msg.publish(msg);
   current_msg.publish(curr_msg);
   ros::spinOnce();
  }
}
