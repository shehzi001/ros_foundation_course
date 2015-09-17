#!/usr/bin/env python
"""
This module contains a simple code to initlize a node.
"""
#-*- encoding: utf-8 -*-
__author__ = 'shehzad ahmed'
import rospy

def initlize_node():
    '''
    Initilize node and spin which simply keeps python 
    from exiting until this node is stopped
    '''
    rospy.init_node('ros_python_example1', anonymous=False)
    rospy.loginfo("ros_python_example1 is now running")
    rospy.spin()

def main():
    initlize_node()
    
    