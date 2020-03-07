#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from std_msgs.msg import String

def publisher():
    pub = rospy.Publisher('vel_msg_1', Twist, queue_size=10)
    rospy.init_node('node_1', anonymous=True)
    rate = rospy.Rate(1) # 1hz
    vel = Twist()
    while not rospy.is_shutdown():
	vel.linear.x = 1
	vel.angular.z= 0
        pub.publish(vel)
        rate.sleep()    # 500msec
	

if __name__== '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        pass
