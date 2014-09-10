#!/usr/bin/env python
"""
This script initilize the node.
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
    rospy.init_node('publish_common_messages_examples_node', anonymous=False)
    rospy.loginfo("publish_common_messages_examples_node is now running")
    
    demo_class1 = DemoClass()

    rospy.spin()

def  main():
    initlize_node()