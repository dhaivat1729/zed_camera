#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <image_transport/image_transport.h>
#include <ros/ros.h>
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <stdlib.h>
#include <iostream>
#include <cv.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

  ros::init(argc, argv, "Image_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher stereo_image_msg = it.advertise("stereo_camera/stereo_image", 1); // To publish image coming from left camera on mentioned topic
  image_transport::Publisher left_image_msg = it.advertise("stereo_camera/left_image", 1); // To publish image coming from left camera on mentioned topic
  image_transport::Publisher right_image_msg = it.advertise("stereo_camera/right_image", 1); // To publish image coming from right camera on mentioned topic
  namedWindow("Left camera",CV_WINDOW_AUTOSIZE);
  namedWindow("Stereo camera",CV_WINDOW_AUTOSIZE);
  namedWindow("Right camera",CV_WINDOW_AUTOSIZE);
  cv::Rect myROILeft(0, 0, 1280, 720);
  cv::Rect myROIRight(1280, 0, 1280, 720);

  Mat frame, left_image, right_image;
  Size frame_size;
  VideoCapture cap(1);
  if(!cap.isOpened()) // if not success, exit program
  {
    cout << "Cannot open video file!" << endl;
    return -1;
  }


  while(nh.ok()){


    bool bSuccess = cap.read(frame);
    //cvtColor(frame, frame, COLOR_BGR2GRAY);
    // cout << frame_size.width << " " << frame_size.height << endl;
    Mat stereo_image = frame;
    left_image =frame(myROILeft);
    right_image =frame(myROIRight);
    frame_size = frame.size();
    ros::Duration(0.05).sleep();
    sensor_msgs::ImagePtr left_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", left_image).toImageMsg();
    sensor_msgs::ImagePtr right_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", right_image).toImageMsg();
    sensor_msgs::ImagePtr stereo_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", stereo_image).toImageMsg();
    stereo_image_msg.publish(stereo_msg);
    left_image_msg.publish(left_msg);
    right_image_msg.publish(right_msg);
    imshow("Left camera", left_image); //show image coming from a left camera
    imshow("Stereo camera", stereo_image);
    imshow("Right camera", right_image); //show image coming from a right camera
    if(waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
   {
            cout << "esc key is pressed by user" << endl;
            break;
   }
    ros::spinOnce();

  }
    return 0;

}
