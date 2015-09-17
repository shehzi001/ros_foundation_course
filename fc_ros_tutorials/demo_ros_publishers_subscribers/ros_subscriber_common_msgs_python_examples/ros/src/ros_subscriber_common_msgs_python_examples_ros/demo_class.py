#!/usr/bin/env python
'''
This script demostrates the way of filling 
ros common_msgs by giving few examples.
'''
import rospy

from geometry_msgs.msg import Point
from geometry_msgs.msg import PointStamped
from geometry_msgs.msg import Pose2D
from geometry_msgs.msg import PoseWithCovariance
from geometry_msgs.msg import TwistWithCovariance
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Transform

from actionlib_msgs.msg import GoalID
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
from sensor_msgs.msg import Range
from trajectory_msgs.msg import JointTrajectoryPoint

class DemoClass():
    def __init__(self):
        self.point_msg_sub = rospy.Subscriber("point", Point, self.point_cb)
        self.pointstamped_msg_sub = rospy.Subscriber("stamped_point", 
                PointStamped, self.pointstamped_cb)
        self.twist_msg_sub = rospy.Subscriber("twist", Twist, self.twist_cb)

        self.laserscan_msg_sub = rospy.Subscriber("laser_scan", LaserScan, self.laserscan_cb)
        
        '''
        Please, add the topics for the following messages:
        PoseStamped, Pose2D, Transform, GoalID, Odometry 
        LaserScan, Range, JointTrajectoryPoint

        Topic names are:
            self.posestamped_msg_pub
            self.pose2d_msg_pub
            self.transform_msg_pub
            self.actionlib_msg_pub
            self.odometry_msg_pub
            self.joint_traj_point_msg_pub
        '''

    def point_cb(self, msg):
        print "point_msg_cb"
        print msg
    
    def pointstamped_cb(self, msg):
        print "pointstamped_cb"
        print msg

    def twist_cb(self, msg):
        print "twist_cb"
        print msg

    def laserscan_cb(self, msg):
        print "laserscan_cb"
        print msg