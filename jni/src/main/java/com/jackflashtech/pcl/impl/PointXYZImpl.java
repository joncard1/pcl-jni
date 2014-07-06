package com.jackflashtech.pcl.impl;

import com.jackflashtech.pcl.*;

public class PointXYZImpl implements PointXYZ {

     private int handler = 0;

     public PointXYZImpl() {
          this(0.0f, 0.0f, 0.0f);
     }

     public PointXYZImpl(float x, float y, float z) {
          createPoint(x, y, z);
     }

     public float getX() {
          return 0;
     }

     public float getY() {
          return 0;
     }

     public float getZ() {
          return 0;
     }

     private synchronized native int createPoint(float x, float y, float z) throws UnsatisfiedLinkError;

     //private synchronized static native int createPoint(float x, float y, float z) throws UnsatisfiedLinkError;
}
