#!/usr/bin/env python
import rospy

class DemoClass():
    def __init__(self):
        self.initilize_parameters(0, 0.0)

    def initilize_parameters(self, number_count, total_sum):
        rospy.loginfo("Initlizing class variables.")
        self.number_count = number_count;
        self.total_sum = total_sum;