#include "std_msgs/msg/float64_multi_array.hpp"
#include <rclcpp/rclcpp.hpp>

using std::placeholders::_1;

class ArrayPublisher : public rclcpp::Node
{
public:
  ArrayPublisher() : Node("array_publisher")
  {
    array_pub = this->create_publisher<std_msgs::msg::Float64MultiArray>("unsorted_array", 1);
  }

  // publisher declaration
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr array_pub;
  std_msgs::msg::Float64MultiArray unsorted_array;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<ArrayPublisher>();

  rclcpp::Rate rate(10);

  while (rclcpp::ok())
  {
    std::vector<double> data {5.21,4.65, 12.13, -0.21, 0.001, 0, 32.21};
    node->unsorted_array.data = data;
    node->array_pub->publish(node->unsorted_array);
    rclcpp::spin_some(node);
    rate.sleep();
  }

  rclcpp::shutdown();
  return 0;
}