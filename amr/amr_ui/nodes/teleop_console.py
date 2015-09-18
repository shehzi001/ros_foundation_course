#!/usr/bin/env python

# This node is based on youbot_keyboard_teleop.py script from youbot-ros-pkg.
# See: http://goo.gl/uGxK9

PACKAGE = 'amr_ui'
NODE = 'teleop_console'

import roslib
roslib.load_manifest(PACKAGE)
import rospy

import argparse
import select
import signal
import sys
import termios
import tty

from geometry_msgs.msg import Twist

MOVE_KEYS = {'qwerty': 'uiojlm,.', 'dvorak': 'gcrhnmwv'}
CFG_KEYS = {'qwerty': 'qzwxec', 'dvorak': '\';,q.j'}

MOVE_CMDS = [(+1, +0, +1),  # forwards + rotation left
             (+1, +0, +0),  # forwards
             (+1, +0, -1),  # forwards + rotation right
             (+0, +1, +0),  # left
             (+0, -1, +0),  # right
             (+0, +0, +1),  # turn left on spot
             (-1, +0, +0),  # backward
             (+0, +0, -1)]  # turn right on spot

CFG_CMDS = [(1.1, 1.1),
            (0.9, 0.9),
            (1.1, 1.0),
            (0.9, 1.0),
            (1.0, 1.1),
            (1.0, 0.9)]

MSG = '''
Move around
-----------

  %c  %c  %c
  %c     %c
  %c  %c  %c

Configuration
-------------

  %c / %c : increase or decrease max velocities by 10%%
  %c / %c : increase or decrease only linear speed by 10%%
  %c / %c : increase or decrease only angular speed by 10%%

CTRL-C to quit
'''


class TimeoutException(Exception):
    pass


def get_key():
    def timeout_handler(signum, frame):
        raise TimeoutException()
    old_handler = signal.signal(signal.SIGALRM, timeout_handler)
    signal.alarm(1)
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    try:
        key = sys.stdin.read(1)
    except TimeoutException:
        return "-"
    finally:
        signal.signal(signal.SIGALRM, old_handler)
    signal.alarm(0)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key


def print_velocities(speed, turn):
    print 'Current configuration:\tspeed %s\tturn %s' % (speed, turn)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='''
    Control the robot with keyboard.
    ''')
    parser.add_argument('--dvorak', help='use Dvorak-friendly key bindings',
                        action='store_true')
    args = parser.parse_args()

    layout = 'dvorak' if args.dvorak else 'qwerty'
    move_bindings = dict(zip(MOVE_KEYS[layout], MOVE_CMDS))
    cfg_bindings = dict(zip(CFG_KEYS[layout], CFG_CMDS))
    msg = MSG % tuple(MOVE_KEYS[layout] + CFG_KEYS[layout])

    settings = termios.tcgetattr(sys.stdin)
    pub = rospy.Publisher('/cmd_vel', Twist)
    rospy.init_node(NODE)

    speed = 0.1
    turn = 0.1
    x = 0
    y = 0
    th = 0
    status = 0

    try:
        print msg
        print_velocities(speed, turn)
        while True:
            key = get_key()
            if key in move_bindings.keys():
                x, y, th = move_bindings[key]
            elif key in cfg_bindings.keys():
                speed = speed * cfg_bindings[key][0]
                turn = turn * cfg_bindings[key][1]
                print_velocities(speed, turn)
                if (status == 14):
                    print msg
                status = (status + 1) % 15
            else:
                x = 0
                y = 0
                th = 0
                if (key == '\x03'):
                    break
            twist = Twist()
            twist.linear.x = x * speed
            twist.linear.y = y * speed
            twist.linear.z = 0
            twist.angular.x = 0
            twist.angular.y = 0
            twist.angular.z = th * turn
            pub.publish(twist)
    except Exception, e:
        print e
    finally:
        twist = Twist()
        twist.linear.x = 0
        twist.linear.y = 0
        twist.linear.z = 0
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = 0
        pub.publish(twist)

    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
