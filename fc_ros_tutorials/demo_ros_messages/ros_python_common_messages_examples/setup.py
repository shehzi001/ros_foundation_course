#!/usr/bin/env python

from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

d = generate_distutils_setup(
    packages=['ros_python_common_messages_examples_ros'],
    package_dir={'ros_python_common_messages_examples_ros': 'ros/src'}
)

setup(**d)