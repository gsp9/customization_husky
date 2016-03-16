#include "ros/ros.h"
#include "move_base/move_base.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "clear_costmaps");
 
  tf::TransformListener tf(ros::Duration(10));
  move_base::MoveBase move_base( tf );
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient(move_base::MoveBase::clearCostmapsService,"clear_costmaps",true);
  move_base::MoveBase::clearCostmapsService srv;
  ros::Rate rate(10);
  while(true)
  {
    if (client.call(srv))
    {
      ROS_INFO("Clearing all Costmaps");
    }
    else
    {
      ROS_ERROR("Failed to call service clear_costmaps_srv_");
      return 1;
    }
    rate.sleep();
   }
  return 0;
}
