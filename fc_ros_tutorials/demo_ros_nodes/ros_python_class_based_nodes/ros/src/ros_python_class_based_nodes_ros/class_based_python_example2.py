#!/usr/bin/env python
"""
This script initilizes simple class based python node.
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
    rospy.init_node('class_based_example2_node', anonymous=False)
    rospy.loginfo("class_based_example2_node is now running")
    demo_class1 = DemoClass()
    demo_class1.initilize_parameters(10, 10.0)
    rospy.spin()

def  main():
    initlize_node()