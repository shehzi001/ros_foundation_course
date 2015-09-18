#!/usr/bin/env python
# -*- coding: utf -*-

import roslib
roslib.load_manifest('amr_ui')

import sys
import math
from PySide.QtGui import *
from PySide.QtCore import *

import rospy
import actionlib
from tf.transformations import quaternion_from_euler

from amr_msgs.msg import MoveToAction, MoveToGoal


class Form(QDialog):

    def __init__(self, client, parent=None):
        super(Form, self).__init__(parent)
        self.client = client
        # General layout
        new_group = QGroupBox('New goal')
        current_group = QGroupBox('Current goal')
        layout = QHBoxLayout()
        layout.addWidget(new_group)
        layout.addWidget(current_group)
        self.setLayout(layout)
        # Left side -- new goal group
        grid = QGridLayout()
        grid.addWidget(QLabel('X:'), 0, 0)
        self.x_spin = QDoubleSpinBox()
        self.x_spin.setRange(-10, 10)
        self.x_spin.setSingleStep(0.1)
        grid.addWidget(self.x_spin, 0, 1)
        grid.addWidget(QLabel('Y:'), 1, 0)
        self.y_spin = QDoubleSpinBox()
        self.y_spin.setRange(-10, 10)
        self.y_spin.setSingleStep(0.1)
        grid.addWidget(self.y_spin, 1, 1)
        grid.addWidget(QLabel('Yaw:'), 2, 0)
        self.yaw_spin = QSpinBox()
        self.yaw_spin.setRange(0, 360)
        grid.addWidget(self.yaw_spin, 2, 1)
        send_button = QPushButton('Send')
        send_button.clicked.connect(self.button_send_cb)
        grid.addWidget(send_button, 3, 0, 1, 2)
        new_group.setLayout(grid)
        # Right side -- current goal group
        grid = QGridLayout()
        grid.addWidget(QLabel('State:'), 0, 0)
        self.state_text = QLabel('<i>unknown</i>')
        grid.addWidget(self.state_text, 0, 1)
        grid.addWidget(QLabel('Target:'), 1, 0)
        self.target_text = QLabel()
        grid.addWidget(self.target_text, 1, 1)
        grid.addWidget(QLabel('Time left:'), 2, 0)
        grid.addWidget(QLabel('<i>not implemented</i>'), 2, 1)
        cancel_button = QPushButton('Cancel')
        cancel_button.clicked.connect(self.button_cancel_cb)
        grid.addWidget(cancel_button, 3, 0, 1, 2)
        current_group.setLayout(grid)

    def update_state_text(self, target=None):
        state = ['pending', 'active', 'preempted', 'succeeded', 'aborted',
                 'rejected', 'preempting', 'recalling', 'recalled',
                 'lost'][self.client.get_state()]
        self.state_text.setText('<i>%s</i>' % state)
        if target is not None:
            self.target_text.setText('<i>%s</i>' % target)

    def button_send_cb(self):
        x = self.x_spin.value()
        y = self.y_spin.value()
        yaw = self.yaw_spin.value()
        goal = MoveToGoal()
        q = quaternion_from_euler(0, 0, yaw * math.pi / 180)
        goal.target_pose.pose.position.x = x
        goal.target_pose.pose.position.y = y
        goal.target_pose.pose.orientation.x = q[0]
        goal.target_pose.pose.orientation.y = q[1]
        goal.target_pose.pose.orientation.z = q[2]
        goal.target_pose.pose.orientation.w = q[3]
        self.client.send_goal(goal,
                              done_cb=self.action_done_cb,
                              active_cb=self.action_active_cb,
                              feedback_cb=self.action_feedback_cb)
        goal_text = u'%.2f; %.2f; %i°' % (x, y, yaw)
        self.update_state_text(goal_text)

    def button_cancel_cb(self):
        self.client.cancel_goal()
        self.update_state_text('')

    def action_done_cb(self, state, result):
        self.update_state_text('')

    def action_active_cb(self):
        self.update_state_text()

    def action_feedback_cb(self, feeback):
        self.update_state_text()


if __name__ == '__main__':
    rospy.init_node('move_to_client_gui')
    client = actionlib.SimpleActionClient('/motion_controller/move_to',
                                          MoveToAction)
    client.wait_for_server()
    app = QApplication(sys.argv)
    gui = Form(client)
    gui.show()
    rospy.on_shutdown(lambda: app.exit())
    # Qt + Python hack: this timer will allow the interpreter to run each 500
    # ms and at some point in time receive the shutdown callback from ROS.
    timer = QTimer()
    timer.start(500)
    timer.timeout.connect(lambda: None)
    # Start application execution
    sys.exit(app.exec_())
