package com.jackflashtech.pcl.search.impl;

import com.jackflashtech.pcl.search.KdTree;

public class KdTreePointXYZ implements KdTree {
	private long handle;

	public KdTreePointXYZ() {
		handle = createKdTreePointXYZ();
	}

	private synchronized native long createKdTreePointXYZ();
}
