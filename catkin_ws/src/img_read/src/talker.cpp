#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
 
/**
* This tutorial demonstrates simple sending of messages over the ROS system.
*/
int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle n;

  image_transport::ImageTransport it(n);
  image_transport::Publisher pub = it.advertise("image",1);

  cv::Mat image = cv::imread("/home/mine/work/ros_kinetic/catkin_ws_test/src/img_read/src/test.bmp",1);
//  cv::imshow("Image", image);
  cv::waitKey(30);
  sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

//  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(5);

/*add
  cv::Mat src_img;
  src_img = cv::imread("/home/mine/work/ros_kinetic/catkin_ws_test/src/img_read/src/test.bmp",1);
  // 画像が読み込まれなかったらプログラム終了
  if(src_img.empty()) return -1;
  // 結果画像表示
  cv::namedWindow("Image", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  cv::imshow("Image", src_img);
  cv::waitKey(0);
*/
//  int count = 0;
  while (ros::ok())
  {
//    std_msgs::String msg;
//    std::stringstream ss;
//    ss << "hello world " << count;
//    msg.data = ss.str();
//    ROS_INFO("%s", msg.data.c_str());
//    chatter_pub.publish(msg);
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
//    ++count;
  }
  return 0;
}
