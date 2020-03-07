#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/String.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    // Initialize the ROS node, and assign the node a name
    ros::init(argc, argv, "publish_numbers");
    // Create a node handler
    ros::NodeHandle n;

    // Creates the publisher, and assign it to publish 
    //to the /diffBot/cmd_vel topic, with a queue size of 10
    ros::Publisher pub = n.advertise<std_msgs::String>("/test_topic_1", 10);
    // Sets the loop to publish at a rate of 2Hz
    ros::Rate rate(2);
    int i=-1;
    while (ros::ok()) {
        // Declares the message to be sent
        std_msgs::String msg;

        i++;
        if(i>10)
        {
            i=0;
        }
        // Random x value between -2 and 2 
        msg.data = std::to_string(i);

        // Publish the message
        pub.publish(msg);
        
        // Delays until it is time to send another message
        rate.sleep();
    }
}