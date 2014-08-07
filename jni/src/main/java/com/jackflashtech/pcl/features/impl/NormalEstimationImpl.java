package com.jackflashtech.pcl.features.impl;

import com.jackflashtech.pcl.features.NormalEstimation;
import com.jackflashtech.pcl.PointCloud;
import com.jackflashtech.pcl.search.KdTree;

public class NormalEstimationImpl implements NormalEstimation {
	private long handle;

	public NormalEstimationImpl() {
		handle = this.createInstance();
	}

	private synchronized native long createInstance();

	public void setInputCloud(PointCloud cloud) {
		setInputCloud(cloud, handle);
	}

	private synchronized native void setInputCloud(PointCloud cloud, long handle);

	public void setSearchMethod(KdTree tree) {
		setSearchMethod(tree, handle);
	}

	private synchronized native void setSearchMethod(KdTree tree, long handle);

	public void setRadiusSearch(double radius) {
		setRadiusSearch(radius, handle);
	}

	private synchronized native void setRadiusSearch(double radius, long handle);

	public void compute(PointCloud cloud) {
		compute(cloud, handle);
	}

	private synchronized native void compute(PointCloud cloud, long handle);
}
