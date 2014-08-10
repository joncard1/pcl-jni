package com.jackflashtech.pcl.impl;

import org.junit.Test;
import org.junit.Before;
import static org.junit.Assert.*;
import com.jackflashtech.pcl.PointXYZ;

import com.jackflashtech.pcl.PointCloud;

public class TestPointCloudPointXYZImpl {
	@Before
	public void setUp() {
		System.loadLibrary("pcl-wrapper");
	}

	@Test
	public void testCreate() {
		PointCloud cloud = new PointCloudPointXYZImpl();

		assertEquals(0, cloud.getHeight());
		assertEquals(0, cloud.getWidth());
		assertFalse(cloud.isDense());
	}

	@Test
	public void testCreateParameters() {
		PointCloud cloud = new PointCloudPointXYZImpl(10, 20, true);
		assertEquals(10, cloud.getHeight());
		assertEquals(20, cloud.getWidth());
		assertTrue(cloud.isDense());
	}

	@Test
	public void testResize() {
		PointCloud cloud = new PointCloudPointXYZImpl();
		cloud.setHeight(10);
		cloud.setWidth(20);
		cloud.resize();

		assertEquals(10, cloud.getHeight());
		assertEquals(20, cloud.getWidth());
		assertNotNull(cloud.getPoints());
		assertEquals(200, cloud.getPoints().size());
	}

	@Test
	public void testAdd() {
		PointXYZ point = new PointXYZImpl(10f, 20f, 30f);

		PointCloud cloud = new PointCloudPointXYZImpl();
		cloud.setHeight(1);
		cloud.setWidth(1);
		cloud.resize();
		cloud.getPoints().add(0, point);

		assertEquals(10f, ((PointXYZ)cloud.getPoints().get(0)).getX(), 0.0001);
		assertEquals(20f, ((PointXYZ)cloud.getPoints().get(0)).getY(), 0.0001);
		assertEquals(30f, ((PointXYZ)cloud.getPoints().get(0)).getZ(), 0.0001);
	}
}
