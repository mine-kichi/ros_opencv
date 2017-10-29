#include "ros/ros.h"
#include "std_msgs/String.h"

#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
    cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
    cv::waitKey(30);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

/*
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
*/


int main(int argc, char **argv)
{

  ros::init(argc, argv, "image_listener");
//  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  cv::namedWindow("view");
  cv::startWindowThread();
  image_transport::ImageTransport it(n);
  image_transport::Subscriber sub = it.subscribe("image",1,imageCallback);

//  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
 ros::spin();

  return 0;
}
