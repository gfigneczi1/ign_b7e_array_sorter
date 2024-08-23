from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='array_sorter',
            output='screen',
            executable='array_sorter',
        ),
        Node(
            package='array_sorter',
            output='screen',
            executable='array_publisher',
        ),
    ])