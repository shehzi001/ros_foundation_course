#!/usr/bin/env python

from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

d = generate_distutils_setup(
    packages=['ros_publisher_common_msgs_python_examples_ros'],
    package_dir={'ros_publisher_common_msgs_python_examples_ros': 'ros/src'}
)

setup(**d)