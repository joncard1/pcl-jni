package com.jackflashtech.pcl.impl;

import com.jackflashtech.pcl.PointCloud;
import com.jackflashtech.pcl.PointXYZ;
import java.util.List;
import java.util.ArrayList;

public class PointCloudPointXYZImpl implements PointCloud {
	private long handle;
	private List<PointXYZ> points;
	
	public PointCloudPointXYZImpl() {
		this(0, 0, false);
	}

	public PointCloudPointXYZImpl(int height, int width, boolean isDense) {
		this.handle = createPointCloud(height, width, isDense);
	}

	public int getHeight() {
		return getHeight(handle);
	}

	public void setHeight(int height) {
		setHeight(height, handle);
	}

	public int getWidth() {
		return getWidth(handle);
	}

	public void setWidth(int width) {
		setWidth(width, handle);
	}

	public boolean isDense() {
		return isDense(handle);
	}

	public void setIsDense(boolean isDense) {
		setIsDense(isDense, handle);
	}

	public List<PointXYZ> getPoints() {
		return points;
	}

	public void finalize() {
		finalize(handle);
	}

	synchronized private native long createPointCloud(int height, int width, boolean isDense);
	synchronized private native int getHeight(long handle);
	synchronized private native void setHeight(int height, long handle);
	synchronized private native int getWidth(long handle);
	synchronized private native void setWidth(int width, long handle);
	synchronized private native boolean isDense(long handle);
	synchronized private native void setIsDense(boolean isDense, long handle);
	private native void finalize(long handle);
}
