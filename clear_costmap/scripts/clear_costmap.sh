#!/bin/sh

while [ "true" ]
do
  echo "clearing all CostMaps"
  rosservice call /move_base/clear_costmaps 
  sleep 10
done
