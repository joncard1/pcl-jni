package com.jackflashtech.pcl.impl;

import org.junit.Test;
import org.junit.Before;
import static org.junit.Assert.*;

import com.jackflashtech.pcl.PointCloud;

public class TestPointCloudNormalImpl {
	@Before
	public void setUp() {
		System.loadLibrary("pcl-wrapper");
	}

	@Test
	public void testCreate() {
		PointCloud cloud = new PointCloudNormalImpl();

		assertEquals(0, cloud.getHeight());
		assertEquals(0, cloud.getWidth());
		assertFalse(cloud.isDense());
	}

	@Test
	public void testCreateParameters() {
		PointCloud cloud = new PointCloudNormalImpl(10, 20, true);
		assertEquals(10, cloud.getHeight());
		assertEquals(20, cloud.getWidth());
		assertTrue(cloud.isDense());
	}

	@Test
	public void testResize() {
		PointCloud cloud = new PointCloudNormalImpl();
		cloud.setHeight(10);
		cloud.setWidth(20);
		cloud.resize();

		assertEquals(10, cloud.getHeight());
		assertEquals(20, cloud.getWidth());
		assertNotNull(cloud.getPoints());
		assertEquals(200, cloud.getPoints().size());
	}
}
