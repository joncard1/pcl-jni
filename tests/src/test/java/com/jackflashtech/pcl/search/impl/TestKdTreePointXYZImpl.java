package com.jackflashtech.pcl.search.impl;

import org.junit.Test;
import org.junit.Before;
import com.jackflashtech.pcl.search.KdTree;

public class TestKdTreePointXYZImpl {

	@Before
	public void setUp() {
		System.loadLibrary("pcl-wrapper");
	}

	public void testCreat() {
		KdTree tree = new KdTreePointXYZ();
	}
}
