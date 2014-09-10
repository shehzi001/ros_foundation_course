#!/usr/bin/env python
'''
This script demostrates the way of subscribing to 
std_msgs by giving few examples.
'''
import rospy
from std_msgs.msg import Bool
from std_msgs.msg import Float32
from std_msgs.msg import Int32
from std_msgs.msg import String


class DemoClass():
    def __init__(self):

        self.bool_msg_sub = rospy.Subscriber("node_status", Bool, self.node_status_cb)

        self.float_msg_sub = rospy.Subscriber("total_sum", Float32, self.total_sum_cb)

        '''
        Please, Do it yourself. 
        Write code to subscribe to Int32 type topic "number_count"
        '''

        '''
        Please, Do it yourself.  
        Write code to subscribe to String type topic "node_event"
        '''

    def node_status_cb(self, msg):

        if msg.data:
            rospy.loginfo("node_status_cb message: %s", "true")
        else:
            rospy.loginfo("node_status_cb message: %s", "false")

    def total_sum_cb(self, msg):

        rospy.loginfo("total_sum_cb message: %f", msg.data)

    '''
    Please, Do it yourself. 
    Write callback method for topic "number_count"
    '''


    '''
    Please, Do it yourself. 
    Write callback method for topic "node_event"
    '''
