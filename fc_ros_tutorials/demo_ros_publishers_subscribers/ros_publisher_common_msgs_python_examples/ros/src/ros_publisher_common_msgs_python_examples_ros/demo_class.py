#!/usr/bin/env python
'''
This script demostrates the way of filling 
ros common_msgs by giving few examples.
'''
import rospy
import random

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
        self.point_msg_pub = rospy.Publisher("~point", Point, queue_size=100)
        self.pointstamped_msg_pub = rospy.Publisher("~stamped_point", 
                PointStamped, queue_size=100)
        self.twist_msg_pub = rospy.Publisher("~twist", Twist, queue_size=100)

        self.laserScan_msg_pub = rospy.Publisher("~laser_scan", LaserScan, queue_size=100)
        
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

    def prepare_and_publish_common_msgs(self):
        self.prepare_and_publish_geometry_msg()
        self.prepare_and_publish_actionlib_msg()
        self.prepare_and_publish_odometry_msg()
        self.prepare_and_publish_laserscan_msg()
        self.prepare_and_publish_range_msg()
        self.prepare_and_publish_joint_trajectoy_point_msg()


    def prepare_and_publish_geometry_msg(self):
        '''
        Fill and publish point message
        '''
        point_msg = Point()

        point_msg.x = 1.0;
        point_msg.y = 1.0;
        point_msg.z = 1.0;

        self.point_msg_pub.publish(point_msg)

        '''
        Fill and publish point message
        '''
        point_stamped_msg = PointStamped()

        now = rospy.get_rostime()
        #rospy.loginfo("Current time %i %i", now.secs, now.nsecs)
        point_stamped_msg.header.stamp = now;
        point_stamped_msg.header.frame_id = "frame_dummy";

        point_stamped_msg.point.x = 1.0;
        point_stamped_msg.point.y = 1.0;
        point_stamped_msg.point.z = 1.0;

        self.pointstamped_msg_pub.publish(point_stamped_msg)

        '''
        Fill and publish twist message
        '''
        twist_msg = Twist()

        twist_msg.linear.x = 1.0;
        twist_msg.linear.y = 0.0;
        twist_msg.linear.z = 0.0;

        twist_msg.angular.x = 0.0;
        twist_msg.angular.y = 0.0;
        twist_msg.angular.z = 0.0;

        self.twist_msg_pub.publish(twist_msg)

        '''
        Fill and publish pose 2D message
        Please, do it your self for practice
        '''
        pose_2d_msg = Pose2D()

        '''
        Fill and publish pose stamped message
        Please, do it your self for practice
        '''
        pose_stamped_msg = PoseStamped()

        '''
        Fill and publish transform message
        Please, do it your self for practice
        '''
        transform_msg = Transform()

    def prepare_and_publish_actionlib_msg(self):
        '''
        Fill and publish action lib message
        '''
        goal_id_msg = GoalID()

        now = rospy.get_rostime()
        goal_id_msg.stamp = now
        goal_id_msg.id = "ACTIVE"

    def prepare_and_publish_odometry_msg(self):
        '''
        Fill and publish odometry message
        Please, do it your self for practice
        '''
        odometry_msg = Odometry()

        pose = PoseWithCovariance();
        twist = TwistWithCovariance();

    def prepare_and_publish_laserscan_msg(self):

        '''
        Fill and publish laser scan message
        '''
        laser_scan_msg = LaserScan()

        #Step 1: 
        num_readings = 15
        laser_frequency = 40
        ranges = []
        intensities = []
        count = 0
        i = 0 

        #generate some fake data for laser scan
        while (i < num_readings):
            ranges.append(random.randrange(0.0,4.0))
            intensities.append(random.randrange(0.0,4.0))
            i = i + 1

        #Step 2
        now = rospy.get_rostime()
        laser_scan_msg.header.stamp = now
        laser_scan_msg.header.frame_id = "laser_frame"
        laser_scan_msg.angle_min = -1.57
        laser_scan_msg.angle_max = 1.57
        laser_scan_msg.angle_increment = 3.14 / num_readings
        laser_scan_msg.time_increment = (1 / laser_frequency) / (num_readings)
        laser_scan_msg.range_min = 0.0
        laser_scan_msg.range_max = 4.0

        laser_scan_msg.ranges = ranges
        laser_scan_msg.intensities = intensities

        self.laserScan_msg_pub.publish(laser_scan_msg)

    def prepare_and_publish_range_msg(self):
        '''
        Fill and publish range message
        Please, do it your self for practice
        '''
        range_msg = Range()

    def prepare_and_publish_joint_trajectoy_point_msg(self):
        '''
        Fill and publish joint trajectory point message
        Please, do it your self for practice
        '''
        joint_traj_point_msg = JointTrajectoryPoint()