package com.jackflashtech.pcl.impl;

import org.junit.Test;
import org.junit.Before;
import static org.junit.Assert.*;

import java.util.List;
import java.util.ArrayList;
import com.jackflashtech.pcl.PointXYZ;
import com.jackflashtech.pcl.impl.PointXYZImpl;

public class TestPointsListImpl {
	@Before
	public void setUp() {
		System.loadLibrary("pcl-wrapper");
	}

	@Test
	public void testCreate() {
		List points = new PointsList();
	}

	@Test
	public void testAddAll() {
		PointXYZ pt1 = new PointXYZImpl(1f, 2f, 3f);
		PointXYZ pt2 = new PointXYZImpl(4f, 5f, 6f);
		List input = new ArrayList();
		input.add(pt1);
		input.add(pt2);

		List points = new PointsList();
		points.addAll(input);

		PointXYZ pt3 = (PointXYZ)points.get(0);
		PointXYZ pt4 = (PointXYZ)points.get(1);
		assertEquals(1f, pt3.getX(), .0001);
		assertEquals(2f, pt3.getY(), .0001);
		assertEquals(3f, pt3.getZ(), .0001);
		assertEquals(4f, pt4.getX(), .0001);
		assertEquals(5f, pt4.getY(), .0001);
		assertEquals(6f, pt4.getZ(), .0001);
	}
}
