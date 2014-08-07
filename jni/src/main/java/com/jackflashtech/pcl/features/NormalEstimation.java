package com.jackflashtech.pcl.features;

import com.jackflashtech.pcl.PointCloud;
import com.jackflashtech.pcl.search.KdTree;

public interface NormalEstimation {
	public void setInputCloud(PointCloud cloud);
	public void setSearchMethod(KdTree tree);
	public void setRadiusSearch(double radius);
	public void compute(PointCloud cloud);
}
