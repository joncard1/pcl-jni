package com.jackflashtech.pcl.impl;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import com.jackflashtech.pcl.Normal;

public class TestNormalImpl {

    /**
     * @Before
     */
    public void setUp() {
        System.loadLibrary("pcl-wrapper");
    }

    /**
     * @Test
     */
    public void testCreate() {
	System.out.println(System.getProperty("java.library.path"));
        System.loadLibrary("pcl-wrapper");

        Normal normal = new NormalImpl();
    }
}
