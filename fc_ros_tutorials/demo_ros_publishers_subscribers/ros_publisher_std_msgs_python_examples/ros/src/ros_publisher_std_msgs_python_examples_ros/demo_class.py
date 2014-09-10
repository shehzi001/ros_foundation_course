#!/usr/bin/env python
'''
This script demostrates the way of filling 
ros std_msgs by giving few examples.
'''
import rospy
from std_msgs.msg import Bool
from std_msgs.msg import Float32
from std_msgs.msg import Int32
from std_msgs.msg import String


class DemoClass():
    def __init__(self):
        self.prepare_std_msgs()
        
        self.bool_msg_pub = rospy.Publisher("~node_status", Bool, queue_size=100)

        self.float_msg_pub = rospy.Publisher("~total_sum", Float32, queue_size=100)

        '''
        Write publishers to publish int and string messages.
        self.int_msg_pub
        self.string_msg_pub
        '''

    def prepare_std_msgs(self):
        rospy.loginfo("Preparing std_msgs......")
        '''
        Fill Bool message
        '''
        self.status_msg = Bool()

        self.status_msg.data = False

        '''
        Fill Float32 message
        '''
        self.sum_msg = Float32()

        self.sum_msg.data = 1.0

        '''
        Fill Int32 message
        Please, do it your self for practice
        '''

        '''
        Fill String message
        Please, do it your self for practice
        '''
        rospy.loginfo("std_msgs preparation done......")

    def publish_std_msgs(self):
        '''
        Publish Bool message
        '''
        self.bool_msg_pub.publish(self.status_msg)

        '''
        Publish total sum message
        '''
        self.float_msg_pub.publish(self.sum_msg)

        '''
        Publish Int32 message
        Please, do it your self for practice
        '''

        '''
        Publish String message
        Please, do it your self for practice
        '''
