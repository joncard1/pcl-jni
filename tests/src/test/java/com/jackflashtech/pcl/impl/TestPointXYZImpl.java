package com.jackflashtech.pcl.impl;

import org.junit.Test;
import org.junit.Before;
import static org.junit.Assert.*;

import com.jackflashtech.pcl.PointXYZ;

public class TestPointXYZImpl {

    @Before
    public void setUp() {
        System.loadLibrary("pcl-wrapper");
    }

    @Test
    public void testCreate() {
        PointXYZ point = new PointXYZImpl();
    }

    @Test
    public void testX() {
        float xValue = 20f;
        PointXYZ point = new PointXYZImpl();
        point.setX(xValue);
        assertEquals(xValue, point.getX(), 0.0001);
    }

    @Test
    public void testY() {
        float yValue = 30f;
        PointXYZ point = new PointXYZImpl();;
        point.setY(yValue);
        assertEquals(yValue, point.getY(), 0.0001);
    }

    @Test
    public void testZ() {
        float zValue = 40f;
        PointXYZ point = new PointXYZImpl();
        point.setZ(zValue);
        assertEquals(zValue, point.getZ(), 0.0001);
    }
}
