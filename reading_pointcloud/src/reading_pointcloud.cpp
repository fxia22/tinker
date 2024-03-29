// Project      : reading_pointcloud
// File         : reading_pointcloud.cpp
// Author       : bss
// Creation Date: 2014-07-12
// Last modified: 2014-07-12, 05:13:52
// Description  : convert ros-style pointcloud to pcl-style.
// 

#include <stdio.h>
#include <string>
#include <ros/ros.h>
#include <reading_pointcloud/reading_pointcloud.h>

CloudConverter::CloudConverter()
    : nh_()
    , ready_xyz_(false)
    , ready_xyzrgb_(false)
{
    sub_xyz_ = nh_.subscribe<pcl::PointCloud<pcl::PointXYZ> >("/openni/points2_xyz", 1, &CloudConverter::cloudXYZCb, this);
    sub_xyzrgb_ = nh_.subscribe<pcl::PointCloud<pcl::PointXYZRGB> >("/openni/points2", 1, &CloudConverter::cloudXYZRGBCb, this);
}

CloudConverter::~CloudConverter()
{
}
    
void CloudConverter::cloudXYZCb(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& msg)
{
    msg_xyz_ = msg;
    ready_xyz_ = true;
}

void CloudConverter::cloudXYZRGBCb(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& msg)
{
    msg_xyzrgb_ = msg;
    ready_xyzrgb_ = true;
}

