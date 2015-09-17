#!/usr/bin/env python
"""
This script demostrates the way of filling 
ros std_msgs by giving few examples.
"""
#-*- encoding: utf-8 -*-
__author__ = 'shehzad ahmed'
import rospy
from demo_class import *

def initlize_node():
    '''
    Initilize node and spin which simply keeps python 
    from exiting until this node is stopped
    '''
    rospy.init_node('publish_std_messages_examples_node', anonymous=False)
    rospy.loginfo("publish_std_messages_examples_node is now running")
    demo_class1 = DemoClass()

    r = rospy.Rate(10)
    while not rospy.is_shutdown():
    	demo_class1.publish_std_msgs()
    	r.sleep()

def  main():
    initlize_node()