# `array_sorter` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/gfigneczi1/ign_b7e_array_sorter
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select array_sorter --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch array_sorter launch_array_sorter.launch.py
```

### Check calculation
Echo topics /unsorted_array and /sorted_array by:
``` r
ros2 topic echo /unsorted_array
```
``` r
ros2 topic echo /sorted_array
```