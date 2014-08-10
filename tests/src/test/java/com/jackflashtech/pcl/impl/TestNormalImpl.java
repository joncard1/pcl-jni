package com.jackflashtech.pcl.impl;

import org.junit.Test;
import org.junit.Before;
import static org.junit.Assert.*;

import com.jackflashtech.pcl.Normal;

public class TestNormalImpl {

    @Before
    public void setUp() {
        System.loadLibrary("pcl-wrapper");
    }

    @Test
    public void testCreate() {
        Normal normal = new NormalImpl();
    }

    @Test
    public void testX() {
        float xValue = 20f;
        Normal normal = new NormalImpl();
        normal.setX(xValue);
        assertEquals(xValue, normal.getX(), 0.0001);
    }

    @Test
    public void testY() {
        float yValue = 30f;
        Normal normal = new NormalImpl();;
        normal.setY(yValue);
        assertEquals(yValue, normal.getY(), 0.0001);
    }

    @Test
    public void testZ() {
        float zValue = 40f;
        Normal normal = new NormalImpl();
        normal.setZ(zValue);
        assertEquals(zValue, normal.getZ(), 0.0001);
    }
}
