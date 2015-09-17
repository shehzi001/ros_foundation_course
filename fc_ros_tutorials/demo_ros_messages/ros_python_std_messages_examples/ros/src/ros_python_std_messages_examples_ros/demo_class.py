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
        self.prepare_std_msg()

    def prepare_std_msg(self):
        rospy.loginfo("Preparing std_msgs......")
        '''
        Fill Bool message
        '''
        bool_msg = Bool()

        bool_msg.data = False

        '''
        Fill Float32 message
        '''
        float32_msg = Float32()

        float32_msg.data = 1.0

        '''
        Fill Int32 message
        Please, do it your self for practice
        '''

        '''
        Fill String message
        Please, do it your self for practice
        '''
        rospy.loginfo("std_msgs preparation done......")
