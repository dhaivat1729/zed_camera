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

int main(int argc, char* argv[])
{

    //ros::init(argc, argv, "Image_publisher");
    //ros::NodeHandle nh;
    // image_transport::ImageTransport it(nh);
    // image_transport::Publisher image_msg = it.advertise("/camera/image", 1);

    VideoCapture cap(1); // open the video file for reading
    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the video file" << endl;
         return -1;
    }

    //cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms

    // double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

     // cout << "Frame per seconds : " << fps << endl;

    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while(1)
    {
        Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
                        cout << "Cannot read the frame from video file" << endl;
                       break;
        }

        imshow("MyVideo", frame); //show the frame in "MyVideo" window

      //   sensor_msgs::ImagePtr current_image = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
      //   current_image->header.stamp=ros::Time::now();
      //   image_msg.publish(current_image);
        if(waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
       {
                cout << "esc key is pressed by user" << endl;
                break;
       }
    }

    return 0;

}
